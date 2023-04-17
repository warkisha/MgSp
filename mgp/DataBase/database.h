#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QtSql>
#include <QFile>
#include "Crypty/qblowfish.h"
#include "Crypty/cryData/cryData.h"
#include "logging/log.h"

class DataBase{
public:
    void DataAction(QString InfoSqlData){
        QSqlQuery query;
        // QString InsertUsersInfo = "INSERT INTO 'users' VALUES ('"+QString(name) +"','" +QString (pswd)+"','"+QString (key) + "','" + QString(where) + "'  )";
        //qDebug() << InsertUsersInfo;
        int k = query.exec(QString(InfoSqlData));
        logging InLog;
        QString result;
        if (k == 1){
            result = "работа с базой....... \r\n";
            qDebug() << result;
            qDebug() << InfoSqlData;
            InLog.log(result);
        }
        else {

            result ="!!!работа с базой закончилась с ошибкой!!!\r\n";
            qDebug() << result << query.lastError();
            InLog.log(result);
        }
    }


    void connectDB (QString BaseName){
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(QString(BaseName));
        QString result;
        logging InLog;
        if(db.open()) {
            qDebug() << BaseName <<" - подлючена база данных";
            result = BaseName + " - open"+ "\r\n";
            InLog.log(result);
        }
        else{
            qDebug() << BaseName  << " -  ошибка соединения с базой" << db.lastError();
            result = BaseName + " - NO open"+ "\r\n";
            InLog.log(result);
        }
    }

    void closeDB (QString BaseName){
        QSqlDatabase db;
        db.setDatabaseName(QString(BaseName));
        db.close();
        QSqlDatabase::removeDatabase(QString(BaseName));
        QString result;
        logging InLog;
        if(db.isOpen()){
            result = BaseName + " - ошибка отключения от базы данных"+ "\r\n";
            InLog.log(result);
            qDebug() << " ошибка отключения от базы данных";
        }
        else{
            result = BaseName + " - база данных отключена успешно"+ "\r\n";
            InLog.log(result);
            qDebug() << "база данных отключена успешно";
        }

    }

    QString GetDataFromDB ( QString queryInfo,QString SqlColumGet ){
        QString DataFile;
        QSqlQuery query;
        //        QString queryInfo = "SELECT *  FROM " + TableName + " WHERE " + SqlColumn + " = '" + userInfo + "'";
        qDebug() << queryInfo;
        query.exec(QString(queryInfo));
        QSqlRecord rec = query.record();
        QString result;
        logging InLog;
        InLog.log(queryInfo);
        while (query.next())
        {
            result = SqlColumGet + " данные получаются...."+ "\r\n";
            InLog.log(result);
            DataFile = query.value(rec.indexOf(QString(SqlColumGet))).toString();
            qDebug() << DataFile;
            return DataFile;
        }
        qDebug() << "закончено получение данных";
    }

    QByteArray getpswTb(QString userName){
        QSqlQuery query;
        QString queryInfo = "SELECT *  FROM users WHERE name = '" + userName + "'";
        query.exec(QString(queryInfo));
        if(query.next())
        {
            QByteArray bitArr = query.record().value("psw").toByteArray();
            return bitArr;
        }

    }
    int countColum(QString tableName){
        QString queryInfo = "SELECT *  FROM " + tableName + "";
        QSqlQuery query;
        int size = 0;
        query.exec(QString(queryInfo));
        while(query.next()){
            size++;

        }
        return size;
    }
    void DecryTable(QString userPsw){
        QString loginFile;
        QString passwdFile;
        QString whereFile;

        QString queryInfo = "SELECT *  FROM MyBook";

        QSqlQuery query;
        query.exec(QString(queryInfo));
        QSqlRecord rec = query.record();
        QString result;
        logging InLog;
        result = " дешифрование...\r\n";
        InLog.log(result);
        while (query.next())
        {

            passwdFile = query.value(rec.indexOf("пароль")).toString();
            loginFile = query.value(rec.indexOf("имя")).toString();
            whereFile = query.value(rec.indexOf("место")).toString();
            passwdFile = Decry(passwdFile, userPsw);
            loginFile = Decry(loginFile, userPsw);
            QString dataInfo = "INSERT INTO 'MyDecBook' VALUES ('"+QString(whereFile) +"','" +QString (loginFile)+"','"+QString (passwdFile) +  "'  )";
            DataAction(dataInfo);
            result = " дешифрованные данные получены успешно\r\n";
            InLog.log(result);
        }
    }
    QString Decry(QString psw, QString key){
        QByteArray secretKey;
        secretKey.append(key.toUtf8());
        QBlowfish bf(QByteArray::fromHex(secretKey));
        bf.setPaddingEnabled(true);
        QByteArray pswr = QByteArray::fromHex(psw.toUtf8());
        bf.setPaddingEnabled(true);
        QByteArray decryptedBa = bf.decrypted(pswr);
        QString decryptedString = QString::fromUtf8(decryptedBa.constData(), decryptedBa.size());
        return decryptedString;
    }
    QString DecryD(QString psw, QString key){
        QByteArray secretKey;
        secretKey.append(key.toUtf8());
        qDebug() << psw << key;
        QBlowfish bf(QByteArray::fromHex(secretKey));
        bf.setPaddingEnabled(true);
        QByteArray pswr = QByteArray::fromHex(psw.toUtf8());
        qDebug() << pswr;
        bf.setPaddingEnabled(true);
        QByteArray decryptedBa = bf.decrypted(pswr);
        qDebug() << decryptedBa;
        QString decryptedString = QString::fromUtf8(decryptedBa.constData(), decryptedBa.size());
        return decryptedString;
    }
    void updateMainPsw(QString oldPsw, QString newPsw){
        QString loginFile;
        QString passwdFile;
        QString whereFile;

        QString queryInfo = "SELECT *  FROM MyBook";

        QSqlQuery query;
        query.exec(QString(queryInfo));
        QSqlRecord rec = query.record();
        QString result;
        logging InLog;
        result = " дешифрование...\r\n";
        InLog.log(result);

        cryData cry;
        if(query.exec("DELETE FROM MyBook")){
            qDebug() << "all delete";
            result = "данные успешно удаленыдля изменения \r\n";
            InLog.log(result);
            while (query.next())
            {

                passwdFile = query.value(rec.indexOf("пароль")).toString();
                loginFile = query.value(rec.indexOf("имя")).toString();
                whereFile = query.value(rec.indexOf("место")).toString();
                passwdFile = Decry(passwdFile, oldPsw);
                passwdFile = cry.CryData(newPsw, passwdFile);
                loginFile = Decry(loginFile, oldPsw);
                loginFile = cry.CryData(newPsw, loginFile);
                QString dataInfo = "INSERT INTO 'MyBook' VALUES ('"+QString(whereFile) +"','" +QString (loginFile)+"','"+QString (passwdFile) +  "'  )";
                DataAction(dataInfo);
                result = " замена данных произошла успешно \r\n";
                InLog.log(result);
            }
        }
        else {
            qDebug() <<"error delete: " << query.lastError();
            result = "ошибка при изменении данных\r\n";
            InLog.log(result);
        }


    }

};

#endif // DATABASE_H

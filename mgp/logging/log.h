#ifndef LOG_H
#define LOG_H

#include <QFile>
#include <QDir>
#include <QApplication>
#include <QString>
#include <QCryptographicHash>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include "Crypty/cryData/cryData.h"

class logging{
public:
    void writtingToFile(QString result){
        QFile file("the event log.txt");
        if ((file.open(QIODevice::Append))){
            QTextStream stream(&file);
            stream << result;
            file.flush();
            file.close();
            if (stream.status() != QTextStream::Ok){
                qDebug() << "Ошибка записи файла";
            }
        }
    }

    QString readLogEvent(){
        QFile file("the event log.txt");
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            QString str = stream.readAll();

            return str;
            file.close();
            if (stream.status() != QTextStream::Ok){
                qDebug() << "Ошибка чтения файла";
            }
        }
    }

    void UpDateSumUserDB(QString userName){
        cryData cry;
        userName = cry.CryData(userName, userName);
        QString where = QApplication::applicationDirPath();
        QString rez = getCS(userName);
        QString fileNameCheckSum = where +  "/users/" + userName + "/check.txt";
        QFile fileKC(fileNameCheckSum);
        logging log;
        QString result;
        if ((fileKC.open(QIODevice::WriteOnly))){
            QTextStream stream(&fileKC);
            stream << rez;
            qDebug() << rez;
            fileKC.flush();
            fileKC.close();
            qDebug() << rez;
            qDebug() << "контрольная сумма обновлена";
            result = "контрольная сумма обновлена\r\n";
            log.log(result);

            updateDateCS(userName);
            if (stream.status() != QTextStream::Ok){
                qDebug() << "Ошибка записи КС";
                result = "Ошибка записи КС\r\n";
                log.log(result);
            }
        }
    }
    void log(QString result){
        QFile file("log.txt");
        if ((file.open(QIODevice::Append))){
            QTextStream stream(&file);
            stream << result;
            file.flush();
            file.close();
            if (stream.status() != QTextStream::Ok){
                qDebug() << "Error with append Log";
            }
        }
    }

    QString CheckCS(QString userName){
        cryData cry;
        userName = cry.CryData(userName, userName);
        QString CS = getCS(userName);
        logging log;
        QString result;
        QString where = QApplication::applicationDirPath();
        QString fileNameCheckSum = where +  "/users/" + userName + "/check.txt";
        QFile file(fileNameCheckSum);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            QString str = stream.readAll();
            qDebug() << "контрольная сумма прочитана";
            result = "контрольная прочитана\r\n";
            log.log(result);
            file.close();
            if(str == CS){
                qDebug() << "контрольная сумма совпадает";
                result = "контрольная сумма совпадает, целостность не нарушена\r\n";
                log.log(result);
                log.writtingToFile(result);
                result = "ok";
                if(result == checkDate(userName)){
                    return result;
                    result = "дата изменения контрольной суммы совпадает";
                    log.log(result);
                }
                else{
                    result = "!!!Внимание дата изменения контрольной суммы совпадает";
                    log.log(result);
                    result = "error";
                    return result;
                }

            }else{
                qDebug() << "!!!ВНИМАНИЕ контрольная сумма НЕ совпадает";
                result = "!!!ВНИМАНИЕ контрольная сумма НЕ совпадает, целостность базы "+ userName +" нарушена!!! \r\n";
                log.log(result);
                log.writtingToFile(result);
                qDebug() << CS << str;
                result = "error";
                return result;
            }

            if (stream.status() != QTextStream::Ok){
                qDebug() << "Ошибка чтения КС";
                result = "Ошибка чтения КС\r\n";
                log.log(result);
                result = "error";
                return result;
            }
        }
    }

    QString tockenHas(QString whereKey){
        QFile file(whereKey);
        if (file.open(QIODevice::ReadOnly)){
            QString result = "open";
            return result;


        }
        else{
            QString result = "close";
            return result;
        }
    }


private:
    void updateDateCS(QString userName){
        QString where = QApplication::applicationDirPath();
        QString command =  "for %I in ( "+ where +  "/users/" + userName  +"/check.txt ) do echo %~tI > " + where +  "/users/" + userName + "/timeGo.txt" ;
        qDebug() << command;
        system(command.toStdString().c_str());
    }
    QString checkDate(QString userName){
        QString where = QApplication::applicationDirPath();
        QString command =  "for %I in ( "+ where +  "/users/" + userName  +"/check.txt ) do echo %~tI > " + where +  "/users/" + userName + "/timeOut.txt" ;
        qDebug() << command;
        system(command.toStdString().c_str());
        QString whereFile = where + "/users/" + userName + "/timeOut.txt";
        QFile file1(whereFile);
        QString str1, str2;
        QString result;
        if(file1.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file1);
            str1 = stream.readAll();
            file1.close();
        }
        else{
            qDebug() << "str1 no open";
        }
        whereFile = where + "/users/" + userName + "/timeGo.txt";
        QFile file2(whereFile);
        if(file2.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file2);
            str2 = stream.readAll();
            file2.close();
        }
        else{
            qDebug() << "str2 no open";
        }
        if(str1==str2){
            result = "ok";
            return result;
        }
        else{
            result = "error";
            return result;
        }

    }

    QString getCS(QString userName){
        QString where = QApplication::applicationDirPath();
        QString command =   where +  "/users/" + userName + "/MyDB.db";
        QString result;
        logging log;
        QString rez;
        QCryptographicHash cryp(QCryptographicHash::Sha256);
        QFile file(command);
        if (file.open(QIODevice::ReadOnly) )
        {
            QByteArray all;
            while (!file.atEnd()) {
                QByteArray line = file.read(1024);
                cryp.addData(line);
                all+=line;
            }
            qDebug() << "контрольная сумма получена";
            result = "контрольная сумма получена\r\n";
            rez = cryp.result().toHex().data();
            log.log(result);
            return rez;
        }
        else {
            qDebug() << "контрольная сумма НЕ получена";
            result = "контрольная сумма НЕ получена\r\n";
            log.log(result);
        }
    }

};

#endif // LOG_H

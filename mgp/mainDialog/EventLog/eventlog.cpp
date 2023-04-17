#include "eventlog.h"
#include "ui_eventlog.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>

EventLog::EventLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventLog)
{
    ui->setupUi(this);
    logging log;
    QString str = log.readLogEvent();
    ui->textBrowser->setText(str);
    ui->groupBox->close();
    ui->psw_groupBox->close();

}

EventLog::~EventLog()
{
    delete ui;
}



void EventLog::on_pushButton_clicked()
{
    close();
}


void EventLog::on_setting_pushButton_clicked()
{
    ui->groupBox->show();
    ui->textBrowser->close();
}


void EventLog::on_closeSetting_Button_clicked()
{
    ui->groupBox->close();
    ui->textBrowser->show();
}


void EventLog::on_deletMainAc_Button_clicked()
{
    QString where = QApplication::applicationDirPath();
    QString name = ui->name_label->text();
    cryData cry;
    name = cry.CryData(name, name);
    where =  where + "/users/" + QString(name);
    QDir dir(where);
    dir.removeRecursively();
    DataBase data;
    data.connectDB(QString("all users.db"));
    QString info = "DELETE FROM 'users' WHERE name = '" + name + "' ";
    data.DataAction(info);
    data.closeDB(QString("all users.db"));
}

void EventLog::slotUserInfo(QString name)
{
    ui->name_label->setText(name);
}


void EventLog::on_changeMain_Button_clicked()
{
    ui->psw_groupBox->show();
    ui->groupBox->close();
}


void EventLog::on_change_MainAc_Button_2_clicked()
{
    QString name = ui->name_label->text();
    cryData cry;
    DataBase data;
    name = cry.CryData(name, name);
    logging info;
    data.connectDB(QString("all users.db"));

    QString sqlInfo = "SELECT * FROM users WHERE name = '" + name + "'";
    QString column = "whereToken"; //название колонки из которой данные читаются
    QString where = data.GetDataFromDB(sqlInfo, column ); //временно хранится расположение токена
    column = "token";
    column = data.GetDataFromDB(sqlInfo, column );
    QString secretKey;
    QString result;

    if(column == "yes"){
        where = where + "MgSp/k.txt";
        QFile file(where);
        qDebug() << where;
        if (file.open(QIODevice::ReadOnly) )
        {
            while (!file.atEnd()) {
                secretKey = file.read(1024);
                result = "токен найден";
                info.log(result);
            }
            file.close();
        }
        else {
            result = "токен не найден";
            ui->error_label->setText("вставьте токен для изменения пароля");
            info.log(result);
        }
    }
    else {
        where = where + "/users/" + name + "/k.txt";
        QFile file(where);
        qDebug() << where;
        qDebug() << file.size();
        if (file.open(QIODevice::ReadOnly) )
        {
            while (!file.atEnd()) {
                secretKey = file.read(1024);
                result = "токен найден\r\n";
                info.log(result);
            }
            file.close();
        }
        else {
            result = "токен не найден\r\n";
            ui->error_label->setText("вставьте токен для изменения пароля");
            info.log(result);
        }

    }
    column = "psw";
    QString psw =  ui->psw_lineEdit->text();
    column = data.GetDataFromDB(sqlInfo, column );//использую для сохранения старого пароля
    secretKey = cry.DecryData(secretKey, psw);
    column = cry.DecryData(column, secretKey);
    if(column != psw){
        ui->error_label->setText("неверно ввели свой настоящий пароль, попробуйте еще раз или вставьте другой токен");
    }
    else{
        psw = ui->pswNew_lineEdit->text();
        psw = cry.CryData(secretKey, psw);
        sqlInfo = "UPDATE 'users' SET 'psw' = '" +  psw + "' WHERE name = '" + name +"'  ";
        data.DataAction(sqlInfo);
        secretKey = cry.CryData(psw, secretKey);
        QFile fileK(where);
        if ((fileK.open(QIODevice::WriteOnly))){
            QTextStream stream(&fileK);
            stream << secretKey;
            fileK.flush();
            fileK.close();
        }
        ui->psw_groupBox->close();
        ui->groupBox->show();
        Dialog *dialog;
        dialog = new Dialog;
        connect (this, &EventLog::updatePsw, dialog, &Dialog::slotUpdatePsw);
        emit updatePsw(psw);

    }
}


void EventLog::on_closeChangePsw_Button_clicked()
{
    ui->psw_groupBox->close();
    ui->groupBox->show();
}


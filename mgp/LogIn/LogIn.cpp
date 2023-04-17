#include "LogIn/LogIn.h"
#include "ui_LogIn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap px1 ("./img/login.jpg");
    QString where = QApplication::applicationDirPath();
    ui->background_label->setPixmap (px1);
    QString time = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    QString logusers= "Открытие приложения в " + time + "\r\n";
    logging log;
    log.writtingToFile(logusers);
    log.log(logusers);
    log.log(where);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_create_Button_clicked()
{

    QString tableName = "all users.db";
    DataBase Table;
    Table.connectDB(tableName);
    regist = new Registration;
    regist->show();
    close();
}


void MainWindow::on_signIn_Button_clicked()
{
    QString nameUser = ui->name_lineEdit->text();
    QString pswUser = ui->pswd_lineEdit->text();
    QString ColumName = "name";
    QString Colum = "psw";
    QString DBname = "all users.db";
    QString tableName = "users";
    logging info;
    cryData cryk;
    nameUser = cryk.CryData(nameUser, nameUser);
    QString queryInfo = "SELECT *  FROM " + tableName + " WHERE  name = '" + nameUser + "'";
    QString name =  ui->name_lineEdit->text();;
    DataBase Data;
    Data.connectDB(DBname);
    QString result;
    result = "Попытка входа под именем: " + name + "\r\n";
    info.log(result);
    info.writtingToFile(result);
    QString time = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    QString nameFile = Data.GetDataFromDB(queryInfo, ColumName );
    qDebug() <<"data: " << nameFile;
    if((nameFile == nameUser) && (!(nameFile == ""))){
        //тут вставить расшифровывание с помощью ключа из файла на токене

        QString pswFile = Data.GetDataFromDB( queryInfo, Colum );
        Colum = "whereToken";
        QString where = Data.GetDataFromDB(queryInfo,Colum);
        Colum = "token";
        QString hasT = Data.GetDataFromDB(queryInfo,Colum);
        QByteArray secretKey;
        QString whereKey ;
        if(hasT == "yes"){
            whereKey = where + "MgSp/k.txt";
            QFile file(whereKey);
            qDebug() << whereKey;
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
                info.log(result);
            }
        }
        else {
            whereKey = where + "/users/" + nameUser + "/k.txt";
            QFile file(whereKey);
            qDebug() << whereKey;
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
                info.log(result);
            }
        }

        qDebug() << secretKey;
        QString key = QString(secretKey);
        key = cryk.DecryData(key, pswUser);
        qDebug() << key;
        QByteArray secret;
        secret.append(key.toUtf8());

        QBlowfish bf(QByteArray::fromHex(secret));
        bf.setPaddingEnabled(true);
        QByteArray pswr = QByteArray::fromHex(pswFile.toUtf8());
        bf.setPaddingEnabled(true);
        QByteArray decryptedBa = bf.decrypted(pswr);
        QString decryptedString = QString::fromUtf8(decryptedBa.constData(), decryptedBa.size());

        if((pswUser == decryptedString) && (!(pswFile == ""))){
            Dialog *dialog;
            dialog = new Dialog;
            dialog->show();
            result = "Удачная попытка входа под именем:  " + name + "  время и дата попытки:   " + time + "\r\n";
            connect (this, &MainWindow::signalUserName, dialog, &Dialog::slotUserName);
            emit signalUserName(name, pswUser, whereKey);
            QTimer::singleShot(300000, dialog, SLOT(close()));
            close();
        }
        else{
            QPixmap px2 ("./img/redLogin.jpg");
            ui->background_label->setPixmap (px2);
            QString style = "border:2px solid  #ff8c66; border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
            ui->lookpsw_Button->setStyleSheet(style);
            ui->error_label->setText("Пользователя с таким именем или паролем не сущесвует, попробуйте еще раз или зарегистрируйтесь  ");
            result = "НЕУДАЧНАЯ попытка входа под именем: " + name + "  время и дата попытки:   " + time + "\r\n";
        }
    }
    else{
        QPixmap px2 ("./img/redLogin.jpg");
        QString style = "border:2px solid  #ff8c66; border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
        ui->lookpsw_Button->setStyleSheet(style);
        ui->background_label->setPixmap (px2);
        ui->error_label->setText("Пользователя с таким именем или паролем не сущесвует, попробуйте еще раз ");
        result = "НЕУДАЧНАЯ попытка входа под именем:   " + name + "  время и дата попытки   " + time + "\r\n";
    }
    Data.closeDB(DBname);
    info.writtingToFile(result);
    info.log(result);

}



void MainWindow::on_lookpsw_Button_clicked()
{
    ui->pswd_lineEdit->setEchoMode(QLineEdit::Normal);
    QString style = "border:2px solid  #ff8c66; border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
    ui->lookpsw_Button->setStyleSheet(style);
    QTimer::singleShot(800, this, SLOT(hide()));
}

void MainWindow::hide()
{
    ui->pswd_lineEdit->setEchoMode(QLineEdit::Password);
    QString style = "border:2px solid rgb(24, 205, 255); border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
    ui->lookpsw_Button->setStyleSheet(style);
}


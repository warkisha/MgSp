#include "getpassword.h"
#include "ui_getpassword.h"

getPassword::getPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPassword)
{
    ui->setupUi(this);
    QPixmap px1 ("./img/img.jpg");
    ui->background_label->setPixmap (px1);
}

getPassword::~getPassword()
{
    delete ui;
}

void getPassword::slotName(QString name){
    qDebug() << name;
    ui->userName_label->setText(name);
}

void getPassword::slotNameK(QString name)
{
    ui->name_label->setText(name);
}

void getPassword::hide()
{
    ui->psw_lineEdit->setEchoMode(QLineEdit::Password);
    ui->pswAgain_lineEdit->setEchoMode(QLineEdit::Password);
    QString style = "border:2px solid rgb(24, 205, 255); border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
    ui->lookpsw_Button->setStyleSheet(style);
}

void getPassword::error()
{
    QPixmap px2 ("./img/img.jpg");
    ui->errorPsw_label->setText("");
    ui->background_label->setPixmap (px2);
    QString style = "border:2px solid  rgb(24, 205, 255); border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
    ui->lookpsw_Button->setStyleSheet(style);
}

void getPassword::on_next_Button_clicked()
{
    QString UserPas1, UserPas2;
    UserPas1 = ui->psw_lineEdit->text();
    UserPas2 = ui->pswAgain_lineEdit->text();
    QPixmap px2 ("./img/img_red.jpg");
    getKey *getky;
    getky = new getKey;

    if(UserPas1 == UserPas2){
        qDebug() << "good pas1 and pas2";
        if(UserPas1.size() < 8){
            ui->errorPsw_label->setText("пароль должен содержать больше 8 символов");
            ui->background_label->setPixmap (px2);
            QString style = "border:2px solid  #ff8c66; border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
            ui->lookpsw_Button->setStyleSheet(style);
            QTimer::singleShot(2000, this, SLOT(error()));
        }
        else{
            qDebug() << "good size";
            QString result = controlUserpsw(UserPas1);
            if(result == "ok"){
                QString result = "Пароль добавлен успешно ";
                logging log;
                log.log(result);
                close();
                connect (this, &getPassword::signalUserData , getky, &getKey::slotUserData);
                QString nameUser = ui->userName_label->text();
                emit signalUserData(nameUser, UserPas1);
                getky->show();
            }
            else{
                ui->errorPsw_label->setText("в пароле используются запрещенные символы");
                ui->background_label->setPixmap (px2);
                QString style = "border:2px solid  #ff8c66; border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
                ui->lookpsw_Button->setStyleSheet(style);
                QTimer::singleShot(2000, this, SLOT(error()));
            }
        }
    }

    else{
        ui->errorPsw_label->setText("Пароли не совпадают");
        QPixmap px2 ("./img/img_red.jpg");
        ui->background_label->setPixmap (px2);
        QString style = "border:2px solid  #ff8c66; border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
        ui->lookpsw_Button->setStyleSheet(style);
        QTimer::singleShot(2000, this, SLOT(error()));
    }

}



void getPassword::on_back_Button_clicked()
{
    Registration *getName;
    getName = new Registration;
    getName->show();
    close();
}


void getPassword::on_lookpsw_Button_clicked()
{
    ui->psw_lineEdit->setEchoMode(QLineEdit::Normal);
    ui->pswAgain_lineEdit->setEchoMode(QLineEdit::Normal);
    QString style = "border:2px solid #ff8c66; border-radius: 30px;background-color: transfert;font: 600 10pt 'Segoe UI Variable Display Semib'";
    ui->lookpsw_Button->setStyleSheet(style);
    QTimer::singleShot(800, this, SLOT(hide()));
}

QString getPassword::controlUserpsw(QString data){
    int sizeData = data.size();
    QString result;
    if(sizeData >= 8){
        for(int i = 0; i < sizeData; i++){
            if ((data[i] != "%") && (data[i] != "$") &&
                    (data[i] != ". ") && (data[i] != ",") &&
                    (data[i] != "\.") && (data[i] != "/") &&
                    (data[i] != "^")  && (data[i] != "#") &&
                    (data[i] != ":")  && (data[i] != ";") &&
                    (data[i] != "@")  && (data[i] != "*") &&
                    (data[i] != "'")  && (data[i] != '"') &&
                    (data[i] != "~")  && (data[i] != "-") &&
                    (data[i] != ">")  && (data[i] != "<") &&
                    (data[i] != "+")  && (data[i] != "=") &&
                    (data[i] != "?")  && (data[i] != "!") &&
                    (data[i] != ")")  && (data[i] != "(") &&
                    (data[i] != "]")  && (data[i] != "[") &&
                    (data[i] != "}")  && (data[i] != "{")) {
                result = "ok";
                return result;
            }
            else {
                result = "error";
                return result;
            }
        }
    }
    else {
        result = "error";
        return result;
    }
}



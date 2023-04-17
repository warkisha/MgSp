#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPixmap px1 ("./img/imgmedium.jpg");
    QPixmap px2 ("./img/img_red_mini.jpg");
    ui->background_label->setPixmap (px1);
    ui->background_label_2->setPixmap(px1);
    ui->label_2->setPixmap(px2);
    ui->label_3->setPixmap(px2);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_openAll_Button_clicked()
{
    LookBase * Lookdb;
    Lookdb = new LookBase;
    cryData cry;
    QString nameUser = ui->name_label->text();
    nameUser = cry.CryData(nameUser, nameUser);
    QString psw = ui->label->text();
    QString where = QApplication::applicationDirPath();
    QString userWhereDB =  where + "/users/" + QString(nameUser) + "/MyDB.db" ;
    qDebug() << userWhereDB;
    DataBase person;
    person.connectDB(userWhereDB);
    person.DecryTable(psw);
    for(int i = 0; i < 1; i++){
        connect (this, &Dialog::signalUserInfo, Lookdb, &LookBase::slotUserInfo);
        emit signalUserInfo(nameUser, psw);
    }

    Lookdb->show();
    QTimer::singleShot(120000, Lookdb, SLOT(close()));
}

void Dialog::slotUserName(QString nameUser, QString pswUs, QString whereKey)
{
    ui->name_label->setText(nameUser);
    ui->label->setText(pswUs);
    logging log;
    QString result = log.CheckCS(nameUser);
    if(result != "ok"){
        QMessageBox::warning(this, "Внимание","Нарушена целостность вашего аккаунта\nкто-то изменял данные вне приложения \nобратитесь к администратору");
    }
    for(int i = 0; i<1;i++){
        if(whereKey[i] != "C"){
            QString result;
            while(result != "close"){
                result = log.tockenHas(whereKey);
                if(result == "open"){
                    QMessageBox::warning(this, "Внимание","Извлеките токен из устройства\r");
                }
            }
        }
    }
}

void Dialog::slotInsertReady(QString nameUser)
{
    qDebug() << nameUser;
    logging CS;
    CS.UpDateSumUserDB(nameUser);
}

void Dialog::slotUpdatePsw(QString pswUs)
{
    ui->label->setText(pswUs);
}


void Dialog::on_addNew_Button_clicked()
{
    AddNew * addnew;
    addnew = new AddNew;
    QString nameUser = ui->name_label->text();
    QString psw = ui->label->text();
    qDebug() << nameUser;
    for(int i = 0; i < 1; i++){
        connect (this, &Dialog::signalUserNamee, addnew, &AddNew::slotUserInfo);
        emit signalUserNamee(nameUser, psw);
    }
    addnew->show();
}


void Dialog::on_pushButton_4_clicked()
{
    QString time = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    QString result = "Выход из аккаунта в " + time + "\r\n";
    logging log;
    log.writtingToFile(result);
    log.log(result);
    close();

}


void Dialog::on_log_Button_clicked()
{
    EventLog * eventLog;
    eventLog = new EventLog;
    eventLog->show();
    QString name = ui->name_label->text();
    connect (this, &Dialog::signalUserName, eventLog, &EventLog::slotUserInfo);
    emit signalUserName(name);

}

void Dialog::closeEvent(QCloseEvent *bar)
{
    logging log;
    QString name = ui->name_label->text();
    log.UpDateSumUserDB(name);
    QString result = "завершение работы пользователем " + name + "\r\n";
    log.log(result);
    log.writtingToFile(result);
    bar->accept();
    MainWindow *login;
    login = new MainWindow;
    login->show();
}



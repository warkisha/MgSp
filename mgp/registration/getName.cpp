#include "getName.h"
#include "ui_getName.h"

Registration::Registration(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    QPixmap px1 ("./img/img.jpg");
    ui->background_label->setPixmap (px1);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_next_Button_clicked()
{
    QString nameUser = ui->name_lineEdit->text();
    QString result = "Началась регистрация под именем: " + nameUser;
    logging log;
    log.log(result);
    if(nameUser == ""){
        QPixmap px2 ("./img/img_red.jpg");
        ui->background_label->setPixmap (px2);
        ui->erroe_label->setText("Вы ничего не ввели, пожалуйста, попробуйте еще раз");
    }
    else{
        if(nameUser.size() <= 3){
            qDebug();
            QPixmap px2 ("./img/img_red.jpg");
            ui->background_label->setPixmap (px2);
            ui->erroe_label->setText("Имя должно содержать более трёх символов");
        }
        else {
            getPassword *getPsw;
            getPsw = new getPassword;
            connect (this, &Registration::signalName , getPsw, &getPassword::slotName);
            emit signalName(nameUser);
            close();
            getPsw->show();
        }

    }
}
void Registration::on_back_Button_clicked(){
    MainWindow *login;
    login = new MainWindow;
    login->show();
    close();
}


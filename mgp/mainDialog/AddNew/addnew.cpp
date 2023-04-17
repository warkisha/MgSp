#include "addnew.h"
#include "ui_addnew.h"

AddNew::AddNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNew)
{
    ui->setupUi(this);
    QPixmap px1 ("./img/img.jpg");
    ui->back_label->setPixmap (px1);
    ui->genPsw_groupBox->close();
    ui->horizontalSlider->setMaximum(32);
    ui->horizontalSlider->setMinimum(8);
    ui->horizontalSlider->setPageStep(1);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(update()));

}

AddNew::~AddNew()
{
    delete ui;
}


void AddNew::on_save_Button_clicked()
{
    QString name, psw, place;
    name = ui->name_lineEdit->text();
    psw = ui->psw_lineEdit->text();
    place = ui->place_lineEdit->text();
    QString uspsw = ui->psw_label->text();
    cryData cry;
    name = cry.CryData(uspsw, name);
    psw = cry.CryData(uspsw, psw);
//    QByteArray secretKey;
//    secretKey.append(uspsw.toUtf8());
//    QBlowfish bf(QByteArray::fromHex(secretKey));
//    bf.setPaddingEnabled(true);
//    QByteArray cipherText = bf.encrypted(psw.toUtf8());
//    uspsw = cipherText.toHex();
    DataBase newData;

    QString insertData =  "INSERT INTO 'MyBook' VALUES ('" + QString(place) + "' ,'" + QString (name) + "' ,'" + QString (psw) + "' )";
    qDebug() << insertData;
    newData.DataAction(insertData);
    Dialog * dialog;
    dialog = new Dialog;
    QString nameUser = ui->name_label->text();
    DataBase person;
    QString where = ui->where_label->text();
    person.closeDB(where);

    connect (this, &AddNew::signalInsertReady, dialog, &Dialog::slotInsertReady);
    emit signalInsertReady(nameUser);

    close();
}

void AddNew::slotUserInfo(QString userName, QString psw)
{
    DataBase person;
    QString where = QApplication::applicationDirPath();
    cryData cry;
    userName = cry.CryData(userName, userName);
    QString userWhereDB =  where + "/users/" + QString(userName) + "/MyDB.db" ;
    qDebug() << userWhereDB;
    person.connectDB(userWhereDB);
    ui->name_label->setText(userName);
    ui->where_label->setText(userWhereDB);
    ui->psw_label->setText(psw);
}

void AddNew::update()
{
    int h = ui->horizontalSlider->value();
    QString s = QString::number(h);
    ui->numLig_label->setText(s);
}




void AddNew::on_exit_Button_clicked()
{
    close();
}


void AddNew::on_generate_Button_clicked()
{
     ui->genPsw_groupBox->show();
}


void AddNew::on_pushButton_clicked()
{
    ui->genPsw_groupBox->close();
}


void AddNew::on_startGen_pushButton_clicked()
{
    generate genpsw;
    QString  possibleCharacters;
    if ((!(ui->checkBox_sym->isChecked())) &&
            (!(ui->checkBox_num->isChecked())) &&
            (!(ui->caseLow_checkBox_2->isChecked())) &&
            (!(ui->capitalLetters_checkBox->isChecked())))
    {
        qDebug() << "zero gen";
    }
    else {
    if(ui->checkBox_sym->isChecked()){
        possibleCharacters = possibleCharacters + "&%$#!.,?*";
    }
    if(ui->checkBox_num->isChecked()){
        possibleCharacters = possibleCharacters + "0123456789";
    }
    if(ui->caseLow_checkBox_2->isChecked()){
        possibleCharacters = possibleCharacters + "abcdefghijklmnopqrstuvwxyz";
    }
    if(ui->capitalLetters_checkBox->isChecked()){
        possibleCharacters = possibleCharacters + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    qDebug() << possibleCharacters;
    int lengthNum = ui->numLig_label->text().toInt();
    QString psw = genpsw.GetRandomStringAll(possibleCharacters, lengthNum);
    ui->psw_lineEdit->setText(psw);
    }


}



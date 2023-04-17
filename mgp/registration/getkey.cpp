#include "getkey.h"
#include "ui_getkey.h"



getKey::getKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getKey)
{
    ui->setupUi(this);
    QPixmap px1 ("./img/img.jpg");
    ui->background_label->setPixmap (px1);
}

getKey::~getKey()
{
    delete ui;
}

void getKey::on_next_Button_clicked()
{
    QString UserKey;
    cryData blowCry;
    UserKey = ui->key_lineEdit->text();
    QPixmap px2 ("./img/img_red.jpg");
    QString WhereKey = ui->wherekey_label->text();
    DataBase userData;
    if((WhereKey == "") || (ui->checkBox->isChecked())){
        ui->errorkey_label->setText("вы не выбрали токен");
        ui->background_label->setPixmap (px2);
    }

    if(UserKey.size() < 12){
        ui->errorkey_label->setText("ключ должен содержать больше 12  символов");
        ui->background_label->setPixmap (px2);
    }
    else{
        qDebug() << "good size";
        QString result = controlUserpsw(UserKey);
        if(result == "error"){
            ui->errorkey_label->setText("использованы запрещенные символы");
            ui->background_label->setPixmap (px2);
        }
        else{
            QString name = ui->name_label->text();
            QString psw = ui->psw_label->text();
            name = blowCry.CryData(name, name);
            //сюда добавить шифрование, шифровать  QString psw c помощью QString UserKey;
            QString where = QApplication::applicationDirPath() +"/users/" +QString(name);
            QDir dir;
            dir.mkdir(where);
            QByteArray secretKey;
            secretKey.append(UserKey);

            QBlowfish bf(QByteArray::fromHex(secretKey));
            bf.setPaddingEnabled(true);// Включить заполнение, чтобы можно было зашифровать байты произвольной длины

            QByteArray cipherText = bf.encrypted(psw.toUtf8());
            QString resPsw = cipherText.toHex();


           QString UserKey1 = blowCry.CryData( psw, UserKey );
 //           secretKey.append(UserKey1);
            qDebug() << UserKey;
            QString lol = blowCry.DecryData(UserKey1, psw);
            qDebug() << lol;
            if(lol != UserKey){
                qDebug() << "error cryption";
                QString result = "пожалуйста попробуйте другой ключ";
                ui->errorkey_label->setText(result);
            }
            else{
                QString tockenHas;
                QString wherekey_label = ui->wherekey_label->text();
                QString errorkey_label = ui->errorkey_label->text();

                if( (wherekey_label != "") && (errorkey_label != "Выбран запрещенный носитель для токена")){
                    tockenHas = "yes";
                    QString FileKey = wherekey_label + "/MgSp";
                    QDir dir;
                    dir.mkdir(FileKey);
                    QString fileKey = FileKey + "/k.txt";
                    QFile fileK(fileKey);
                    if ((fileK.open(QIODevice::WriteOnly))){
                        QTextStream stream(&fileK);
                        stream << UserKey1;
                        fileK.flush();
                        fileK.close();
                    }


                    QString InsertUsersInfo = "INSERT INTO 'users' VALUES ('"+QString(name) +"','"  +QString (resPsw) +"', '" +QString (tockenHas)+"', '" +QString(wherekey_label ) +"') ";
                    userData.DataAction(InsertUsersInfo);

                }
                if(errorkey_label != "Выбран запрещенный носитель для токена"){
                    tockenHas = "no";
                    QString where = QApplication::applicationDirPath();
                    QString fileKey = where +  "/users/" + name + "/k.txt";
                    QFile fileK(fileKey);
                    if ((fileK.open(QIODevice::WriteOnly))){
                        QTextStream stream(&fileK);
                        stream << UserKey1;
                        fileK.flush();
                        fileK.close();
                    }
                    else {
                        qDebug() << "File no open";
                    }
                    QString InsertUsersInfo = "INSERT INTO 'users' VALUES ('"+QString(name) +"','" +QString (resPsw)+"', '"+QString (tockenHas)+"', '" +QString(where) +"') ";
                    userData.DataAction(InsertUsersInfo);
                }
                else
                {
                    qDebug() << "not correct tocken";
                }

                QString BaseAllUsers = "./all users";
                QSqlDatabase::removeDatabase(QString(BaseAllUsers));


                QString userBase = QString(where) + "/MyDB.db";
                userData.connectDB(userBase);
                QString tableInfo = "CREATE TABLE MyDecBook ( место TEXT, имя TEXT, пароль TEXT )";
                userData.DataAction(tableInfo);
                tableInfo = "CREATE TABLE MyBook ( место TEXT, имя TEXT, пароль TEXT )";
                userData.DataAction(tableInfo);
                logging info;
                info.UpDateSumUserDB(name);
                close();
                QString result = "регистрация завершилась успешно " ;
                info.log(result);
                login = new MainWindow;
                login->show();
            }
        }
    }
}


void getKey::on_tockenchoose_Button_clicked()
{
    QString whereKey = QFileDialog::getExistingDirectory();
    ui->wherekey_label->setText(whereKey);
    QPixmap px2 ("./img/img_red.jpg");
    QPixmap px1 ("./img/img.jpg");
    ui->errorkey_label->setText("");
    ui->background_label->setPixmap (px1);
    int i;
    for( i = 0;i < 1; i++){
        if((whereKey[i] == "C") || (whereKey[i] == "A") ){
            ui->errorkey_label->setText("Выбран запрещенный носитель для токена");
            ui->background_label->setPixmap (px2);
            i = 5;
        }
    }
}


void getKey::on_checkBox_stateChanged()
{
    ui->tockenchoose_Button->setStyleSheet("color: rgb(255, 255, 255); background-color: rgb(255, 85, 0);");
    ui->keychoose_label->setStyleSheet("color: rgb(255, 255, 255);");
}

void getKey::slotUserData(QString nameUser, QString UserPas1)
{
    qDebug() <<  nameUser << UserPas1;
    ui->name_label->setText(QString(nameUser));
    ui->psw_label->setText(QString(UserPas1));

}


void getKey::on_back_Button_clicked()
{
    getPassword * getpsw;
    getpsw = new getPassword;
    QString name = ui->name_label->text();
    connect (this, &getKey::signalNameK , getpsw, &getPassword::slotNameK);
    emit signalNameK(name);
    getpsw->show();
    close();
}


void getKey::on_pushButton_clicked()
{
    generate Gen;
    QString key = Gen.GetRandomString();
    ui->key_lineEdit->setText(key);
}

QString getKey::controlUserpsw(QString input){

        if(isAlphaNumeric(input)) {
            return "ok";
        } else {
            return "error";
        }
    }


bool getKey::isAlphaNumeric(QString str) {
    bool result = true;
    for(int i = 0; i < str.length(); i++) {
        if(!isalnum(str[i].toLatin1())) {
            result = false;
            break;
        }
    }
    return result;
}

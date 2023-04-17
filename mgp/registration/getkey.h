#ifndef GETKEY_H
#define GETKEY_H

#include <QDialog>
#include <registration/getpassword.h>
#include <LogIn/LogIn.h>
#include <QFileDialog>
#include <DataBase/database.h>
#include "logging/log.h"
#include <Crypty/qblowfish.h>
#include "Crypty/crypty.h"
#include "Crypty/cryData/cryData.h"


namespace Ui {
class getKey;
}

class getKey : public QDialog
{
    Q_OBJECT

public:
    explicit getKey(QWidget *parent = nullptr);
    ~getKey();

private slots:
    void on_next_Button_clicked();

    void on_tockenchoose_Button_clicked();

    void on_checkBox_stateChanged();

    void on_back_Button_clicked();

    void on_pushButton_clicked();
    bool isAlphaNumeric(QString str) ;

private:
    Ui::getKey *ui;
    QString controlUserpsw(QString data);

public:
    QMainWindow *login;
    QDialog *dialogchoosefile;

public slots:
    void slotUserData(QString, QString);
signals:
    void signalNameK(QString);
};

#endif // GETKEY_H

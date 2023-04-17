#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "LogIn/LogIn.h"
#include "LookDB/lookbase.h"
#include "DataBase/database.h"
#include "AddNew/addnew.h"
#include "EventLog/eventlog.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_openAll_Button_clicked();

    void on_addNew_Button_clicked();

    void on_pushButton_4_clicked();

    void on_log_Button_clicked();

private:
    Ui::Dialog *ui;


public slots:
    void slotUserName (QString, QString, QString);
    void slotInsertReady(QString nameUser);
    void slotUpdatePsw(QString);


signals:
    void signalUserInfo (QString, QString);
    void signalUserNamee(QString,QString);
    void signalUserName(QString);


private:
    void closeEvent(QCloseEvent *bar);


};

#endif // DIALOG_H

#ifndef ADDNEW_H
#define ADDNEW_H

#include <QDialog>
#include "DataBase/database.h"
#include "mainDialog/dialog.h"
#include "Crypty/qblowfish.h"
#include <QThread>
#include "Crypty/cryData/cryData.h"

namespace Ui {
class AddNew;
}

class AddNew : public QDialog
{
    Q_OBJECT

public:
    explicit AddNew(QWidget *parent = nullptr);
    ~AddNew();

private slots:
    void on_save_Button_clicked();

    void on_exit_Button_clicked();

    void on_generate_Button_clicked();

    void on_pushButton_clicked();

    void on_startGen_pushButton_clicked();


private:
    Ui::AddNew *ui;

public slots:
    void slotUserInfo (QString, QString);
    void update();

signals:
    void signalInsertReady(QString);


};

#endif // ADDNEW_H

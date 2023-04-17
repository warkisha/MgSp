void on_back_Button_clicked();
#ifndef GETNAME_H
#define GETNAME_H

#include <QMainWindow>
#include <LogIn/LogIn.h>
#include <registration/getpassword.h>
#include <QDialog>
#include "logging/log.h"

namespace Ui {
class Registration;
}

class Registration : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_next_Button_clicked();
    void on_back_Button_clicked();


private:
    Ui::Registration *ui;

signals:
    void signalName(QString);

};

#endif // GETNAME_H

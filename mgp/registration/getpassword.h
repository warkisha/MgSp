#ifndef GETPASSWORD_H
#define GETPASSWORD_H

#include <QDialog>
#include <registration/getname.h>
#include <registration/getkey.h>
#include <registration/getpassword.h>

namespace Ui {
class getPassword;
}

class getPassword : public QDialog
{
    Q_OBJECT

public:
    explicit getPassword(QWidget *parent = nullptr);
    ~getPassword();

private slots:
    void on_next_Button_clicked();

    void on_back_Button_clicked();

    void on_lookpsw_Button_clicked();

private:
    Ui::getPassword *ui;
    QString controlUserpsw(QString data);

public slots:
    void slotName(QString);
    void slotNameK(QString);
    void hide();
    void error();

signals:
    void signalUserData(QString, QString);
};

#endif // GETPASSWORD_H

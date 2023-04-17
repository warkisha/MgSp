#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "registration/getName.h"
#include <QDebug>
#include "mainDialog/dialog.h"
#include "DataBase/database.h"
#include "logging/log.h"
#include <QDate>
#include <QDateTime>
#include <Crypty/qblowfish.h>
#include "Crypty/crypty.h"
#include "Crypty/genPsw/genPsw.h"
#include "Crypty/cryData/cryData.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_create_Button_clicked();

    void on_signIn_Button_clicked();

    void on_lookpsw_Button_clicked();

private:
    Ui::MainWindow *ui;

public:
    QMainWindow *regist;

signals:
    void signalUserName(QString, QString, QString);
private slots:
    void hide();

};
#endif // LOGIN_H

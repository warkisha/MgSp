#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <QDialog>
#include "logging/log.h"
#include "DataBase/database.h"
#include "mainDialog/dialog.h"

namespace Ui {
class EventLog;
}

class EventLog : public QDialog
{
    Q_OBJECT

public:
    explicit EventLog(QWidget *parent = nullptr);
    ~EventLog();

private slots:
    void on_pushButton_clicked();

    void on_setting_pushButton_clicked();

    void on_closeSetting_Button_clicked();

    void on_deletMainAc_Button_clicked();

    void on_changeMain_Button_clicked();

    void on_change_MainAc_Button_2_clicked();

    void on_closeChangePsw_Button_clicked();

private:
    Ui::EventLog *ui;

public slots:
    void slotUserInfo(QString);

signals:
    void updatePsw(QString);
};

#endif // EVENTLOG_H

#ifndef LOOKBASE_H
#define LOOKBASE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QTableView>
#include "mainDialog/dialog.h"
#include "DataBase/database.h"
#include <QCloseEvent>
#include <QMessageBox>

namespace Ui {
class LookBase;
}

class LookBase : public QDialog
{
    Q_OBJECT

public:
    explicit LookBase(QWidget *parent = nullptr);
    ~LookBase();

private:
    Ui::LookBase *ui;

public slots:
    void slotUserInfo(QString, QString);
private:
    void closeEvent(QCloseEvent *bar);

private slots:
    void on_exit_Button_clicked();

public:
    QSqlTableModel * modele;



};

#endif // LOOKBASE_H

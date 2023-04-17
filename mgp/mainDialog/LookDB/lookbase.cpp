#include "lookbase.h"
#include "ui_lookbase.h"


LookBase::LookBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LookBase)
{
    ui->setupUi(this);
    QPixmap px1 ("./img/img_mini.jpg");
    ui->pic_label->setPixmap (px1);


}

LookBase::~LookBase()
{
    delete ui;
}

void LookBase::slotUserInfo(QString userName, QString psw)
{
    qDebug() << "open all acc wind";
    qDebug() << userName;
    logging log;
    QString result = "просмотр всех паролей\r\n";
    log.log(result);
    modele = new QSqlTableModel;
    modele->setTable("MyDecBook");
    modele->select();
    ui->tableView->setModel(modele);
    ui->tableView->setColumnWidth(1, 250);
    ui->tableView->setColumnWidth(2, 250);
    ui->tableView->setColumnWidth(3, 310);
    QString SS = QString("QHeaderView::section { background: black;}");
    ui->tableView->setStyleSheet(SS);
    ui->psw_label->setText(psw);
}

void LookBase::on_exit_Button_clicked()
{
    close();
}


void LookBase::closeEvent(QCloseEvent *bar)
{
    logging log;
    QSqlQuery query;

    QString result;
    if(query.exec("DELETE FROM MyDecBook")){
        qDebug() << "all delete";
        result = "данные успешно удалены\r\n";
        log.log(result);
    }
    else {
        qDebug() <<"error delete: " << query.lastError();
        result = "ошибка при удалении данных\r\n";
        log.log(result);
    }
    delete modele;
    bar->accept();
}



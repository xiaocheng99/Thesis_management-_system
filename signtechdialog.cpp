#include "signtechdialog.h"
#include "ui_signtechdialog.h"
#include "QSqlQuery"
#include "QSqlError"
#include "qmessagebox.h"
SignTechDialog::SignTechDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignTechDialog)
{
    ui->setupUi(this);
        this->setWindowTitle("信息管理");
}

SignTechDialog::~SignTechDialog()
{
    delete ui;
}

void SignTechDialog::on_btnOK_clicked()
{
  QSqlQuery query;
    query.prepare("INSERT INTO teacher(`teaid`,`teaname`,`teanumber`,`teaage`,`teasex`,`teazhuanye`,`teabanji`,`teaphone`,`teapassword`)"
                  "VALUES(:teaid,:teaname,:teanumber,:teaage,:teasex,:teazhuanye,:teabanji,:teaphone,:teapassword)");
    query.bindValue(":teaid",ui->IndexEdit->text().toInt());
    query.bindValue(":teaname",ui->nameEdit->text());
    query.bindValue(":teanumber",ui->numberEdit->text().toInt());
    query.bindValue(":stuage",ui->ageEdit->text().toInt());
    query.bindValue(":teasex",ui->sexEdit->text());
    query.bindValue(":teazhuanye",ui->zhuanyeEdit->text());
    query.bindValue(":teabanji",ui->banjiEdit->text());
    query.bindValue(":teaphone",ui->phoneEdit->text().toInt());
    query.bindValue(":teapassword",ui->pswdEdit->text());

    if(!query.exec())
    {
        QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
    }
    else {

        //           bool a= querymodel->query().exec();
        //            qDebug()<<a;
       QMessageBox::information(this,"ok","注册成功"+query.lastError().text());
       this->accept();
    }
}

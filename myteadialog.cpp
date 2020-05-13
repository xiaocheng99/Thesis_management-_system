#include "myteadialog.h"
#include "ui_myteadialog.h"
#include "QSqlQuery"
#include "QMessageBox"
#include "QSqlError"
myTeaDialog::myTeaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myTeaDialog)
{
    ui->setupUi(this);
        this->setWindowTitle("信息管理");
}

myTeaDialog::~myTeaDialog()
{
    delete ui;
}

void myTeaDialog::on_btnOK_clicked()
{//修改教师信息
    QSqlQuery query;
    query.prepare("UPDATE teacher SET `teaid`=:teaid,`teaname`=:teaname,`teanumber`=:teanumber , `teaage`=:teaage,`teasex`=:teasex,`teazhuanye`=:teazhuanye,"
                  "  `teabanji`=:teabanji,`teaphone`=:teaphone,`teapassword`=:teapassword where `teanumber`=:ID");
    query.bindValue(":teaid",ui->IndexEdit->text().toInt());
    query.bindValue(":teaname",ui->nameEdit->text());
    query.bindValue(":teanumber",ui->numberEdit->text().toInt());
    query.bindValue(":teaage",ui->ageEdit->text().toInt());
    query.bindValue(":teasex",ui->sexEdit->text());
    query.bindValue(":teazhuanye",ui->zhuanyeEdit->text());
    query.bindValue(":teabanji",ui->banjiEdit->text());
    query.bindValue(":teaphone",ui->phoneEdit->text().toInt());
    query.bindValue(":teapassword",ui->pswdEdit->text());
    query.bindValue(":ID",ui->numberEdit->text().toInt());
    if(!query.exec())
    {
        QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
    }
    else {

        QMessageBox::information(this,"ok","修改成功");
           this->accept();
    }

}

void myTeaDialog::on_btnCancel_clicked()
{
    this->close();
}

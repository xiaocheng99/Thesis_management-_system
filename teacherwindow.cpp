#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "myteadialog.h"
#include "ui_myteadialog.h"
#include "QSqlQuery"
#include "QMessageBox"
#include "QSqlError"
#include "teastudialog.h"
teacherWindow::teacherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacherWindow)
{
    ui->setupUi(this);
        this->setWindowTitle("信息管理");
}

teacherWindow::~teacherWindow()
{
    delete ui;
}

void teacherWindow::on_btnTeacher_clicked()
{//查看个人信息
    QSqlQuery query;
    query.prepare("SELECT * FROM `teacher` WHERE `teanumber`=:ID");
    query.bindValue(":ID",teanum.toInt());

    if(!query.exec())
    {
        QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
    }
    query.next();

    myTeaDialog *my=new myTeaDialog;
  my->  ui->IndexEdit->setText(query.value("teaid").toString());
     my->   ui->nameEdit->setText(query.value("teaname").toString());
    my->    ui->numberEdit->setText(query.value("teanumber").toString());
   my->     ui->ageEdit->setText(query.value("teaage").toString());
    my->    ui->sexEdit->setText(query.value("teasex").toString());
   my->     ui->zhuanyeEdit->setText(query.value("teazhuanye").toString());
    my->    ui->banjiEdit->setText(query.value("teabanji").toString());
    my->    ui->phoneEdit->setText(query.value("teaphone").toString());
    my->    ui->pswdEdit->setText(query.value("teapassword").toString());
      my->exec();

}

void teacherWindow::on_btnStudent_clicked()
{//查看学生信息
    teaStuDialog *stu=new teaStuDialog;
    stu->show();

}

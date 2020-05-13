#include "logindialog.h"
#include "ui_logindialog.h"
#include "QMessageBox"
#include "QSqlQuery"
#include "stuwindow.h"
#include "teacherwindow.h"
#include "QSettings"
#include "mainwindow.h"
#include "QtDebug"
#include "signstudialog.h"
#include "signtechdialog.h"
loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    qDebug()<<ui->checkManger->isChecked();
    this->setWindowTitle("登录窗口");
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_checkStu_stateChanged(int arg1)
{
    bool status = ui->checkStu->isChecked();
    if(status == true)
    {
        ui->checkTea->setChecked(false);
        ui->checkTea->setAutoExclusive(false);
        ui->checkManger->setChecked(false);
        ui->checkManger->setAutoExclusive(false);

    }

}

void loginDialog::on_checkTea_stateChanged(int arg1)
{
    bool status = ui->checkTea->isChecked();
    if(status == true)
    {
        ui->checkStu->setChecked(false);
        ui->checkStu->setAutoExclusive(false);
        ui->checkManger->setChecked(false);
        ui->checkManger->setAutoExclusive(false);

    }
}

void loginDialog::on_checkManger_stateChanged(int arg1)
{
    bool status = ui->checkManger->isChecked();
    if(status == true)
    {
        ui->checkTea->setChecked(false);
        ui->checkTea->setAutoExclusive(false);
        ui->checkStu->setChecked(false);
        ui->checkStu->setAutoExclusive(false);
    }
}

void loginDialog::on_btnOk_clicked()
{//登录
    QString user= ui->userEdit->text();
    QString pswd=ui->pswdEdit->text();
    bool status1 = ui->checkStu->isChecked();
    bool status2= ui->checkTea->isChecked();
    bool status3 = ui->checkManger->isChecked();
    qDebug()<<status3;
    if(!status1&& !status2&& !status3)
    {
        QMessageBox::warning(this,"waring","请选择登录方式！ ");
        return;
    }
    if(status1)
    {//如果选择学生登录
        QSqlQuery query1;
        query1.prepare("   SELECT * FROM `student` WHERE `stunumber`=:stunumbe AND `stupassword`=:stupassword");
        query1.bindValue(":stunumbe",user.toInt());
        query1.bindValue(":stupassword",pswd);
        query1.exec();
        query1.first();
        if(query1.value("stunumber").toString().isEmpty())
        {
            QMessageBox::warning(this,"waring","输入的账号或者密码错误 ");
            return;
        }
        else {
            stuWindow *stu=new stuWindow;
            stu->stunum=user;
            stu->initWindow();
            stu->show();
            this->accept();
        }
    }
    if(status2)
    {//如果选择教师登录
        QSqlQuery query1;
        query1.prepare("  SELECT * FROM `teacher` WHERE `teanumber`=:teanumber  AND `teapassword`=:teapassword");
        query1.bindValue(":teanumber",user.toInt());
        query1.bindValue(":teapassword",pswd);
        query1.exec();
        query1.first();
        if(query1.value("teanumber").toString().isEmpty())
        {
            QMessageBox::warning(this,"waring","输入的账号或者密码错误 ");
            return;
        }
        else {
            teacherWindow *tec=new teacherWindow;
            tec->teanum=user;
            tec->show();
            this->accept();
        }
    }
    if(status3)
    {//管理员登录
        QSettings settings("biye","sheji");
        QString m_user=   settings.value("user","user").toString();
        QString m_pswd=  settings.value("pswd","123456").toString();
        if(m_user==user&&m_pswd==pswd)
        {
            MainWindow *m=new MainWindow;
            m->show();
            this->accept();
        }
        else {
            QMessageBox::warning(this,"waring","输入的账号或者密码错误 ");
        }
    }
}

void loginDialog::on_btnStuSign_clicked()
{//进入学生注册界面
    SignStuDialog *stu=new  SignStuDialog;
    stu->exec();

}

void loginDialog::on_btnTchSign_clicked()
{//进入教师注册界面

    SignTechDialog *tech=new SignTechDialog;
    tech->exec();
}

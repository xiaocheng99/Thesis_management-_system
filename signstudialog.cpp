#include "signstudialog.h"
#include "ui_signstudialog.h"
#include "QSqlQuery"
#include "QSqlError"
#include "QMessageBox"
SignStuDialog::SignStuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignStuDialog)
{
    ui->setupUi(this);
        this->setWindowTitle("信息管理");
}

SignStuDialog::~SignStuDialog()
{
    delete ui;
}

void SignStuDialog::on_btnOk_clicked()
{//注册添加
    QSqlQuery query;
    query.prepare("INSERT INTO student( `stuid`,`stuname`,`stunumber`,`stuage`,`stusex`,`stuzhuanye`,`stubanji`,`stuteacher`,`stuphone`,`stupassword`,`stubishename`,`stubishetime`,`stubishezishu`,`stubishewenxian`,`stubishepinfen`)"
                  "VALUES(:stuid,:stuname,:stunumber,:stuage,:stusex,:stuzhuanye,:stubanji,:stuteacher,:stuphone,:stupassword,:stubishename,:stubishetime,:stubishezishu,:stubishewenxian,:stubishepinfen)");
    query.bindValue(":stuid",ui->IndexEdit->text().toInt());
    query.bindValue(":stuname",ui->nameEdit->text());
    query.bindValue(":stunumber",ui->numberEdit->text().toInt());
    query.bindValue(":stuage",ui->ageEdit->text().toInt());
    query.bindValue(":stusex",ui->sexEdit->text());
    query.bindValue(":stuzhuanye",ui->zhuanyeEdit->text());
    query.bindValue(":stubanji",ui->banjiEdit->text());
    query.bindValue(":stuteacher",ui->teacherEdit->text());
    query.bindValue(":stuphone",ui->phoneEdit->text().toInt());
    query.bindValue(":stupassword",ui->pswdEdit->text());
    query.bindValue(":stubishename",ui->bishetimeEdit->text());
    query.bindValue(":stubishetime",ui->bishetimeEdit->text());
    query.bindValue(":stubishezishu",ui->zishuEdit->text().toInt());
    query.bindValue(":stubishewenxian",ui->wenxianEdit->text());
    query.bindValue(":stubishepinfen",ui->pinfenEdit->text());
    if(!query.exec())
    {
        QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
    }
    else {

        //           bool a= querymodel->query().exec();
        //            qDebug()<<a;
      QMessageBox::information(this,"waring","注册成功");
      this->accept();
    }
}



void SignStuDialog::on_btnCancel_clicked()
{
    this->close();
}

#include "stuwindow.h"
#include "ui_stuwindow.h"
#include "QSqlQuery"
#include "QMessageBox"
#include "QSqlError"
#include "logindialog.h"
stuWindow::stuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stuWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("信息管理");

    initWindow();
}
void stuWindow::receiveData(QString str)
{
    stunum=str;
    initWindow();
}

stuWindow::~stuWindow()
{
    delete ui;
}
void  stuWindow::initWindow()
{
    //显示学生个人信息
    QSqlQuery query;
    query.prepare("SELECT * FROM `student`  WHERE `stunumber`=:ID");
    query.bindValue(":ID",stunum);
    query.exec();
    query.first();
    ui->IndexEdit->setText(query.value("stuid").toString());
    ui->nameEdit->setText(query.value("stuname").toString());
    ui->numberEdit->setText(query.value("stunumber").toString());
    ui->ageEdit->setText(query.value("stuage").toString());
    ui->sexEdit->setText(query.value("stusex").toString());
    ui->zhuanyeEdit->setText(query.value("stuzhuanye").toString());
    ui->banjiEdit->setText(query.value("stubanji").toString());
    ui->teacherEdit->setText(query.value("stuteacher").toString());
    ui->phoneEdit->setText(query.value("stuphone").toString());
    ui->pswdEdit->setText(query.value("stupassword").toString());
    ui->bishenameEdit->setText(query.value("stubishename").toString());
    ui->bishetimeEdit->setText(query.value("stubishetime").toString());
    ui->zishuEdit->setText(query.value("stubishezishu").toString());
    ui->wenxianEdit->setText(query.value("stubishewenxian").toString());
    ui->pinfenEdit->setText(query.value("stubishepinfen").toString());
}

void stuWindow::on_btnOk_clicked()
{//修改学生信息
    QSqlQuery query;
    query.prepare("UPDATE student SET `stuid`=:stuid,`stuname`=:stuname,`stunumber`=:stunumber , `stuage`=:stuage,`stusex`=:stusex,`stuzhuanye`=:stuzhuanye,"
                  "  `stubanji`=:stubanji,`stuteacher`=:stuteacher,`stuphone`=:stuphone  ,`stupassword`=:stupassword,`stubishename`=:stubishename,`stubishetime`=:stubishetime,"
                  "  `stubishezishu`=:stubishezishu,`stubishewenxian`=:stubishewenxian,`stubishepinfen`=:stubishepinfen   where `stunumber`=:ID");
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
    query.bindValue(":stubishename",ui->bishenameEdit->text());
    query.bindValue(":stubishetime",ui->bishetimeEdit->text());
    query.bindValue(":stubishezishu",ui->zishuEdit->text().toInt());
    query.bindValue(":stubishewenxian",ui->wenxianEdit->text());
    query.bindValue(":stubishepinfen",ui->pinfenEdit->text());
    query.bindValue(":ID",stunum.toInt());
    if(!query.exec())
    {
        QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
    }
    else {

        QMessageBox::information(this,"ok","修改成功");
        stunum=ui->numberEdit->text();
    }

}

void stuWindow::on_btnCancel_clicked()
{
    //关闭
    this->close();
}

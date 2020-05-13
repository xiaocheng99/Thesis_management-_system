#include "teacherdialog.h"
#include "ui_teacherdialog.h"
#include "QtDebug"
TeacherDialog::TeacherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherDialog)
{
    ui->setupUi(this);
        this->setWindowTitle("信息管理");
}

TeacherDialog::~TeacherDialog()
{
    delete ui;
}

void TeacherDialog::setUpdateRecored(QSqlRecord &recdata)
{//编辑记录，更新记录到数据界面
    mrecored=recdata;
    ui->IndexEdit->setEnabled(false);//设置序号不允许编辑
    setWindowTitle("更新记录");
    ui->IndexEdit->setText(recdata.value("teaid").toString());
    ui->nameEdit->setText(recdata.value("teaname").toString());
    ui->numberEdit->setText(recdata.value("teanumber").toString());
    ui->ageEdit->setText(recdata.value("teaage").toString());
    ui->sexEdit->setText(recdata.value("teasex").toString());
    ui->zhuanyeEdit->setText(recdata.value("teazhuanye").toString());
    ui->banjiEdit->setText(recdata.value("teabanji").toString());
    ui->phoneEdit->setText(recdata.value("teaphone").toString());
    ui->pswdEdit->setText(recdata.value("teapassword").toString());




}
void TeacherDialog::setInsertRecored(QSqlRecord &recdata)
{//插入记录，无需更新界面显示，但是要存储recdata的字段结构
    mrecored=recdata;//保存recdata到内部变量
    ui->IndexEdit->setEnabled(true);//设置序号允许编辑
    setWindowTitle("插入记录");
    ui->IndexEdit->setText(recdata.value("teaid").toString());
}
QSqlRecord TeacherDialog::getRecoredDate( )
{//“确定”按钮之后，界面数据保存到记录mrecored-
    qDebug()<<"进来了";
    mrecored.setValue("teaid",ui->IndexEdit->text().toInt());
    mrecored.setValue("teaname",ui->nameEdit->text());
    mrecored.setValue("teanumber",ui->numberEdit->text().toInt());
    mrecored.setValue("teaage",ui->ageEdit->text().toInt());
    mrecored.setValue("teasex",ui->sexEdit->text());
    mrecored.setValue("teazhuanye",ui->zhuanyeEdit->text());
    mrecored.setValue("teabanji",ui->banjiEdit->text());
    mrecored.setValue("teaphone",ui->phoneEdit->text().toInt());
    mrecored.setValue("teapassword",ui->pswdEdit->text());
    return  mrecored;

}

void TeacherDialog::on_btnOK_clicked()
{
    this->accept();
}

void TeacherDialog::on_btnCancel_clicked()
{
    this->close();
}

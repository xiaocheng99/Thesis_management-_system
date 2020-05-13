#include "studialog.h"
#include "ui_studialog.h"
#include "QtDebug"
stuDialog::stuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuDialog)
{
    ui->setupUi(this);
        this->setWindowTitle("信息管理");
}

stuDialog::~stuDialog()
{
    delete ui;
}
void stuDialog::setUpdateRecored(QSqlRecord &recdata)
{//编辑记录，更新记录到数据界面
    mrecored=recdata;
    ui->IndexEdit->setEnabled(false);//设置序号不允许编辑
    setWindowTitle("更新记录");
    ui->IndexEdit->setText(recdata.value("stuid").toString());
    ui->nameEdit->setText(recdata.value("stuname").toString());
    ui->numberEdit->setText(recdata.value("stunumber").toString());
    ui->ageEdit->setText(recdata.value("stuage").toString());
    ui->sexEdit->setText(recdata.value("stusex").toString());
    ui->zhuanyeEdit->setText(recdata.value("stuzhuanye").toString());
    ui->banjiEdit->setText(recdata.value("stubanji").toString());
    ui->teacherEdit->setText(recdata.value("stuteacher").toString());
    ui->phoneEdit->setText(recdata.value("stuphone").toString());
    ui->pswdEdit->setText(recdata.value("stupassword").toString());
    ui->bishenameEdit->setText(recdata.value("stubishename").toString());
    ui->bishetimeEdit->setText(recdata.value("stubishetime").toString());
    ui->zishuEdit->setText(recdata.value("stubishezishu").toString());
    ui->wenxianEdit->setText(recdata.value("stubishewenxian").toString());
    ui->pinfenEdit->setText(recdata.value("stubishepinfen").toString());



}
void stuDialog::setInsertRecored(QSqlRecord &recdata)
{//插入记录，无需更新界面显示，但是要存储recdata的字段结构
    mrecored=recdata;//保存recdata到内部变量
    ui->IndexEdit->setEnabled(true);//设置序号允许编辑
    setWindowTitle("插入记录");
    ui->IndexEdit->setText(recdata.value("stuid").toString());
}
QSqlRecord stuDialog::getRecoredDate( )
{//“确定”按钮之后，界面数据保存到记录mrecored-
    qDebug()<<"进来了";
    mrecored.setValue("stuid",ui->IndexEdit->text().toInt());
    mrecored.setValue("stuname",ui->nameEdit->text());
    mrecored.setValue("stunumber",ui->numberEdit->text().toInt());
    mrecored.setValue("stuage",ui->ageEdit->text().toInt());
    mrecored.setValue("stusex",ui->sexEdit->text());
    mrecored.setValue("stuzhuanye",ui->zhuanyeEdit->text());
    mrecored.setValue("stubanji",ui->banjiEdit->text());
    mrecored.setValue("stuteacher",ui->teacherEdit->text());
    mrecored.setValue("stuphone",ui->phoneEdit->text().toInt());
    mrecored.setValue("stupassword",ui->pswdEdit->text());
    mrecored.setValue("stubishename",ui->bishenameEdit->text());
    mrecored.setValue("stubishetime",ui->bishetimeEdit->text());
    mrecored.setValue("stubishezishu",ui->zishuEdit->text().toInt());
    mrecored.setValue("stubishewenxian",ui->wenxianEdit->text());
    mrecored.setValue("stubishepinfen",ui->pinfenEdit->text());
    return  mrecored;

}

void stuDialog::on_btnOk_clicked()
{
    this->accept();
}

void stuDialog::on_btnCancel_clicked()
{
    this->close();
}

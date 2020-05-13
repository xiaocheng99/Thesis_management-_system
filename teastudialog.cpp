#include "teastudialog.h"
#include "ui_teastudialog.h"
#include "QSqlQuery"
#include "QSqlError"
#include "QMessageBox"
#include "QSqlRecord"
#include "qdebug.h"
#include "studialog.h"

teaStuDialog::teaStuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teaStuDialog)
{
    ui->setupUi(this);
        this->setWindowTitle("信息管理");
    initdlg();
}

teaStuDialog::~teaStuDialog()
{
    delete ui;
}

void teaStuDialog::initdlg()
{
    querymodel =new QSqlQueryModel(this);
    theselection =new QItemSelectionModel(  querymodel);
    querymodel->setQuery("SELECT * FROM `student` ");
    querymodel->setHeaderData(0,Qt::Horizontal,"编号");
    querymodel->setHeaderData(1,Qt::Horizontal,"姓名");
    querymodel->setHeaderData(2,Qt::Horizontal,"学号");
    querymodel->setHeaderData(3,Qt::Horizontal,"年龄");
    querymodel->setHeaderData(4,Qt::Horizontal,"性别");
    querymodel->setHeaderData(5,Qt::Horizontal,"专业");
    querymodel->setHeaderData(6,Qt::Horizontal,"班级");
    querymodel->setHeaderData(7,Qt::Horizontal,"指导教师");
    querymodel->setHeaderData(8,Qt::Horizontal,"联系方式");
    querymodel->setHeaderData(9,Qt::Horizontal,"密码");
    querymodel->setHeaderData(10,Qt::Horizontal,"毕设名称");
    querymodel->setHeaderData(11,Qt::Horizontal,"发布时间");
    querymodel->setHeaderData(12,Qt::Horizontal,"字数");
    querymodel->setHeaderData(13,Qt::Horizontal,"参考文献");
    querymodel->setHeaderData(14,Qt::Horizontal,"评分");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel( querymodel);
    ui->tableView->setSelectionModel(  theselection);
}

void teaStuDialog::updateRecord(int recNo)
{//学生更新一条记录
    QSqlRecord curRec=querymodel->record(recNo);
    int index=curRec.value("stuid").toInt();
    qDebug()<<index;
    QSqlQuery query;
    query.prepare("SELECT * FROM `student` WHERE `stuid`=:ID");
    query.bindValue(":ID",index);
    query.exec();
    query.first();
    if(!query.isValid())
    {
        return;
    }
    curRec =query.record();
    stuDialog *datadlg=new stuDialog;
    datadlg->setUpdateRecored(curRec);//调用对话框函数更新数据界面

    if(datadlg->exec()==QDialog::Accepted)
    {

        QSqlRecord recData=datadlg->getRecoredDate();//获得 会话框返回记录
        query.prepare("UPDATE student SET `stuid`=:stuid,`stuname`=:stuname,`stunumber`=:stunumber , `stuage`=:stuage,`stusex`=:stusex,`stuzhuanye`=:stuzhuanye,"
                      "  `stubanji`=:stubanji,`stuteacher`=:stuteacher,`stuphone`=:stuphone  ,`stupassword`=:stupassword,`stubishename`=:stubishename,`stubishetime`=:stubishetime,"
                      "  `stubishezishu`=:stubishezishu,`stubishewenxian`=:stubishewenxian,`stubishepinfen`=:stubishepinfen   where `stuid`=:ID");
        query.bindValue(":stuid",recData.value("stuid"));
        query.bindValue(":stuname",recData.value("stuname"));
        query.bindValue(":stunumber",recData.value("stunumber"));
        query.bindValue(":stuage",recData.value("stuage"));
        query.bindValue(":stusex",recData.value("stusex"));
        query.bindValue(":stuzhuanye",recData.value("stuzhuanye"));
        query.bindValue(":stubanji",recData.value("stubanji"));
        query.bindValue(":stuteacher",recData.value("stuteacher"));
        query.bindValue(":stuphone",recData.value("stuphone"));
        query.bindValue(":stupassword",recData.value("stupassword"));
        query.bindValue(":stubishename",recData.value("stubishename"));
        query.bindValue(":stubishetime",recData.value("stubishetime"));
        query.bindValue(":stubishezishu",recData.value("stubishezishu"));
        query.bindValue(":stubishewenxian",recData.value("stubishewenxian"));
        query.bindValue(":stubishepinfen",recData.value("stubishepinfen"));
        query.bindValue(":ID",index);
        if(!query.exec())
        {
            QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
        }
        else {

            querymodel->query().exec();

        }
        delete datadlg;
    }

}
void teaStuDialog::on_btnAdd_clicked()
{//增加
    QSqlQuery query ;
    query.exec("SELECT * FROM `student` WHERE `stuid`=-1");//只查询字段信息
    QSqlRecord curRec=query.record();//获取当前记录，实际为空
    curRec.setValue("stuid",querymodel->rowCount()+1);
    stuDialog *datadlg=new stuDialog;
    datadlg->setInsertRecored(curRec);//调用对话框函数更新数据界面
    if(datadlg->exec()==QDialog::Accepted)
    {
        QSqlRecord recData=datadlg->getRecoredDate();//获得 会话框返回记录
        query.prepare("INSERT INTO student( `stuid`,`stuname`,`stunumber`,`stuage`,`stusex`,`stuzhuanye`,`stubanji`,`stuteacher`,`stuphone`,`stupassword`,`stubishename`,`stubishetime`,`stubishezishu`,`stubishewenxian`,`stubishepinfen`)"
                      "VALUES(:stuid,:stuname,:stunumber,:stuage,:stusex,:stuzhuanye,:stubanji,:stuteacher,:stuphone,:stupassword,:stubishename,:stubishetime,:stubishezishu,:stubishewenxian,:stubishepinfen)");
        query.bindValue(":stuid",recData.value("stuid"));
        query.bindValue(":stuname",recData.value("stuname"));
        query.bindValue(":stunumber",recData.value("stunumber"));
        query.bindValue(":stuage",recData.value("stuage"));
        query.bindValue(":stusex",recData.value("stusex"));
        query.bindValue(":stuzhuanye",recData.value("stuzhuanye"));
        query.bindValue(":stubanji",recData.value("stubanji"));
        query.bindValue(":stuteacher",recData.value("stuteacher"));
        query.bindValue(":stuphone",recData.value("stuphone"));
        query.bindValue(":stupassword",recData.value("stupassword"));
        query.bindValue(":stubishename",recData.value("stubishename"));
        query.bindValue(":stubishetime",recData.value("stubishetime"));
        query.bindValue(":stubishezishu",recData.value("stubishezishu"));
        query.bindValue(":stubishewenxian",recData.value("stubishewenxian"));
        query.bindValue(":stubishepinfen",recData.value("stubishepinfen"));
        if(!query.exec())
        {
            QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
        }
        else {

            //           bool a= querymodel->query().exec();
            //            qDebug()<<a;
            initdlg();
        }
    }
}

void teaStuDialog::on_btnReset_clicked()
{//修改
    int curRecno=theselection->currentIndex().row();
        updateRecord(curRecno);

}

void teaStuDialog::on_btnDelete_clicked()
{//删除
    int curRecno=theselection->currentIndex().row();
    QSqlRecord curRec=querymodel->record(curRecno);//获取当前记录
    if (curRec.isEmpty())
        return;
        int index=curRec.value("stuid").toInt();//获取员工编号
        QSqlQuery query;
        query.prepare("DELETE FROM `student` WHERE `stuid`=:ID");
        query.bindValue(":ID",index);
        if(!query.exec())
        {
            QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
        }
        else {
            initdlg();
    }
}

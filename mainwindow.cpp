#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlRecord"
#include <studialog.h>
#include "QtDebug"
#include "QSqlQuery"
#include "qmessagebox.h"
#include "QSqlError"
#include "teacherdialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("信息管理");
    connect(ui->tableView->horizontalHeader(),SIGNAL(sectionResized(int, int, int)),
            ui->tableView,SLOT(resizeRowsToContents()));
    studentInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::studentInfo()
{//学生信息显示
    info="学生";
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
void MainWindow::TeacherInfo()
{//教师信息显示
    info="教师";
    querymodel =new QSqlQueryModel(this);
    theselection =new QItemSelectionModel(  querymodel);
    querymodel->setQuery("SELECT * FROM `teacher`");
    querymodel->setHeaderData(0,Qt::Horizontal,"编号");
    querymodel->setHeaderData(1,Qt::Horizontal,"姓名");
    querymodel->setHeaderData(2,Qt::Horizontal,"工号");
    querymodel->setHeaderData(3,Qt::Horizontal,"年龄");
    querymodel->setHeaderData(4,Qt::Horizontal,"性别");
    querymodel->setHeaderData(5,Qt::Horizontal,"专业");
    querymodel->setHeaderData(6,Qt::Horizontal,"班级");
    querymodel->setHeaderData(7,Qt::Horizontal,"联系方式");
    querymodel->setHeaderData(8,Qt::Horizontal,"密码");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel( querymodel);
    ui->tableView->setSelectionModel(  theselection);
}

void MainWindow::on_actTeacher_triggered()
{
    TeacherInfo();
}

void MainWindow::on_actStudent_triggered()
{
    studentInfo();
}

void MainWindow::updateRecord(int recNo)
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
void MainWindow::TeaupdateRecord(int recNo)
{//教师更新
    QSqlRecord curRec=querymodel->record(recNo);
    int index=curRec.value("teaid").toInt();
    qDebug()<<index;
    QSqlQuery query;
    query.prepare("SELECT * FROM `teacher` WHERE `teaid`=:ID");
    query.bindValue(":ID",index);
    query.exec();
    query.first();
    if(!query.isValid())
    {
        return;
    }
    curRec =query.record();
    TeacherDialog *datadlg=new TeacherDialog;
    datadlg->setUpdateRecored(curRec);//调用对话框函数更新数据界面

    if(datadlg->exec()==QDialog::Accepted)
    {

        QSqlRecord recData=datadlg->getRecoredDate();//获得 会话框返回记录
        query.prepare("UPDATE teacher SET `teaid`=:teaid,`teaname`=:teaname,`teanumber`=:teanumber , `teaage`=:teaage,`teasex`=:teasex,`teazhuanye`=:teazhuanye,"
                      "  `teabanji`=:teabanji,`teaphone`=:teaphone,`teapassword`=:teapassword where `teaid`=:ID");
        query.bindValue(":teaid",recData.value("teaid"));
        query.bindValue(":teaname",recData.value("teaname"));
        query.bindValue(":teanumber",recData.value("teanumber"));
        query.bindValue(":teaage",recData.value("teaage"));
        query.bindValue(":teasex",recData.value("teasex"));
        query.bindValue(":teazhuanye",recData.value("teazhuanye"));
        query.bindValue(":teabanji",recData.value("teabanji"));
        query.bindValue(":teaphone",recData.value("teaphone"));
        query.bindValue(":teapassword",recData.value("teapassword"));
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

void MainWindow::on_btnAdd_clicked()
{//增加
    if(info=="学生"){

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
                studentInfo();
            }
        }
    }
    else if (info=="教师")
    {
        QSqlQuery query ;
        query.exec("SELECT * FROM `teacher` WHERE `teaid`=-1");//只查询字段信息
        QSqlRecord curRec=query.record();//获取当前记录，实际为空
        curRec.setValue("teaid",querymodel->rowCount()+1);
        TeacherDialog *datadlg=new TeacherDialog;
        datadlg->setInsertRecored(curRec);//调用对话框函数更新数据界面
        if(datadlg->exec()==QDialog::Accepted)
        {
            QSqlRecord recData=datadlg->getRecoredDate();//获得 会话框返回记录
            query.prepare("INSERT INTO teacher(`teaid`,`teaname`,`teanumber`,`teaage`,`teasex`,`teazhuanye`,`teabanji`,`teaphone`,`teapassword`)"
                          "VALUES(:teaid,:teaname,:teanumber,:teaage,:teasex,:teazhuanye,:teabanji,:teaphone,:teapassword)");
            query.bindValue(":teaid",recData.value("teaid"));
            query.bindValue(":teaname",recData.value("teaname"));
            query.bindValue(":teanumber",recData.value("teanumber"));
            query.bindValue(":stuage",recData.value("stuage"));
            query.bindValue(":teasex",recData.value("teasex"));
            query.bindValue(":teazhuanye",recData.value("teazhuanye"));
            query.bindValue(":teabanji",recData.value("teabanji"));
            query.bindValue(":teaphone",recData.value("teaphone"));
            query.bindValue(":teapassword",recData.value("teapassword"));

            if(!query.exec())
            {
                QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
            }
            else {

                //           bool a= querymodel->query().exec();
                //            qDebug()<<a;
                TeacherInfo();
            }
        }
    }


}

void MainWindow::on_btnReset_clicked()
{//修改
    int curRecno=theselection->currentIndex().row();
    if(info=="学生"){
        updateRecord(curRecno);
    }
    else if (info=="教师") {
        TeaupdateRecord(curRecno);
    }
}

void MainWindow::on_btnDelete_clicked()
{//删除
    int curRecno=theselection->currentIndex().row();
    QSqlRecord curRec=querymodel->record(curRecno);//获取当前记录
    if (curRec.isEmpty())
        return;
    if(info=="学生"){
        int index=curRec.value("stuid").toInt();//获取员工编号
        QSqlQuery query;
        query.prepare("DELETE FROM `student` WHERE `stuid`=:ID");
        query.bindValue(":ID",index);
        if(!query.exec())
        {
            QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
        }
        else {
            studentInfo();
        }
    }
    else if (info=="教师")
    {
        int index=curRec.value("teaid").toInt();//获取员工编号
        QSqlQuery query;
        query.prepare("DELETE FROM `teacher` WHERE `teaid`=:ID");
        query.bindValue(":ID",index);
        if(!query.exec())
        {
            QMessageBox::warning(this,"waring","记录更新错误\n"+query.lastError().text());
        }
        else {
            TeacherInfo();
        }
    }

}

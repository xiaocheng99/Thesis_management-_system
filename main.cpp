#include "mainwindow.h"
#include <QApplication>
#include "QtDebug"
#include "stuwindow.h"
#include "teacherwindow.h"
#include "logindialog.h"
#include "QSettings"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSettings settings("biye","sheji");
    settings.setValue("user","user");
    settings.setValue("pswd","123456");
    QSqlDatabase d = QSqlDatabase::addDatabase("QMYSQL");
    d.setHostName("localhost");
    d.setDatabaseName("lcc");
    d.setPort(3306);
    d.setUserName("root");
    d.setPassword("1019");
    if(d.open())
        qDebug()<<"Hi mysql!连接"<<endl;
    else
        qDebug()<<"失败"<<endl;
    qDebug()<<QSqlDatabase::drivers()<<endl;
//    MainWindow w;
//    w.show();

//    teacherWindow t;
//    t.show();
   loginDialog *login=new loginDialog;
 login->exec();

    return a.exec();
}

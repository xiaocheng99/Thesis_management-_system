#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QSqlQueryModel>
#include <QItemSelectionModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString info;
    QSqlQueryModel *querymodel;//数据模型
    QItemSelectionModel  *theselection;//选择模型
    void studentInfo();
    void TeacherInfo();
    void updateRecord(int recNo);
     void TeaupdateRecord(int recNo);
private slots:
    void on_actTeacher_triggered();

    void on_actStudent_triggered();

    void on_btnAdd_clicked();

    void on_btnReset_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

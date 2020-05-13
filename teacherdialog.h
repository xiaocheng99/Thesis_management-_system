#ifndef TEACHERDIALOG_H
#define TEACHERDIALOG_H

#include <QDialog>
#include "QSqlRecord"
namespace Ui {
class TeacherDialog;
}

class TeacherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherDialog(QWidget *parent = nullptr);
    ~TeacherDialog();

    QSqlRecord  mrecored;//保存每一条记录的数据
  void setUpdateRecored(QSqlRecord &recdata);//更新记录
  void setInsertRecored(QSqlRecord &recdata);//插入记录
  QSqlRecord getRecoredDate();//获取录入的数据

private slots:
  void on_btnOK_clicked();

  void on_btnCancel_clicked();

private:
    Ui::TeacherDialog *ui;
};

#endif // TEACHERDIALOG_H

#ifndef STUDIALOG_H
#define STUDIALOG_H

#include <QDialog>
#include "QSqlRecord"
namespace Ui {
class stuDialog;
}

class stuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit stuDialog(QWidget *parent = nullptr);
    ~stuDialog();
      QSqlRecord  mrecored;//保存每一条记录的数据
    void setUpdateRecored(QSqlRecord &recdata);//更新记录
    void setInsertRecored(QSqlRecord &recdata);//插入记录
    QSqlRecord getRecoredDate();//获取录入的数据
private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::stuDialog *ui;
};

#endif // STUDIALOG_H

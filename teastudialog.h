#ifndef TEASTUDIALOG_H
#define TEASTUDIALOG_H

#include <QDialog>
#include "QSqlQueryModel"
#include "QItemSelectionModel"
namespace Ui {
class teaStuDialog;
}

class teaStuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit teaStuDialog(QWidget *parent = nullptr);
    ~teaStuDialog();
void initdlg();
QSqlQueryModel *querymodel;//数据模型
QItemSelectionModel  *theselection;//选择模型

void updateRecord(int recNo);
private slots:
void on_btnAdd_clicked();

void on_btnReset_clicked();

void on_btnDelete_clicked();

private:
    Ui::teaStuDialog *ui;
};

#endif // TEASTUDIALOG_H

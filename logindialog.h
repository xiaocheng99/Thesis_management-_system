#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();

private slots:
    void on_checkStu_stateChanged(int arg1);

    void on_checkTea_stateChanged(int arg1);

    void on_checkManger_stateChanged(int arg1);

    void on_btnOk_clicked();

    void on_btnStuSign_clicked();

    void on_btnTchSign_clicked();

private:
    Ui::loginDialog *ui;
 signals:
    void sendData(QString str);//信号

};

#endif // LOGINDIALOG_H

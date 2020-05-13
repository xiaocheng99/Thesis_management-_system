#ifndef MYTEADIALOG_H
#define MYTEADIALOG_H

#include <QDialog>

namespace Ui {
class myTeaDialog;
}

class myTeaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myTeaDialog(QWidget *parent = nullptr);
    ~myTeaDialog();
    Ui::myTeaDialog *ui;
private slots:
    void on_btnOK_clicked();

    void on_btnCancel_clicked();

private:

};

#endif // MYTEADIALOG_H

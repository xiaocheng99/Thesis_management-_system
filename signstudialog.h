#ifndef SIGNSTUDIALOG_H
#define SIGNSTUDIALOG_H

#include <QDialog>

namespace Ui {
class SignStuDialog;
}

class SignStuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignStuDialog(QWidget *parent = nullptr);
    ~SignStuDialog();

private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::SignStuDialog *ui;
};

#endif // SIGNSTUDIALOG_H

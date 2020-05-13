#ifndef SIGNTECHDIALOG_H
#define SIGNTECHDIALOG_H

#include <QDialog>

namespace Ui {
class SignTechDialog;
}

class SignTechDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignTechDialog(QWidget *parent = nullptr);
    ~SignTechDialog();

private slots:
    void on_btnOK_clicked();

private:
    Ui::SignTechDialog *ui;
};

#endif // SIGNTECHDIALOG_H

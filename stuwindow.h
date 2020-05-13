#ifndef STUWINDOW_H
#define STUWINDOW_H

#include <QMainWindow>

namespace Ui {
class stuWindow;
}

class stuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit stuWindow(QWidget *parent = nullptr);
    ~stuWindow();
    QString stunum="123456";
 void  initWindow();
  void receiveData(QString str);
private slots:
 void on_btnOk_clicked();

 void on_btnCancel_clicked();



private:
    Ui::stuWindow *ui;
};

#endif // STUWINDOW_H

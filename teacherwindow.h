#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class teacherWindow;
}

class teacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacherWindow(QWidget *parent = nullptr);
    ~teacherWindow();
QString teanum="1";
private slots:
void on_btnTeacher_clicked();

void on_btnStudent_clicked();

private:
    Ui::teacherWindow *ui;
};

#endif // TEACHERWINDOW_H

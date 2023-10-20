#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void input_numbers();
    void on_pushButton_dot_clicked();
    void operation();

    void on_pushButton_AC_clicked();

    void on_pushButton_equ_clicked();
    void math_operations();

private:
    Ui::Calculator *ui;
};
#endif // MAINWINDOW_H

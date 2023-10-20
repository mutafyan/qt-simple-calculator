#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);


    connect(ui->pushButton_0,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()), this, SLOT(input_numbers()));
    connect(ui->pushButton_sgn,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_percent,SIGNAL(clicked()), this, SLOT(operation()));
    connect(ui->pushButton_div,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_bazm,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()), this, SLOT(operation()));

    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_bazm->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input_numbers()
{
    QPushButton *pressed_b = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(ui->result->text().contains('.') && pressed_b->text() == "0"){
        new_label = ui->result->text() + pressed_b->text();
    } else {
        all_numbers = (ui->result->text() + pressed_b->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result->setText(new_label);
    }
}
void MainWindow::operation()
{
    QPushButton *pressed_b = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if(pressed_b->text() == "+/-"){
        all_numbers = (ui->result->text().toDouble());
        all_numbers = all_numbers * (-1);
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result->setText(new_label);
    }

    else if(pressed_b->text() == "%") {
        all_numbers = (ui->result->text().toDouble());
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result->setText(new_label);
    }
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result->text().contains('.')))
        ui->result->setText(ui->result->text() + ".");
}

void MainWindow::math_operations()
{
    QPushButton *pressed_b = (QPushButton *)sender();
    num_first = ui->result->text().toDouble();
    ui->result->setText("");
    pressed_b->setChecked(true);

}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_bazm->setChecked(false);

    ui->result->setText("0");
}


void MainWindow::on_pushButton_equ_clicked()
{
    double labelNum, num_second;
    QString new_label;

    num_second = ui->result->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {
        labelNum = num_first + num_second;
        new_label = QString::number(labelNum, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked()) {
        labelNum = num_first - num_second;
        new_label = QString::number(labelNum, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_div->isChecked()) {
        if(num_second == 0) {
            ui->result->setText("0");
        } else {
            labelNum = num_first / num_second;
            new_label = QString::number(labelNum, 'g', 15);
            ui->result->setText(new_label);
        }
        ui->pushButton_div->setChecked(false);
    }
    else if(ui->pushButton_bazm->isChecked()) {
        labelNum = num_first * num_second;
        new_label = QString::number(labelNum, 'g', 15);
        ui->result->setText(new_label);
        ui->pushButton_bazm->setChecked(false);
    }
}


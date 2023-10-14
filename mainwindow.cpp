#include "mainwindow.h"
#include "ui_mainwindow.h"
double calcValue = 0.0;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Entry->setText(QString::number(calcValue));
    QPushButton *numButtons[10];
    for (int i = 0; i < 10; ++i){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(clicked(bool)), this, SLOT(NumPressed()));
    }
    connect(ui-> btn_add, SIGNAL(clicked(bool)), this, SLOT(MathButtonPressed()));
    connect(ui-> btn_sub, SIGNAL(clicked(bool)), this, SLOT(MathButtonPressed()));
    connect(ui-> btn_mul, SIGNAL(clicked(bool)), this, SLOT(MathButtonPressed()));
    connect(ui-> btn_div, SIGNAL(clicked(bool)), this, SLOT(MathButtonPressed()));
    connect(ui-> btn_exp, SIGNAL(clicked(bool)), this, SLOT(MathButtonPressed()));
    connect(ui-> btn_equal, SIGNAL(clicked(bool)), this, SLOT(EqualButtonPressed()));
    connect(ui->btn_clear, SIGNAL(clicked(bool)), this, SLOT(CEButtonPressed()));
    connect(ui->btn_backspace, SIGNAL(clicked(bool)), this, SLOT(BackspaceButtonPressed()));
    connect(ui-> btn_clearAll, SIGNAL(clicked(bool)), this, SLOT(CButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed()
{
    QPushButton *button =  (QPushButton *)sender();
    QString butValue = button->text();
    QString entryValue = ui->Entry->text();
    if ((entryValue.toDouble() == 0) || (entryValue.toDouble() == 0.0)){
        ui->Entry->setText(butValue);
    } else {
        QString newValue = entryValue + butValue;
        double dblNewValue = newValue.toDouble();
        ui->Entry->setText(QString::number(dblNewValue, 'g', 15));
    }
}

void MainWindow::MathButtonPressed(){
    calc.setDefault();
    QString entryValue = ui->Entry->text();
    calcValue = entryValue.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butValue = button->text();
    if (QString::compare(butValue, "÷", Qt::CaseInsensitive) == 0){
        calc.setDivide();
    } else if (QString::compare(butValue, "×", Qt::CaseInsensitive) == 0){
        calc.setMult();
    } else if (QString::compare(butValue, "+", Qt::CaseInsensitive) == 0){
        calc.setPlus();
    } else if (QString::compare(butValue, "-", Qt::CaseInsensitive) == 0){
        calc.setMinus();
    } else if (QString::compare(butValue, "^", Qt::CaseInsensitive) == 0){
        calc.setExp();
    }
    ui->Entry->setText("");

}

void MainWindow::EqualButtonPressed() {
    double solution = 0;
    QString entryValue = ui->Entry->text();
    double dblEntryValue = entryValue.toDouble();

    if (calc.divTrigger && dblEntryValue == 0) {
        ui->Entry->setText("Error");
    } else {
        if (calc.addTrigger) {
            solution = calcValue + dblEntryValue;
        } else if (calc.subTrigger) {
            solution = calcValue - dblEntryValue;
        } else if (calc.divTrigger) {
            solution = calcValue / dblEntryValue;
        } else if (calc.mulTrigger) {
            solution = calcValue * dblEntryValue;
        } else if (calc.expTrigger) {
            solution = pow(calcValue, dblEntryValue);
        }
        ui->Entry->setText(QString::number(solution));
    }
}

void MainWindow::CButtonPressed(){
    calcValue = 0.0;
    ui->Entry->setText(QString::number(calcValue));
}

void MainWindow::CEButtonPressed(){
    ui->Entry->setText("");
}

void MainWindow::BackspaceButtonPressed(){
    QString entryValue = ui->Entry->text();
    QString newValue = entryValue.left(entryValue.length() - 1);
    ui->Entry->setText(newValue);
}

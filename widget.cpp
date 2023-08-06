#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEnabled()
{
    if (100 <= money)
        ui->pbCoffee->setEnabled(true);
    else
        ui->pbCoffee->setEnabled(false);

    if (150 <= money)
        ui->pbTea->setEnabled(true);
    else
        ui->pbTea->setEnabled(false);

    if (200 <= money)
        ui->pbMilk->setEnabled(true);
    else
        ui->pbMilk->setEnabled(false);
}

void Widget::changeMoney(int diff)
{
    money += diff;
    changeEnabled();
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString text;
    int n500;
    int n100;
    int n50;
    int n10;

    n500 = money/500;
    money -= 500 * n500;
    n100 = money/100;
    money -= 100 * n100;
    n50 = money/50;
    money -= 50 * n50;
    n10 = money/10;
    money -= 10 * n10;

    text = QString("500 : %1\n 100 : %2\n 50 : %3\n 10 : %4").arg(n500).arg(n100).arg(n50).arg(n10);

    mb.information(nullptr, "Money Reset", text);

    changeMoney(-money);
}


#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    updateMenuButtons();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateMenuButtons()
{
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
    updateMenuButtons();
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
    updateMenuButtons();
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
    updateMenuButtons();
}


void Widget::on_pbCoffee_clicked()
{
    if(money >= 100)
    {
        changeMoney(-100);
        updateMenuButtons();
    }
}


void Widget::on_pbTea_clicked()
{
    if(money >= 150)
    {
        changeMoney(-150);
        updateMenuButtons();
    }
}


void Widget::on_pbMilk_clicked()
{
    if(money >= 200)
    {
        changeMoney(-200);
        updateMenuButtons();
    }
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString msg;
    if (money != 0)
    {
        msg = QString("Returned: %1 won").arg(money);
    }
    else
    {
        msg = QString("Got nothing to return");
    }
    mb.information(nullptr, "Change", msg);
    money = 0;
    updateMenuButtons();
    ui->lcdNumber->display(money);
}


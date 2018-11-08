#include "widget.h"
#include "ui_widget.h"
#include "ui_reset.h"
#include <qstring.h>
#include <qmessagebox.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    money_ = 0;
    ui->setupUi(this);
    set_control();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::set_control()
{
    ui->lcdNumber->display(money_);
    ui->pb_coffee->setEnabled(money_ >= 100);
    ui->pb_tea->setEnabled(money_ >= 150);
    ui->pb_coke->setEnabled(money_ >= 200);
}

void Widget::calc_change()
{
    cnt10_ = 0;
    cnt50_ = 0;
    cnt100_ = 0;
    cnt500_ = 0;
    while(money_ / 500 > 0) {
        money_ -= 500;
        cnt500_++;
    }
    while(money_ / 100 > 0){
        money_ -= 100;
        cnt100_++;
    }
    while(money_ / 50 > 0) {
        money_ -= 50;
        cnt50_++;
    }
    while(money_ > 0) {
        money_ -= 10;
        cnt10_++;
    }
}

void Widget::on_pb500_clicked()
{
    money_ += 500;
    set_control();
}

void Widget::on_pb100_clicked()
{
    money_ += 100;
    set_control();
}

void Widget::on_pb50_clicked()
{
    money_ += 50;
    set_control();
}

void Widget::on_pb10_clicked()
{
    money_ += 10;
    set_control();
}
void Widget::on_pb_coffee_clicked()
{
    money_ -= 100;
    set_control();
}

void Widget::on_pb_tea_clicked()
{
    money_ -= 150;
    set_control();
}

void Widget::on_pb_coke_clicked()
{
    money_ -= 200;
    set_control();
}

void Widget::on_pb_reset_clicked()
{
    QMessageBox resetMsgBox;
    resetMsgBox.setText("The Change\n");
    calc_change();
    resetMsgBox.setInformativeText(QString("500won : %1\n100won : %2\n50won  : %3\n10won  : %4\n").arg(cnt500_).arg(cnt100_).arg(cnt50_).arg(cnt10_));
    resetMsgBox.setEscapeButton(QMessageBox::Ok);

    resetMsgBox.exec();

    ui->lcdNumber->display(money_);
}

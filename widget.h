#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int money_; // member var
    int cnt10_;
    int cnt50_;
    int cnt100_;
    int cnt500_;
    void set_control();
    void calc_change();

private slots:
    void on_pb500_clicked();

    void on_pb100_clicked();

    void on_pb50_clicked();

    void on_pb10_clicked();

    void on_pb_coffee_clicked();

    void on_pb_tea_clicked();

    void on_pb_coke_clicked();

    void on_pb_reset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

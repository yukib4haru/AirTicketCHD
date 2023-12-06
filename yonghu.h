#ifndef YONGHU_H
#define YONGHU_H

#include <QWidget>

namespace Ui {
class yonghu;
}

typedef struct
{
 QString f_num;          //航班号
 QString f_take_city;    //始发地
 QString f_ar_city;      //目的地
 QString f_to_time;      //起飞时间
 QString f_ar_time;      //到达时间
 QString f_price;        //票价
 QString f_money;        //余额

} user;
class yonghu : public QWidget
{
    Q_OBJECT

public:
    explicit yonghu(QWidget *parent = nullptr);
    ~yonghu();

private:
    Ui::yonghu *ui;
};

#endif // YONGHU_H

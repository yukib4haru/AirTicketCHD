#ifndef JIPIAO_H
#define JIPIAO_H
#include<QString>

class jipiao
{
public:
    jipiao();
    void disply();
    QString f_num;          //航班号
    QString f_price;        //票价
    QString f_to_date;      //起飞日期
    QString f_ar_date;      //到达日期
    QString f_to_time;      //起飞时间
    QString f_dis;            //飞行距离
    QString f_type;         //机型
    QString f_take_city;    //起飞城市
    QString f_ar_city;      //目的地
};

#endif // JIPIAO_H

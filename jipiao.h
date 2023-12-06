#ifndef JIPIAO_H
#define JIPIAO_H
#include<QString>

class jipiao
{
public:
    jipiao();
    jipiao(QString num,QString to_date,QString ar_date,QString to_time,QString dis,QString type,QString take_city,QString ar_city);
    void disply();
    QString get_num(){return f_num;}
    QString get_price(){return f_price;}
    QString get_to_date(){return f_to_date;}
    QString get_ar_date(){return f_ar_date;}
    QString get_to_time(){return f_to_time;}
    QString get_dis(){return f_dis;}
    QString get_type(){return f_type;}
    QString get_take_city(){return f_take_city;}
    QString get_ar_city(){return f_ar_city;}
private:
    QString f_num;          //航班号
    QString f_price;        //票价
    QString f_to_date;      //起飞日期
    QString f_ar_date;      //到达日期
    QString f_to_time;      //起飞时间
    QString f_dis;          //飞行距离
    QString f_type;         //机型
    QString f_take_city;    //起飞城市
    QString f_ar_city;      //目的地
};

#endif // JIPIAO_H

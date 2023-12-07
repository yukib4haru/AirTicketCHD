#ifndef JIPIAO_H
#define JIPIAO_H
#include<QString>

class jipiao
{
public:
    jipiao();
    jipiao(QString num,QString to_date,QString ar_date,QString to_time,QString dis,QString type,QString take_city,QString ar_city);
    QString get_num(){return f_num;}
    QString get_price(){return f_price;}
    QString get_to_date(){return f_to_date;}
    QString get_ar_date(){return f_ar_date;}
    QString get_to_time(){return f_to_time;}
    QString get_dis(){return f_dis;}
    QString get_type(){return f_type;}
    QString get_take_city(){return f_take_city;}
    QString get_ar_city(){return f_ar_city;}
    int get_bought(){return f_be_bought;}
    QString get_remain(){return f_remain;}
    int get_true_bought() {return f_true_bought;}

    void true_bought()
    {
        f_true_bought=1;
    }

    void unreal_bought()
    {
        f_true_bought=-1;
    }

    void be_bought()
    {
        f_remain=QString::number(f_remain.toInt()-1);
        f_price=QString::number(f_base_price.toInt()+sought_num/3*15+tourists_num*10-market_competition*100);
        ++sought_num;
        f_be_bought++;
    }
    void un_bought()
    {
        f_remain=QString::number(f_remain.toInt()+1);
        sought_num--;
        f_be_bought--;
        f_price=QString::number(f_base_price.toInt()+sought_num/3*15+tourists_num*10-market_competition*100);
    }
private:
    QString f_num;          //航班号
    QString f_base_price;   //基础票价
    QString f_price;        //修正票价
    QString f_remain;       //剩余票数
    QString f_to_date;      //起飞日期
    QString f_ar_date;      //到达日期
    QString f_to_time;      //起飞时间
    QString f_dis;          //飞行距离
    QString f_type;         //机型
    QString f_take_city;    //起飞城市
    QString f_ar_city;      //目的地
    int f_be_bought;        //是否购买

    int f_true_bought;      //是否已付钱
    //修正票价参数
    int sought_num;         //卖出票数
    int tourists_num;       //游客数量
    int market_competition; //市场竞争力

};

#endif // JIPIAO_H

#include "jipiao.h"
#include<QDebug>
#include<ctime>

jipiao::jipiao()
{

}

jipiao::jipiao(QString num,QString to_date,QString ar_date,QString to_time,QString dis,QString type,QString take_city,QString ar_city)
{
    f_num=num;
    f_to_date=to_date;
    f_ar_date=ar_date;
    f_to_time=to_time;
    f_dis=dis;
    f_type=type;
    f_take_city=take_city;
    f_ar_city=ar_city;
    f_be_bought=0;

    f_true_bought=0;
    f_base_price=QString::number(300+f_dis.toInt()/5/100*100);

    //修正参数
    srand(time(0)+rand());
    sought_num = rand()%70;
    f_remain = QString::number(100-sought_num);
    tourists_num = (rand()%5+5);
    market_competition = rand()%5;
    f_price=QString::number(f_base_price.toInt()+sought_num/10*50+tourists_num*10-market_competition*100);
}
void jipiao::get_zhi(jipiao a)
{

    f_num =a.f_num;
    f_base_price  =a.f_base_price ;
    f_price = a.f_base_price;
    f_remain=a.f_remain;
    f_to_date=a.f_to_date ;
    f_ar_date=a.f_ar_date;
    f_to_time=a.f_to_time;
    f_dis=a.f_dis;
    f_type=a.f_type;
    f_take_city=a.f_take_city;
    f_ar_city=a.f_ar_city;
    f_be_bought=a.f_be_bought;
    f_true_bought=a.f_true_bought;
    sought_num=a.sought_num;
    tourists_num=a.tourists_num;
    market_competition=a.market_competition;
}

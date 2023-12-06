#include "jipiao.h"
#include<QDebug>
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
<<<<<<< HEAD
    f_bool=0;
=======
    f_be_booked=0;

    f_base_price=QString::number(f_dis.toInt()/100*100);

    //修正参数
    srand(time(0)+rand());
    sought_num=rand()%70;
    f_remain=QString::number(100-sought_num);
    tourists_num=(rand()%5+5);
    market_competition=rand()%5;
    f_price=QString::number(f_base_price.toInt()+sought_num/10*10+tourists_num*10-market_competition*10);
>>>>>>> 6606171c7eaa0dca334671d76ce0043e7f172c0b
}



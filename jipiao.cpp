#include "jipiao.h"
#include<QDebug>
jipiao::jipiao()
{

}

jipiao::jipiao(QString num,QString to_date,QString ar_date,QString to_time,QString dis,QString type,QString take_city,QString ar_city)
{
    //基础属性
    f_num=num;
    f_to_date=to_date;
    f_ar_date=ar_date;
    f_to_time=to_time;
    f_dis=dis;
    f_type=type;
    f_take_city=take_city;
    f_ar_city=ar_city;

    f_base_price=QString::number(f_dis.toInt()/100*100);

    //修正参数
    srand(time(0));
    sought_num=rand()%70;
    f_remain=QString::number(100-sought_num);
    tourists_num=(rand()%5+5)*10000000;

}



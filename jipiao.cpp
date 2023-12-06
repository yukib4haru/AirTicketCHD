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
    f_bool=0;
}

void jipiao::disply()
{
    qInfo()<<f_ar_city<<f_ar_date;
}

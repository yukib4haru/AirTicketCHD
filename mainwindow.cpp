#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFile>
#include<QKeyEvent>
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>
#include<QTableWidgetItem>
#include<Qtime>
#include<QDate>
#include<cstring>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f_money=QString::number(1000);
    loadData("D:\\College\\Github\\AirTicketCHD\\AirTicketData\\jipiaoshuju.txt");


    //出发地
    ui->comboBox->insertItem(0,  "所有");
    ui->comboBox->insertItem(1, "北京"); // 出现了11次
    ui->comboBox->insertItem(2, "上海"); // 出现了5次
    ui->comboBox->insertItem(3, "太原"); // 出现了3次
    ui->comboBox->insertItem(4, "西安"); // 出现了4次
    ui->comboBox->insertItem(5, "杭州"); // 出现了3次
    ui->comboBox->insertItem(6, "广州"); // 出现了5次
    ui->comboBox->insertItem(7, "成都"); // 出现了2次
    ui->comboBox->insertItem(8, "南昌"); // 出现了2次
    ui->comboBox->insertItem(9, "深圳"); // 出现了4次
    ui->comboBox->insertItem(10, "香港"); // 出现了4次
    ui->comboBox->insertItem(11, "台北"); // 出现了4次
    ui->comboBox->insertItem(12, "东京"); // 出现了5次
    ui->comboBox->insertItem(13, "巴黎"); // 出现了4次
    ui->comboBox->insertItem(14, "纽约"); // 出现了5次
    ui->comboBox->insertItem(15, "华盛顿"); // 出现了4次


    //到达地
    ui->comboBox_2->insertItem(0,  "所有");
    ui->comboBox_2->insertItem(1, "北京"); // 出现了11次
    ui->comboBox_2->insertItem(2, "上海"); // 出现了5次
    ui->comboBox_2->insertItem(3, "太原"); // 出现了3次
    ui->comboBox_2->insertItem(4, "西安"); // 出现了4次
    ui->comboBox_2->insertItem(5, "杭州"); // 出现了3次
    ui->comboBox_2->insertItem(6, "广州"); // 出现了5次
    ui->comboBox_2->insertItem(7, "成都"); // 出现了2次
    ui->comboBox_2->insertItem(8, "南昌"); // 出现了2次
    ui->comboBox_2->insertItem(9, "深圳"); // 出现了4次
    ui->comboBox_2->insertItem(10, "香港"); // 出现了4次
    ui->comboBox_2->insertItem(11, "台北"); // 出现了4次
    ui->comboBox_2->insertItem(12, "东京"); // 出现了5次
    ui->comboBox_2->insertItem(13, "巴黎"); // 出现了4次
    ui->comboBox_2->insertItem(14, "纽约"); // 出现了5次
    ui->comboBox_2->insertItem(15, "华盛顿"); // 出现了4次

    // 月
    ui->comboBox_3->insertItem(0,"12");
    // 日
    ui->comboBox_4->insertItem(0,"所有");
    for(int i = 8,j = 2; i <= 31; i++)
    {
        ui->comboBox_4->insertItem(j - 1, QString::number(i));
        j++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
//刷新
void MainWindow::refresh()
{
    jp_xiabiao.clear();
    QString arg1 = ui->comboBox->currentText();
    QString arg2 = ui->comboBox_2->currentText();
    QString month = ui->comboBox_3->currentText();
    QString day = ui->comboBox_4->currentText();
    QString date;
    if(day.toInt()<10){date = month+"-0"+day;}
    else{date = month+"-"+day;}
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        bool take_city_flag = 0;
        bool ar_city_flag = 0;
        bool to_date_flag = 0;
        if(arg1=="所有"||arg1==m_jipiao[i]->get_take_city()){take_city_flag=1;}
        if(arg2=="所有"||arg2==m_jipiao[i]->get_ar_city()){ar_city_flag=1;}
        if(date=="12-0所有"||date==m_jipiao[i]->get_to_date()){to_date_flag=1;}
        if(take_city_flag&&ar_city_flag&&to_date_flag)
        {
            jp_xiabiao.push_back(i);
            auto s=new jipiao;
            s=m_jipiao[i];
            int row=ui->looktable->rowCount();
            ui->looktable->insertRow(row);
            ui->looktable->setItem(row,0,new QTableWidgetItem(s->get_num()));
            ui->looktable->setItem(row,1,new QTableWidgetItem(s->get_price()));
            ui->looktable->setItem(row,2,new QTableWidgetItem(s->get_to_date()));
            ui->looktable->setItem(row,3,new QTableWidgetItem(s->get_ar_date()));
            ui->looktable->setItem(row,4,new QTableWidgetItem(s->get_to_time()));
            ui->looktable->setItem(row,5,new QTableWidgetItem(s->get_dis()));
            ui->looktable->setItem(row,6,new QTableWidgetItem(s->get_type()));
            ui->looktable->setItem(row,7,new QTableWidgetItem(s->get_take_city()));
            ui->looktable->setItem(row,8,new QTableWidgetItem(s->get_ar_city()));
        }
    }
}

//读文件
void MainWindow::loadData(const QString &filename)
{


    QFile file (filename);
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo()<<"file is no";
        return;
    }
    //读取数据

    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        auto linedata=stream.readLine().split(" ");
        auto s=new jipiao(linedata[0],linedata[2],linedata[3],linedata[4],linedata[5],linedata[6],linedata[7],linedata[8]," ");
        m_jipiao.push_back(s);

    }
}
void MainWindow::loadData1(const QString &filename)
{

    QFile file (filename);
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qInfo()<<"file is no";
        return;
    }
    //读取数据
    QTextStream stream(&file);
    while(!stream.atEnd())
    {
        try
        {
            auto linedata=stream.readLine().split(" ");
            auto s=new jipiao(linedata[0],linedata[2],linedata[3],linedata[4],linedata[5],linedata[6],linedata[7],linedata[8],linedata[9]);
            h_jipiao.push_back(s);
        }
        catch (std::out_of_range& e) // 如果出现数组越界的异常
        {
            qInfo() << "数组越界：" << e.what(); // 打印异常信息
        }

    }

}
void MainWindow::on_pushButton_clicked()
{
    //点击转换页面1
    ui->stackedWidget->setCurrentWidget(ui->page);
    refresh();
}

void MainWindow::on_pushButton_2_clicked()
{
    //点击转换页面2
    loadData1("D:\\study\\qtgode\\zuoye\\AirTicketCHD\\lishi.txt");

   ui->stackedWidget->setCurrentWidget(ui->page_2);
   ui->my_table->clearContents();
   ui->my_table->setRowCount(0);
   int n=h_jipiao.size();
   for(int i=n-1;i>=0;i--)
   {
       qDebug()<<n;
       ui->looktable_2->clearContents();
       ui->looktable_2->setRowCount(0);
           auto s=new jipiao;
           s=h_jipiao[i];
           int row=ui->my_table->rowCount();
           ui->my_table->insertRow(row);
           ui->my_table->setItem(row,0,new QTableWidgetItem("sxd"));
           ui->my_table->setItem(row,1,new QTableWidgetItem(s->get_num()));
           ui->my_table->setItem(row,6,new QTableWidgetItem(s->get_price()));
           ui->my_table->setItem(row,5,new QTableWidgetItem(s->get_ar_date()));
           ui->my_table->setItem(row,4,new QTableWidgetItem(s->get_to_time()));
           ui->my_table->setItem(row,2,new QTableWidgetItem(s->get_take_city()));
           ui->my_table->setItem(row,3,new QTableWidgetItem(s->get_ar_city()));
           ui->my_table->setItem(row,7,new QTableWidgetItem(s->get_wd()));
   }

}


void MainWindow::on_pushButton_3_clicked()
{
    //点击转换页面3
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    ui->looktable_2->clearContents();
    ui->looktable_2->setRowCount(0);
    ui->M_money->setText(get_money());
    int n=f_jipiao.size();
    for(int i=0;i<n;i++)
    {
        qDebug()<<n;

        auto s=new jipiao;
        s=f_jipiao[i];
        int row=ui->looktable_2->rowCount();
        ui->looktable_2->insertRow(row);
        ui->looktable_2->setItem(row,0,new QTableWidgetItem(s->get_num()));
        ui->looktable_2->setItem(row,1,new QTableWidgetItem(s->get_price()));
        ui->looktable_2->setItem(row,2,new QTableWidgetItem(s->get_to_date()));
        ui->looktable_2->setItem(row,3,new QTableWidgetItem(s->get_ar_date()));
        ui->looktable_2->setItem(row,4,new QTableWidgetItem(s->get_to_time()));
        ui->looktable_2->setItem(row,5,new QTableWidgetItem(s->get_dis()));
        ui->looktable_2->setItem(row,6,new QTableWidgetItem(s->get_type()));
        ui->looktable_2->setItem(row,7,new QTableWidgetItem(s->get_take_city()));
        ui->looktable_2->setItem(row,8,new QTableWidgetItem(s->get_ar_city()));
        if(f_jipiao[i]->get_true_bought()==1)
        {
            ui->looktable_2->setItem(row,9,new QTableWidgetItem("是"));
        }
        else
        {
            ui->looktable_2->setItem(row,9,new QTableWidgetItem("否"));
        }



    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    qDebug()<<arg1;
    refresh();
}

void MainWindow::on_comboBox_2_activated(const QString &arg2)
{
    qDebug()<<arg2;
    refresh();
}

void MainWindow::on_comboBox_activated(int index)
{
    qDebug()<<index;
    refresh();
}

void MainWindow::on_pushButton_5_clicked()//订票信息的机票查询
{

    ui->looktable_2->clearContents();
    ui->looktable_2->setRowCount(0);
    int n=f_jipiao.size();
    QString m_time=ui->lineEdit->text();
    QString m_take_city=ui->lineEdit_3->text();
    QString m_ar_city=ui->lineEdit_3->text();
    QString m_num=ui->lineEdit_4->text();
    QString temp=0,temp1=0;
    if(n==0)
    {
        QMessageBox msgBox;
        msgBox.setText("订单列表为空");
        msgBox.setWindowTitle("查询错误");
        msgBox.exec();
    }
    else
    {
        if(m_time!=nullptr)
        {
            temp=m_time;
            for(int i=0;i<n;i++)
            {
                if(f_jipiao[i]->get_to_time()==temp)
                {
                    auto s=new jipiao;
                    s=f_jipiao[i];
                    int row=ui->looktable_2->rowCount();
                    ui->looktable_2->insertRow(row);
                    ui->looktable_2->setItem(row,0,new QTableWidgetItem(s->get_num()));
                    ui->looktable_2->setItem(row,1,new QTableWidgetItem(s->get_price()));
                    ui->looktable_2->setItem(row,2,new QTableWidgetItem(s->get_to_date()));
                    ui->looktable_2->setItem(row,3,new QTableWidgetItem(s->get_ar_date()));
                    ui->looktable_2->setItem(row,4,new QTableWidgetItem(s->get_to_time()));
                    ui->looktable_2->setItem(row,5,new QTableWidgetItem(s->get_dis()));
                    ui->looktable_2->setItem(row,6,new QTableWidgetItem(s->get_type()));
                    ui->looktable_2->setItem(row,7,new QTableWidgetItem(s->get_take_city()));
                    ui->looktable_2->setItem(row,8,new QTableWidgetItem(s->get_ar_city()));
                }

            }
        }
        else if(m_take_city!=nullptr&&m_ar_city!=nullptr)
        {
            temp=m_take_city;
            temp1=m_ar_city;
            for(int i=0;i<n;i++)
            {
                if(f_jipiao[i]->get_take_city()==temp&&f_jipiao[i]->get_ar_city()==temp1)
                {
                    auto s=new jipiao;
                    s=f_jipiao[i];
                    int row=ui->looktable_2->rowCount();
                    ui->looktable_2->insertRow(row);
                    ui->looktable_2->setItem(row,0,new QTableWidgetItem(s->get_num()));
                    ui->looktable_2->setItem(row,1,new QTableWidgetItem(s->get_price()));
                    ui->looktable_2->setItem(row,2,new QTableWidgetItem(s->get_to_date()));
                    ui->looktable_2->setItem(row,3,new QTableWidgetItem(s->get_ar_date()));
                    ui->looktable_2->setItem(row,4,new QTableWidgetItem(s->get_to_time()));
                    ui->looktable_2->setItem(row,5,new QTableWidgetItem(s->get_dis()));
                    ui->looktable_2->setItem(row,6,new QTableWidgetItem(s->get_type()));
                    ui->looktable_2->setItem(row,7,new QTableWidgetItem(s->get_take_city()));
                    ui->looktable_2->setItem(row,8,new QTableWidgetItem(s->get_ar_city()));
                }
            }


        }
        else if(m_num!=nullptr)
        {
            ui->looktable_2->clearContents();
            ui->looktable_2->setRowCount(0);
            temp=m_num;
            for(int i=0;i<n;i++)
            {
                if(f_jipiao[i]->get_num()==temp)
                {
                    auto s=new jipiao;
                    s=f_jipiao[i];
                    int row=ui->looktable_2->rowCount();
                    ui->looktable_2->insertRow(row);
                    ui->looktable_2->setItem(row,0,new QTableWidgetItem(s->get_num()));
                    ui->looktable_2->setItem(row,1,new QTableWidgetItem(s->get_price()));
                    ui->looktable_2->setItem(row,2,new QTableWidgetItem(s->get_to_date()));
                    ui->looktable_2->setItem(row,3,new QTableWidgetItem(s->get_ar_date()));
                    ui->looktable_2->setItem(row,4,new QTableWidgetItem(s->get_to_time()));
                    ui->looktable_2->setItem(row,5,new QTableWidgetItem(s->get_dis()));
                    ui->looktable_2->setItem(row,6,new QTableWidgetItem(s->get_type()));
                    ui->looktable_2->setItem(row,7,new QTableWidgetItem(s->get_take_city()));
                    ui->looktable_2->setItem(row,8,new QTableWidgetItem(s->get_ar_city()));
                }
            }

        }
        else
        {
            for(int i=0;i<n;i++)
            {
                auto s=new jipiao;
                s=f_jipiao[i];
                int row=ui->looktable_2->rowCount();
                ui->looktable_2->insertRow(row);
                ui->looktable_2->setItem(row,0,new QTableWidgetItem(s->get_num()));
                ui->looktable_2->setItem(row,1,new QTableWidgetItem(s->get_price()));
                ui->looktable_2->setItem(row,2,new QTableWidgetItem(s->get_to_date()));
                ui->looktable_2->setItem(row,3,new QTableWidgetItem(s->get_ar_date()));
                ui->looktable_2->setItem(row,4,new QTableWidgetItem(s->get_to_time()));
                ui->looktable_2->setItem(row,5,new QTableWidgetItem(s->get_dis()));
                ui->looktable_2->setItem(row,6,new QTableWidgetItem(s->get_type()));
                ui->looktable_2->setItem(row,7,new QTableWidgetItem(s->get_take_city()));
                ui->looktable_2->setItem(row,8,new QTableWidgetItem(s->get_ar_city()));
            }
        }

    }
}

void MainWindow::on_pushButton_10_clicked()
{
    QString money=get_money();
    QString m_note=0;
    int m_row = ui->looktable_2->currentRow();
    if(m_row==-1||f_jipiao[m_row]->get_true_bought()==1)
    {
        QMessageBox msgBox;
        msgBox.setText("您还未选择要购买的机票或机票已购买");
        msgBox.setWindowTitle("购票错误");
        msgBox.exec();
    }
    else
    {
        money=QString::number(money.toInt()-f_jipiao[m_row]->get_price().toInt());
        ui->M_money->setText(money);
        set_money(money);
        f_jipiao[m_row]->true_bought();
        ui->looktable_2->setItem(m_row,9,new QTableWidgetItem("是"));
        QString str = "sxd";
        QFile file("D:\\study\\qtgode\\zuoye\\AirTicketCHD\\lishi.txt"); //打开文件，不存在则创建
        file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
        QTextStream stream(&file); //创建一个QTextStream对象
        //使用<<操作符将不同的字符串写入文件中，用空格或换行符分隔
        stream  << f_jipiao[m_row]->get_num() << " " <<"100" << " " << f_jipiao[m_row]->get_to_date() << " " << f_jipiao[m_row]->get_ar_date()<<" "<< f_jipiao[m_row]->get_to_time() <<
                   " "<< f_jipiao[m_row]->get_price() <<" " <<f_jipiao[m_row]->get_type()<<" "<<f_jipiao[m_row]->get_take_city() <<" " <<f_jipiao[m_row]->get_ar_city()<<" "<<f_jipiao[m_row]->get_zhuangtai()<< "\n";
        file.close(); //关闭文件
    }


}


void MainWindow::on_pushButton_9_clicked()
{
    int m_row = ui->looktable_2->currentRow();
    if(m_row==-1)
    {
        QMessageBox msgBox;
        msgBox.setText("您还未选择要删除的机票");
        msgBox.setWindowTitle("删除错误");
        msgBox.exec();
    }
    else
    {
        if(f_jipiao[m_row]->get_true_bought()==1||f_jipiao[m_row]->get_true_bought()==1)
        {
            QMessageBox msgBox;
            msgBox.setText("已购买的机票不能删除或者退款的无法删除");
            msgBox.setWindowTitle("删除错误");
            msgBox.exec();
        }
        else
        {
            f_jipiao[m_row]->unreal_bought();
            f_jipiao[m_row]->un_bought();
            if (m_row >= 0 && m_row < f_jipiao.size())
            {
                f_jipiao.removeAt(m_row);
                ui->looktable_2->removeRow(m_row);
            }
        }

    }
}

void MainWindow::on_comboBox_2_activated(int index)
{
    qDebug()<<index;
    refresh();
}

void MainWindow::on_comboBox_3_activated(int index)
{
    qDebug()<<index;
    refresh();
}


void MainWindow::on_comboBox_4_activated(int index)
{
    qDebug()<<index;
    refresh();
}

//预定
void MainWindow::on_pushButton_6_clicked()
{
    int row = ui->looktable->currentRow();
    qInfo()<<m_jipiao.size();
    qInfo()<<"row:"<<row;
    if (row == -1)
    {
        return ;
    }
    else
    {
        refresh();
        int n=jp_xiabiao[row];
        qInfo()<<"n"<<n;
        m_jipiao[n]->be_bought();
        auto s=new jipiao;
        s->get_zhi(*m_jipiao[n]);
        f_jipiao.push_back(s);
    }
    //QMessageBox msgBox;
    //msgBox.setText("购票成功！");
    //msgBox.setWindowTitle("恭喜");
    //msgBox.exec();
    jp_xiabiao.clear();
}
//退款
void MainWindow::on_tuikuan_button_clicked()
{
    int money;

    int row = ui->looktable_2->currentRow();
    money=f_jipiao[row]->get_price().toInt();
    if(row==-1||f_jipiao[row]->get_true_bought()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("机票已退款或未选中或未支付");
        msgBox.setWindowTitle("退款失败");
        msgBox.exec();
    }
    else
    {

        // 获取当前的时间
        QTime currentTime = QTime::currentTime();
        QDate date = QDate::currentDate();
        // 获取当前的小时数
        int currentHour = currentTime.hour();
        int day = date.day();
        int n=(f_jipiao[row]->get_ar_date().right(2).toInt());
        int m=(f_jipiao[row]->get_to_time().left(2).toInt());
        int sum=(n-day)*24-currentHour+m;

        if(sum>3*24)
        {
            qInfo()<<"1"<<n<<"+"<<m;
            int s=f_money.toInt();
            s=s+money*0.95;
            qInfo()<<money*0.95;
            f_money=QString::number(s);
            ui->M_money->setText(get_money());
            f_jipiao[row]->flase_bought();
            ui->looktable_2->setItem(row,9,new QTableWidgetItem("已退款"));
        }
        else
        {
            qInfo()<<n<<"+"<<m;
            int d=sum/24;
            int s=f_money.toInt();
            switch ( d)
            {
            case 0:
                s=s+money*0.7;
                f_money=QString::number(s);
                ui->M_money->setText(get_money());
                f_jipiao[row]->flase_bought();
                ui->looktable_2->setItem(row,9,new QTableWidgetItem("已退款"));
                break;
            case 1:
                s=s+money*0.85;
                f_money=QString::number(s);
                ui->M_money->setText(get_money());
                f_jipiao[row]->flase_bought();
                ui->looktable_2->setItem(row,9,new QTableWidgetItem("已退款"));
                break;
            case 2:
                s=s+money*0.90;
                f_money=QString::number(s);
                ui->M_money->setText(get_money());
                f_jipiao[row]->flase_bought();
                ui->looktable_2->setItem(row,9,new QTableWidgetItem("已退款"));
                break;
            default:
                QMessageBox msgBox;
                msgBox.setText("机票失效或已经使用");
                msgBox.setWindowTitle("退款失败");
                msgBox.exec();
                break;
            }
        }
        QString str = "sxd";
        QFile file("D:\\study\\qtgode\\zuoye\\AirTicketCHD\\lishi.txt"); //打开文件，不存在则创建
       file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
        QTextStream stream(&file); //创建一个QTextStream对象
        //使用<<操作符将不同的字符串写入文件中，用空格或换行符分隔
                                                                                        //FM9102 100 12-12 12-12 21:35 1178 波音737 北京 上海

        stream  << f_jipiao[row]->get_num() << " " <<"100" << " " << f_jipiao[row]->get_to_date() << " " << f_jipiao[row]->get_ar_date()<<" "<< f_jipiao[row]->get_to_time() <<
                   " "<< f_jipiao[row]->get_price() <<" " <<f_jipiao[row]->get_type()<<" "<<f_jipiao[row]->get_take_city() <<" " <<f_jipiao[row]->get_ar_city()<<" "<<f_jipiao[row]->get_zhuangtai()<< "\n";
        file.close(); //关闭文件
    }


}

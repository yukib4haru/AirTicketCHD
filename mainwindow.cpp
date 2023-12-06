#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFile>
#include<QKeyEvent>
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>
#include<QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadData("E:\\asd\\AirTicketCHD\\jipiaoshuju.txt");
    ui->comboBox->insertItem(0,  "a");
    ui->comboBox->insertItem(1,  "b");
    ui->comboBox->insertItem(2,  "c");
    ui->comboBox->insertItem(3,  "d");


    ui->comboBox->insertItem(0,  "北京");
    ui->comboBox->insertItem(1,  "西安");
    ui->comboBox->insertItem(2,  "太原");
    ui->comboBox->insertItem(3,  "成都");

    ui->comboBox->insertItem(4,  "e");
    ui->comboBox->insertItem(5,  "f");
    ui->comboBox->insertItem(6,  "g");
    ui->comboBox->insertItem(7,  "h");
    //到达地
    ui->comboBox_2->insertItem(0,  "上海");
    ui->comboBox_2->insertItem(1,  "西安");
    ui->comboBox_2->insertItem(2,  "杭州");
    ui->comboBox_2->insertItem(3,  "广州");
    ui->comboBox_2->insertItem(4,  "太原");
    ui->comboBox_2->insertItem(5,  "南昌");
    ui->comboBox_2->insertItem(6,  "g");
    ui->comboBox_2->insertItem(7,  "h");   
    // 月
    ui->comboBox_3->insertItem(0,  "12");
    // 日
    for(int i = 6,j = 1; i <= 31; i++)
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
    QString arg1 = ui->comboBox->currentText();
    QString arg2 = ui->comboBox_2->currentText();
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        if(arg1==m_jipiao[i]->get_take_city()&&arg2==m_jipiao[i]->get_ar_city())
        {
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
        auto s=new jipiao(linedata[0],linedata[2],linedata[3],linedata[4],linedata[5],linedata[6],linedata[7],linedata[8]);
        m_jipiao.push_back(s);
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
    ui->stackedWidget->setCurrentWidget(ui->page_2);


    //初始化数据
    user data1 = {"1","東京","大阪","02.03.2004","03.03.2004","1554","114514"};
    user data2 = {"2","大阪","東京","03.03.2004","04.03.2004","1554","112960"};
    user data[10] = {data1,data2};

    //建立表格
    tableView = new QTableView(ui->page_2);
    tableView->move(0,0);
    // 设置表格视图大小
    this->setFixedSize(1600,900);
    tableView->setFixedSize(1600, 900);
    // 创建数据模型
    model = new QStandardItemModel(0,7,this);
    model->setHorizontalHeaderLabels({"航班号","始发地","目的地","起飞时间","到达时间","票价","余额"});

    // 自适应所有列，让它布满空间
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // 加载共length行数据，并每行有4列数据
    for (int i = 0; i < 2; i++)
    {
        // 加载数据
        model->setItem(i, 0, new QStandardItem(QString(data[i].f_num)));
        model->setItem(i, 1, new QStandardItem(QString(data[i].f_take_city)));
        model->setItem(i, 2, new QStandardItem(QString(data[i].f_ar_city)));
        model->setItem(i, 3, new QStandardItem(QString(data[i].f_to_time)));
        model->setItem(i, 4, new QStandardItem(QString(data[i].f_ar_time)));
        model->setItem(i, 5, new QStandardItem(QString(data[i].f_price)));
        model->setItem(i, 6, new QStandardItem(QString(data[i].f_money)));

    }qDebug()<<"huihui";
    // 设置表格视图数据
    tableView->setModel(model);
    // 设置只读模型
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSortingEnabled(true); // 设置tableView的排序功能为启用
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 设置tableView的选择模式为按行选择

    tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); // 设置tableView的水平表头的背景颜色为天蓝色

    // 显示表格
    tableView->show();
    }
    
//     tableView->setModel(model);     // 设置表格视图数据
//     tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);      // 设置只读模型
//     tableView->setSortingEnabled(true);     // 设置tableView的排序功能为启用
//     tableView->setSelectionBehavior(QAbstractItemView::SelectRows);   // 设置tableView的选择模式为按行选择
//     tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");   // 设置tableView的水平表头的背景颜色为天蓝色
//     tableView->show();      // 显示表格

// }

void MainWindow::on_pushButton_3_clicked()
{
    //点击转换页面3
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    int n=m_jipiao.size();
    for(int i=0;i<n;i++)
    {
        if(1==m_jipiao[i]->get_booked())
        {
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

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QString arg2 = ui->comboBox_2->currentText();
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        if(arg1==m_jipiao[i]->get_take_city()&&arg2==m_jipiao[i]->get_ar_city())
        {
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

void MainWindow::on_comboBox_2_activated(const QString &arg2)
{
    QString arg1 = ui->comboBox->currentText(); // 使用索引获取当前选中的文本
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        if(arg1==m_jipiao[i]->get_take_city()&&arg2==m_jipiao[i]->get_ar_city())
        {
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

void MainWindow::on_comboBox_activated(int index)
{
    QString arg1 = ui->comboBox->itemText(index); // 使用索引获取当前选中的文本
    QString arg2 = ui->comboBox_2->currentText();
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        if(arg1==m_jipiao[i]->get_take_city()&&arg2==m_jipiao[i]->get_ar_city())
        {
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

void MainWindow::on_pushButton_5_clicked()
{

    ui->looktable_2->clearContents();
    ui->looktable_2->setRowCount(0);
    int n=m_jipiao.size();
    QString m_time=ui->lineEdit->text();
    QString m_take_city=ui->lineEdit_2->text();
    QString m_ar_city=ui->lineEdit_3->text();
    QString m_num=ui->lineEdit_4->text();
    QString temp=0,temp1=0;
    if(m_time!=nullptr)
    {
        temp=m_time;
        for(int i=0;i<n;i++)
        {
            if(temp==m_jipiao[i]->get_to_time())
            {
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
    else if(m_take_city!=nullptr&&m_ar_city!=nullptr)
    {
        temp=m_take_city;
        temp1=m_ar_city;
        for(int i=0;i<n;i++)
        {
            if(temp==m_jipiao[i]->get_take_city()&&temp1==m_jipiao[i]->get_ar_city())
            {
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
    else if(m_num!=nullptr)
    {
        temp=m_num;
        for(int i=0;i<n;i++)
        {
            if(temp==m_jipiao[i]->get_num())
            {
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

}


void MainWindow::on_comboBox_2_activated(int index)
{
    QString arg1 = ui->comboBox->currentText(); // 使用索引获取当前选中的文本
    QString arg2 = ui->comboBox_2->itemText(index);
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        if(arg1==m_jipiao[i]->get_take_city()&&arg2==m_jipiao[i]->get_ar_city())
        {
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
void MainWindow::on_pushButton_6_clicked()
{
    int row = ui->looktable->currentRow();

  qInfo()<<m_jipiao.size();

    if (row == -1)
    {
        return ;

    }
    else
    {
        m_jipiao[row]->dev_remain();
        m_jipiao[row]->add_booked();
        refresh();
    }
    qInfo()<<m_jipiao[row]->get_remain();

}

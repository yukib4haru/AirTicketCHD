#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QKeyEvent>
#include<QMessageBox>
#include<QTextStream>
#include<QDebug>
#include <QTableWidget>
#include<QTableWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadData("D:\\QTProject\\GitHub\\AirTicketCHD\\jipiaoshuju.txt");
=======
=======
>>>>>>> 6606171c7eaa0dca334671d76ce0043e7f172c0b

    //让鼠标和行号链接
    loadData("E:\\asd\\AirTicketCHD\\jipiaoshuju.txt");

<<<<<<< HEAD
>>>>>>> 6606171c7eaa0dca334671d76ce0043e7f172c0b
=======
>>>>>>> 6606171c7eaa0dca334671d76ce0043e7f172c0b
    for(auto s:m_jipiao)
    { //获取行号
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

    ui->comboBox->insertItem(0,  "a");
    ui->comboBox->insertItem(1,  "b");
    ui->comboBox->insertItem(2,  "c");
    ui->comboBox->insertItem(3,  "d");
    ui->comboBox->insertItem(4,  "e");
    ui->comboBox->insertItem(5,  "f");
    ui->comboBox->insertItem(6,  "g");
    ui->comboBox->insertItem(7,  "h");

    //第二表
    ui->comboBox_2->insertItem(0,  "a");
    ui->comboBox_2->insertItem(1,  "b");
    ui->comboBox_2->insertItem(2,  "c");
    ui->comboBox_2->insertItem(3,  "d");
    ui->comboBox_2->insertItem(4,  "e");
    ui->comboBox_2->insertItem(5,  "f");
    ui->comboBox_2->insertItem(6,  "g");
    ui->comboBox_2->insertItem(7,  "h");
}

MainWindow::~MainWindow()
{
    delete ui;
}
//获得鼠标行号

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
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    for(auto s:m_jipiao)
    { //获取行号
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

void MainWindow::on_pushButton_2_clicked()
{
    //点击转换页面2
    ui->stackedWidget->setCurrentWidget(ui->page_2);
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

    }
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

void MainWindow::on_pushButton_3_clicked()
{
    //点击转换页面3

    ui->stackedWidget->setCurrentWidget(ui->page_3);
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        if(arg1==m_jipiao[i]->get_take_city())
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

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    ui->looktable->clearContents();
    ui->looktable->setRowCount(0);
    int n=m_jipiao.size();
    for(int i=0;i<n;++i)
    {
        if(arg1==m_jipiao[i]->get_ar_city())
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

void MainWindow::on_pushButton_4_clicked()
{

    int row = ui->looktable->currentRow();
  qInfo()<<row;
    // 判断是否有行被选中
    /*if (row == -1)
    {
        return ;

    }
    else
    {
        m_jipaio[row]->ad_sought();
        m_jipaio[row]->ad_booked();
    }*/

}

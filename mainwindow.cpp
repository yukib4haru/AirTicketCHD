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
    //让鼠标和行号链接
    loadData("D:\\study\\sxd\\AirTicketCHD\\jipiaoshuju.txt");
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

    // 判断是否有行被选中
    if (row == -1)
    {
        return ;
        // 删除选中的行 tableWidget->removeRow(row);
    }
    qInfo()<<row;
}

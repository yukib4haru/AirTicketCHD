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
    loadData("D://College//QTProject//zuoye//jipiaoshuju.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
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
    auto s=new jipiao;
    s->f_num=linedata[0];
    s->f_price=linedata[1];
    s->f_to_date=linedata[2];
    s->f_ar_date=linedata[3];
    s->f_to_time=linedata[4];
    s->f_dis=linedata[5];
    s->f_type=linedata[6];
    s->f_take_city=linedata[7];
    s->f_ar_city=linedata[8];
    m_jipiao.push_back(s);

 }
for(auto s:m_jipiao)
 {
    s->disply();
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

      ui->looktable->setItem(row,0,new QTableWidgetItem(s->f_num));
      ui->looktable->setItem(row,1,new QTableWidgetItem(s->f_price));
      ui->looktable->setItem(row,2,new QTableWidgetItem(s->f_to_date));
      ui->looktable->setItem(row,3,new QTableWidgetItem(s->f_ar_date));
      ui->looktable->setItem(row,4,new QTableWidgetItem(s->f_to_time));
      ui->looktable->setItem(row,5,new QTableWidgetItem(s->f_dis));
      ui->looktable->setItem(row,6,new QTableWidgetItem(s->f_type));
      ui->looktable->setItem(row,7,new QTableWidgetItem(s->f_take_city));
      ui->looktable->setItem(row,8,new QTableWidgetItem(s->f_ar_city));
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


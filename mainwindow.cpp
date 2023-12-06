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
    loadData("E:\\project\\QT Project\\zuoye\\jipiaoshuju.txt");
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
    auto s=new jipiao(linedata[0],linedata[2],linedata[3],linedata[4],linedata[5],linedata[6],linedata[7],linedata[8]);
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


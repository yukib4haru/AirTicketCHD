#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jipiao.h"
#include "yonghu.h"
#include <QList>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QLineEdit>

typedef struct
{
 QString f_num;          //航班号
 QString f_take_city;    //始发地
 QString f_ar_city;      //目的地
 QString f_to_time;      //起飞时间
 QString f_ar_time;      //到达时间
 QString f_price;        //票价
 QString f_money;        //余额

} user;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //加载数据
    void loadData(const QString& filename);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_pushButton_6_clicked();
	
    void refresh();

    void on_comboBox_3_activated(int index);

    void on_comboBox_4_activated(int index);

private:
    Ui::MainWindow *ui;
    QList<jipiao*> m_jipiao;
    QTableView *tableView;
    QStandardItemModel* model;
    QList<jipiao*>m_jipaio;
    QList<int>jp_xiabiao;
    QList<jipiao*>f_jipiao;


};

#endif // MAINWINDOW_H

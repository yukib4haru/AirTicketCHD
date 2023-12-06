#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"jipiao.h"
#include"yonghu.h"
#include<QList>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QInputDialog>
#include <QLineEdit>


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

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QList<jipiao*> m_jipiao;
    QTableView *tableView;
    QStandardItemModel* model;
    QList<jipiao*>m_jipaio;

    //初始化数据
    user data1 = {"1","東京","大阪","02.03.2004","03.03.2004","1554","114514"};
};

#endif // MAINWINDOW_H

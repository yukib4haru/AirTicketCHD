#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"jipiao.h"
#include <QList>
namespace Ui {
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

private:
    Ui::MainWindow *ui;
    QList<jipiao*>m_jipiao;
};

#endif // MAINWINDOW_H

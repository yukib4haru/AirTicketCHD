#include "yonghu.h"
#include "ui_yonghu.h"

yonghu::yonghu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yonghu)
{
    ui->setupUi(this);
}

yonghu::~yonghu()
{
    delete ui;
}

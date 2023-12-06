#include "yonghu.h"
#include "ui_yonghu.h"
#include "User.h"


yonghu::yonghu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yonghu)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");

    this->setAutoFillBackground(true);
    //获得widget的palette
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/background.png").scaled(  // 缩放背景图.
                this->size(),Qt::IgnoreAspectRatio,        //不限制原图片的长宽比
                Qt::SmoothTransformation)));               // 使用平滑的缩放方式
    this->setPalette(palette);


    this->setGeometry(750,300,400,300);
    this->setFixedSize(400,300);

    btnA = new QPushButton(this);
    btnA->setText("登录");// 设置按钮的文本
    btnA->setGeometry(65, 200, 100, 50);   // 设置按钮的位置和大小
    btnA->setFlat(true);
    btnA->setStyleSheet("background-color: rgb(255,250,250);color: rgb(0,255,0);");
    btnA->show();

    btnB = new QPushButton(this);
    btnB->setText("注册");// 设置按钮的文本
    btnB->setGeometry(225, 200, 100, 50);   // 设置按钮的位置和大小
    btnB->setFlat(true);
    btnB->setStyleSheet("background-color: rgb(255,250,250);color: rgb(0,0,0);");
    btnB->show();

    tel_num = new QLabel(this);
    tel_num->setText("Tel_Num:");
    tel_num->setGeometry(50, 45, 68, 25);
    tel_num->setStyleSheet("QLabel{color: rgb(255,0,0);}");
    password = new QLabel(this);
    password->setText("PassWord:");
    password->setGeometry(50, 105, 68, 25);
    password->setStyleSheet("QLabel{color: rgb(255,0,0);}");

    tel_num_lineEdit = new QLineEdit(this);
    tel_num_lineEdit->setGeometry(160, 45, 170, 30);
    password_lineEdit = new QLineEdit(this);
    password_lineEdit->setGeometry(160, 105, 170, 30);

    //注册
    connect(this->btnB,&QPushButton::clicked,[this](){
        if(this->tel_num_lineEdit->text().isEmpty() || this->password_lineEdit->text().isEmpty())
        {QMessageBox::critical(this,"警告","tel_num或password不能为空");
            return;}
        else{
            UserInfo user = {this->tel_num_lineEdit->text(),this->password_lineEdit->text()};
            User* call = new User();
            int ret = call->registerUser(user);
            switch (ret)
            {
            case 0:
                QMessageBox::information(this,"信息","注册成功！");
                break;
            case 1:
                QMessageBox::question(this,"信息","注册失败");
                break;
            }

        }
    });

    //登录
    //Lambda 表达式
    connect(this->btnA,&QPushButton::clicked,[this](){
        if(this->tel_num_lineEdit->text().isEmpty() || this->password_lineEdit->text().isEmpty())
        {
            QMessageBox::critical(this,"警告","tel_num或password不能为空");
            return;
        }
        else
        {
            UserInfo user = {this->tel_num_lineEdit->text(),this->password_lineEdit->text()};
            User* call = new User();

            int ret = call->judgeTel_numAndPassword(user);//验证tel_num和password

            switch (ret)
            {
            case 0:
            { QMessageBox::information(this,"信息","登录成功！");
                this->close();

                MainWindow *w = new MainWindow;
                w->show();

                break;}
            case 1:
                QMessageBox::question(this,"信息","登录失败");
                break;
            case 2:
                QMessageBox::critical(this,"信息","账号或密码错误");
                break;
            case 3:
                QMessageBox::critical(this,"信息","不能以tel_num或password来作为账号密码");
                break;
            }
        }
    });

}



yonghu::~yonghu()
{
    delete ui;
}

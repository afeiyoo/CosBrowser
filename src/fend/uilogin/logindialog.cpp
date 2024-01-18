#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>
#include <QMouseEvent>
#include <QString>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //取消默认标题栏
    this->setWindowFlags(Qt::CustomizeWindowHint);
    //设置图标
    QPixmap pixmap("F:/030_Study/Code/CosBrowser/u-logoa.jpg");
    ui->labelLogo->setPixmap(pixmap.scaled(ui->labelLogo->size()));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        m_start = event->pos(); //返回的是相对于当前控件原点的位置
    }
    QDialog::mousePressEvent(event);    //调用基类的处理函数
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton){
        //鼠标偏移量+控件原点位置
        QPoint targetPos = event->pos() - m_start + pos();
        this->move(targetPos);
    }
    QDialog::mouseMoveEvent(event);
}

void LoginDialog::on_btnClose_clicked()
{
    reject();
}


void LoginDialog::on_btnLogin_clicked()
{
    //进行登录信息验证
    if(ui->lineSecretID->text().trimmed() == "zhangsan" &&
        ui->lineSecretKey->text().trimmed() == "123"){
        accept();   //关闭自身，并发送accepted信号
    }else{
        QMessageBox::warning(this, QString::fromLocal8Bit("登录失败"),
                             QString::fromLocal8Bit("请检查SecretID或者SecretKey是否正确"));
    }
}


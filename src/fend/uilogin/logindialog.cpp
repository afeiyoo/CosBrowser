#include "logindialog.h"
#include "ui_logindialog.h"
#include "src/bend/man/mandb.h"

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

    //Deprecated 2024-01-20 改用qss文件进行设置
    // QPixmap pixmap("F:/030_Study/Code/CosBrowser/u-logoa.jpg");
    // ui->labelLogo->setPixmap(pixmap.scaled(ui->labelLogo->size()));

    //lineSecretKey控件安装事件过滤器
    ui->lineSecretKey->installEventFilter(this);

    // style是一个自定义属性，用于属性选择器
    ui->labelTitle->setProperty("style", "h3");
    ui->labelSecretID->setProperty("style", "h4");
    ui->labelLoginName->setProperty("style", "h4");
    ui->labelSecretKey->setProperty("style", "h4");
    ui->labelRemark->setProperty("style", "h4");
    ui->btnClose->setProperty("style", "h4");
    ui->btnLogin->setProperty("style", "h4");
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

bool LoginDialog::eventFilter(QObject *watched, QEvent *event)
{
    //watched 需要关注的控件对象
    //event 传递给事件对象的事件
    if(watched == ui->lineSecretKey){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if(keyEvent->modifiers() == Qt::ControlModifier){
                if(keyEvent->key() == Qt::Key_C || keyEvent->key() == Qt::Key_V)
                    return true;    //停止事件传递
            }
        }
    }

    return QDialog::eventFilter(watched, event);
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
        accept();   //关闭自身，并发送accepted信号(显示主窗口)

        if(ui->checkSaveSection->isChecked()){
            //保存登录信息
            MDB->saveLoginInfo(
                ui->lineLoginName->text(),
                ui->lineSecretID->text(),
                ui->lineSecretKey->text(),
                ui->lineRemark->text()
            );
        }else{
            //删除登录信息
            MDB->removeLoginInfo(ui->lineSecretID->text());
        }
    }else{
        QMessageBox::warning(this, QString::fromLocal8Bit("登录失败"),
                             QString::fromLocal8Bit("请检查SecretID或者SecretKey是否正确"));
    }
}


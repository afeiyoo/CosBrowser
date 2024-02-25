#include "logindialog.h"
#include "ui_logindialog.h"
#include "src/bend/man/mandb.h"
#include "src/bend/gateway.h"
#include "src/config/api.h"
#include "src/middle/signals/mansignals.h"
#include "src/middle/manglobal.h"

#include <QCompleter>
#include <QJsonObject>
#include <QMessageBox>
#include <QMouseEvent>
#include <QString>

LoginDialog::LoginDialog(QWidget *parent)
    : UiQosDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(body());
    //取消默认标题栏
    this->setWindowFlags(Qt::CustomizeWindowHint);

    //Deprecated 2024-01-20 改用qss文件进行设置
    // QPixmap pixmap("F:/030_Study/Code/CosBrowser/u-logoa.jpg");
    // ui->labelLogo->setPixmap(pixmap.scaled(ui->labelLogo->size()));

    //lineSecretKey控件安装事件过滤器
    ui->lineSecretKey->installEventFilter(this);

    setTitle(QString::fromLocal8Bit("登录"));

    // style是一个自定义属性，用于属性选择器
    ui->labelSecretID->setProperty("style", "h5");
    ui->labelLoginName->setProperty("style", "h5");
    ui->labelSecretKey->setProperty("style", "h5");
    ui->labelRemark->setProperty("style", "h5");
    ui->btnLogin->setProperty("style", "h5");

    connect(ui->btnLogin, &QPushButton::clicked, this, &LoginDialog::onBtnLoginClicked);
    connect(MG->mSignal, &ManSignals::loginSuccess, this, &LoginDialog::onLoginSucceed);
    connect(MG->mSignal, &ManSignals::unLogin, this, &LoginDialog::show);
    connect(MG->mSignal, &ManSignals::error, this, &LoginDialog::onLoginError);
    updateLoginInfo();
}


LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::updateLoginInfo()
{
    QStringList words = MG->mDb->loginNameList();
    QCompleter* completer = new QCompleter(words);
    ui->lineLoginName->setCompleter(completer);

    connect(completer, static_cast<void (QCompleter::*)(const QString&)>(&QCompleter::activated),
            this, [&](const QString& name){
        LoginInfo info = MG->mDb->loginInfoByName(name);
        ui->lineSecretID->setText(info.secret_id);
        ui->lineSecretKey->setText(info.secret_key);
        ui->lineRemark->setText(info.remark);
        ui->checkSaveSection->setChecked(true);
    });
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

void LoginDialog::onBtnLoginClicked()
{
    //进行登录信息验证
    QJsonObject params;
    params["secretId"] = ui->lineSecretID->text().trimmed();
    params["secretKey"] = ui->lineSecretKey->text().trimmed();
    MG->mGate->send(API::LOGIN::NORMAL, params);
}

void LoginDialog::onLoginSucceed()
{
    accept();   //关闭自身，并发送accepted信号(显示主窗口)
    if(ui->checkSaveSection->isChecked()){
        //保存登录信息
        MG->mDb->saveLoginInfo(
            ui->lineLoginName->text(), ui->lineSecretID->text(),
            ui->lineSecretKey->text(), ui->lineRemark->text());
        updateLoginInfo();
    }else{
        //删除登录信息
        MG->mDb->removeLoginInfo(ui->lineSecretID->text());
    }
}

void LoginDialog::onLoginError(int api, const QString &msg)
{
    if(api != API::LOGIN::NORMAL)
        return;
    QMessageBox::warning(this, QString::fromLocal8Bit("登录失败"),
                               QString::fromLocal8Bit("登录失败: %1").arg(msg));
}


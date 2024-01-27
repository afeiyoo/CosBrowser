#include "uimain.h"
#include "ui_uimain.h"

#include <QDebug>

UiMain::UiMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UiMain)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);

    connect(ui->widgetToolbar, &ToolbarWidget::buttonClicked, this, &UiMain::onButtonClicked);
}

UiMain::~UiMain()
{
    delete ui;
    if(m_loginDialog != nullptr){
        delete m_loginDialog;
    }
}

void UiMain::showLoginDialog()
{
    if(m_loginDialog == nullptr){
        m_loginDialog = new LoginDialog();  //顶层窗口，不需要设置父窗口
        m_loginDialog->updateLoginInfo();
        //绑定登录成功信号
        connect(m_loginDialog, &LoginDialog::accepted, this, &UiMain::show);
    }
    hide();
    m_loginDialog->show();
}

void UiMain::onButtonClicked(const QString &text)
{
    qDebug()<<text;
    if(text == QString::fromLocal8Bit("上传")){
        //....
    }else if(text == QString::fromLocal8Bit("下载")){
        //....
    }else if(text == QString::fromLocal8Bit("退出登录")){
        onUnLogin();
    }
}

void UiMain::onUnLogin()
{
    showLoginDialog();
}

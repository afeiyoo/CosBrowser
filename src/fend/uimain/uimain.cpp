#include "uimain.h"
#include "ui_uimain.h"

UiMain::UiMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UiMain)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);
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
        //绑定登录成功信号
        connect(m_loginDialog, &LoginDialog::accepted, this, &UiMain::show);
        //绑定退出登录信号
        connect(ui->widgetToolbar, &ToolbarWidget::quitLogin, this, &UiMain::showLoginDialog);
    }
    hide();
    m_loginDialog->show();
}

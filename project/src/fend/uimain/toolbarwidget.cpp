#include "toolbarwidget.h"
#include "ui_toolbarwidget.h"
#include "src/middle/signals/mansignals.h"

#include <QSignalMapper>

ToolbarWidget::ToolbarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToolbarWidget)
{
    ui->setupUi(this);

    //使用SignalMapper避免大量的信号槽绑定
    // QSignalMapper *mapper = new QSignalMapper(this);
    // QList<QPushButton*> buttonList = findChildren<QPushButton*>();
    // for(auto btn: buttonList){
    //     connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
    //     mapper->setMapping(btn, btn->text());
    // }
    // //map发现btn和btn->text之间是绑定关系，则会发出mapped信号
    // connect(mapper, SIGNAL(mapped(QString)), this, SIGNAL(buttonClicked(QString)));
}

ToolbarWidget::~ToolbarWidget()
{
    delete ui;
}

void ToolbarWidget::on_btnQuit_clicked()
{
    emit MS->unLogin(); //发送退出登录信号
}


#include "uimain.h"
#include "ui_uimain.h"
#include "src/middle/signals/mansignals.h"

#include <QDebug>

UiMain::UiMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UiMain)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);

    connect(MS, &ManSignals::loginSuccess, this, &UiMain::show);
    connect(MS, &ManSignals::unLogin, this, &UiMain::onUnLogin);
}

UiMain::~UiMain()
{
    delete ui;
}

void UiMain::onUnLogin()
{
    hide();
}

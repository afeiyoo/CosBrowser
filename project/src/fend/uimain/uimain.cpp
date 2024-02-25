#include "uimain.h"
#include "ui_uimain.h"
#include "src/middle/signals/mansignals.h"
#include "src/middle/manglobal.h"

#include <QDebug>

UiMain::UiMain(QWidget *parent)
    : UiQosDialog(parent)
    , ui(new Ui::UiMain)
{
    ui->setupUi(body());
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);


    addMinButton(GLOBAL::PATH::MIN_PATH, GLOBAL::PATH::MIN_HOVER_PATH);
    addMaxButton(GLOBAL::PATH::MAX_PATH, GLOBAL::PATH::MAX_HOVER_PATH,
                 GLOBAL::PATH::NORMAL_PATH, GLOBAL::PATH::NORMAL_HOVER_PATH);

    setTitle(QString::fromLocal8Bit("Qos Browser"));
    resize(1080, 640);

    connect(MG->mSignal, &ManSignals::loginSuccess, this, &UiMain::show);
    connect(MG->mSignal, &ManSignals::unLogin, this, &UiMain::onUnLogin);
}

UiMain::~UiMain()
{
    delete ui;
}

void UiMain::onUnLogin()
{
    hide();
}

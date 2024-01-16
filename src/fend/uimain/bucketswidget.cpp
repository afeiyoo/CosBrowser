#include "bucketswidget.h"
#include "ui_bucketswidget.h"

BucketsWidget::BucketsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BucketsWidget)
{
    ui->setupUi(this);
}

BucketsWidget::~BucketsWidget()
{
    delete ui;
}

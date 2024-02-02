#include "bucketswidget.h"
#include "ui_bucketswidget.h"
#include "src/bend/man/manbuckets.h"

BucketsWidget::BucketsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BucketsWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(MB->model());
}

BucketsWidget::~BucketsWidget()
{
    delete ui;
}

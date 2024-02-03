#include "objectswidget.h"
#include "ui_objectswidget.h"
#include "src/bend/man/mancloud.h"
#include "src/fend/uidelegates/bucketdelegate.h"

ObjectsWidget::ObjectsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    ui->tableView->setModel(MC->model());
    //对第二列设置代理
    ui->tableView->setItemDelegateForColumn(1, new BucketDelegate());

    // 设置列宽度
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); //设置最后一列占满整个表

    //隐藏垂直表头
}

ObjectsWidget::~ObjectsWidget()
{
    delete ui;
}

#include "objectswidget.h"
#include "ui_objectswidget.h"
#include "src/bend/man/manbuckets.h"
#include "src/fend/uidelegates/bucketdelegate.h"

ObjectsWidget::ObjectsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    ui->tableView->setModel(MB->model());

    //对第二列设置代理
    ui->tableView->setItemDelegateForColumn(1, new BucketDelegate());
}

ObjectsWidget::~ObjectsWidget()
{
    delete ui;
}

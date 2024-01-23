#include "objectswidget.h"
#include "ui_objectswidget.h"
#include "src/bend/man/manbuckets.h"

ObjectsWidget::ObjectsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    ui->tableView->setModel(MB->model());
}

ObjectsWidget::~ObjectsWidget()
{
    delete ui;
}

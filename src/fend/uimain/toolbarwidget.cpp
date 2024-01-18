#include "toolbarwidget.h"
#include "ui_toolbarwidget.h"

ToolbarWidget::ToolbarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToolbarWidget)
{
    ui->setupUi(this);
    connect(ui->btnQuit, &QPushButton::clicked, this, &ToolbarWidget::quitLogin);
}

ToolbarWidget::~ToolbarWidget()
{
    delete ui;
}


void ToolbarWidget::on_btnUpload_clicked()
{

}


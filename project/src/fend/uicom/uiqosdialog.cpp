#include "uiqosdialog.h"
#include "ui_uiqosdialog.h"
#include "ui_uibasedialog.h"
#include "src/config/globals.h"

UiQosDialog::UiQosDialog(QWidget *parent)
    : UiBaseDialog(parent)
    , ui(new Ui::UiQosDialog)
{
    ui->setupUi(body());
    setLogo(GLOBAL::PATH::LOGO_PATH);
    setTitle(QString::fromLocal8Bit("Qos"));
    m_ui->labelLogo->setFixedSize(32, 24);
    m_ui->labelTitle->setProperty("style", "h4");
}

UiQosDialog::~UiQosDialog()
{
    delete ui;
}

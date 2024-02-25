#ifndef UIMAIN_H
#define UIMAIN_H

#include "src/fend/uicom/uiqosdialog.h"

namespace Ui {
class UiMain;
}

class UiMain : public UiQosDialog
{
    Q_OBJECT

public:
    explicit UiMain(QWidget *parent = nullptr);
    ~UiMain();


private slots:

    void onUnLogin();

private:
    Ui::UiMain *ui;
};

#endif // UIMAIN_H

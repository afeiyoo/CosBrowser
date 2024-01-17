#include "src/fend/uimain/uimain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UiMain w;
    w.showLoginDialog();    //显示登录窗口
    return a.exec();
}

#include "src/fend/uimain/uimain.h"
#include "src/helper/filehelper.h"
#include "src/bend/man/manbuckets.h"
#include "src/bend/man/mandb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //1. 读取文件中的qss
    QString qssStr = FileHelper::readAllTxt(":/static/qss/default.qss");

    //2. QApplication加载qss内容
    a.setStyleSheet(qssStr);

    MDB->init();

    MB->setBuckets();

    UiMain w;
    w.showLoginDialog();    //显示登录窗口
    return a.exec();
}

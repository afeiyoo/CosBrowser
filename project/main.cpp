#include "src/fend/uimain/uimain.h"
#include "src/fend/uilogin/logindialog.h"
#include "src/middle/manglobal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MG->init(argc,argv);

    UiMain w;
    LoginDialog login;

    login.show();
    return a.exec();
}

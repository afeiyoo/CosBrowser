#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent):
    QLineEdit(parent)
{

}

void MyLineEdit::keyPressEvent(QKeyEvent *event)
{
    //捕获Ctrl+c或Ctrl+v事件，禁用复制粘贴
    if(event->modifiers() == Qt::ControlModifier){
        if(event->key() == Qt::Key_C || event->key() == Qt::Key_V)
            return;
    }

    QLineEdit::keyPressEvent(event);
}

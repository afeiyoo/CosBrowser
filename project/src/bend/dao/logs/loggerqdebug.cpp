#include "loggerqdebug.h"
#include "src/config/globals.h"
#include <QDebug>
#include <QtGlobal>
#include <QDateTime>
#include <iostream>

LoggerQDebug::LoggerQDebug(QObject *parent)
    : BasicLogger{parent}
{
    // QDebug拦截器安装，将QDebug信息打印到文件中
    qInstallMessageHandler(handle);
}

LoggerQDebug::~LoggerQDebug()
{

}

void LoggerQDebug::print(const QString &file, int line, const QString &func, void *tid, int level, const QVariant &var, bool up)
{
    QDateTime dt;
    QString dtStr = dt.currentDateTime().toString(Qt::ISODate);
    QString front = QString::fromLocal8Bit("%1[%2] %3:%4 -")
                        .arg(dtStr, GLOBAL::LOG_NAMES[level], file)
                        .arg(line);
    front = front.replace("..\\", "");
    //使用qDebug而不是直接存文件，是为了打印QVariant类型
    qDebug() << front.toLocal8Bit().data() << var;
}

void LoggerQDebug::handle(QtMsgType type, const QMessageLogContext &contex, const QString &msg)
{
    QFile file(filePath());

    QString key("QVariant(");
    QString message = msg;
    message.replace(msg.indexOf(key), key.size(), "").chop(1);

    if(file.open(QIODevice::WriteOnly|QIODevice::Append)){
        //输入到文件流中
        QTextStream stream(&file);
        stream << message << endl;
        file.close();
    }
    //用于控制台输出
    std::cout << message.toUtf8().data() << std::endl;
}

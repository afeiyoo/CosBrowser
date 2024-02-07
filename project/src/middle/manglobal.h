#ifndef MANGLOBAL_H
#define MANGLOBAL_H

#include <QObject>
#include "src/config/loggerproxy.h"

#define MG ManGlobal::instance()
#define mLogIns MG->mLog
#define mTotal mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).total
#define mDebug mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).debug
#define mInfo mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).info
#define mWarning mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).warning
#define mError mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).error
#define mFatal mLogIns->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).fatal

//不能将其他单例类的头文件放在全局单例的头文件中
//具体哪个类引用了，则哪个类再包含（这里包含了日志类的头文件，是因为日志类头文件基本每个类都会使用）
//使用对象树所属关系系统进行内存释放
class ManCloud;
class ManDB;
class ManPlugin;
class GateWay;
class ManSignals;
class LoggerProxy;
class ManModels;

class ManGlobal : public QObject
{
    Q_OBJECT
public:
    explicit ManGlobal(QObject *parent = nullptr);

    ~ManGlobal();

    void destory();

    static ManGlobal* instance();

    void init(int argc, char* argv[]);

public:
    LoggerProxy* mLog = nullptr;
    ManCloud* mCloud = nullptr;
    ManDB* mDb = nullptr;
    ManPlugin* mPlugin = nullptr;
    GateWay* mGate = nullptr;
    ManSignals* mSignal = nullptr;
    ManModels* mModel = nullptr;

signals:
};

#endif // MANGLOBAL_H

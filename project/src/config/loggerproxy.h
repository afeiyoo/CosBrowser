#ifndef LOGGERPROXY_H
#define LOGGERPROXY_H
#include "src/bend/dao/logs/basiclogger.h"
#include "src/config/globals.h"

#define log LoggerProxy::instance()
#define mTotal log->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).total
#define mDebug log->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).debug
#define mInfo log->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).info
#define mWarning log->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).warning
#define mError log->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).error
#define mFatal log->reset(QT_MESSAGELOG_FILE, QT_MESSAGELOG_LINE, QT_MESSAGELOG_FUNC).fatal


class LoggerProxy: public QObject
{
    Q_OBJECT
public:
    explicit LoggerProxy(QObject *parent = nullptr);
    ~LoggerProxy();

    static LoggerProxy* instance();

    const LoggerProxy& reset(const QString& file, int line, const QString& func);

    void total(const QVariant& var, bool up=false) const;
    void debug(const QVariant& var, bool up=false) const;
    void info(const QVariant& var, bool up=false) const;
    void warning(const QVariant& var, bool up=false) const;
    void error(const QVariant& var, bool up=true) const;
    void fatal(const QVariant& var, bool up=true) const;

    void setLevel(GLOBAL::LOG_LEVEL newLevel);
    void setLogger(BasicLogger *newLogger);

signals:
    void sigLog(const QString& file, int line, const QString& func, void* tid,
                int level, const QVariant& var, bool up) const;

private:
    void doLog(GLOBAL::LOG_LEVEL level, const QVariant& var, bool up) const;

private:
    BasicLogger* m_logger = nullptr;
    GLOBAL::LOG_LEVEL m_level;

    QString m_file;
    int m_line;
    QString m_func;
};

#endif // LOGGERPROXY_H

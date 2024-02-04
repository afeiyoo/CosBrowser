﻿#ifndef BASICLOGGER_H
#define BASICLOGGER_H

#include <QObject>
#include <QThread>

// 日志线程类，负责打印日志
class BasicLogger : public QObject
{
    Q_OBJECT
public:
    explicit BasicLogger(QObject *parent = nullptr);
    ~BasicLogger();

public slots:
    void onLog(const QString& file, int line, const QString& func, void* tid,
               int level, const QVariant& var, bool up);

protected:
    virtual void print(const QString& file, int line, const QString& func, void* tid,
                       int level, const QVariant& var, bool up) = 0;

    static QString filePath();

private:
    QThread* m_td = nullptr;

signals:
};

#endif // BASICLOGGER_H
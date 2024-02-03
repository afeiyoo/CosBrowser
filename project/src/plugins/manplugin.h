#ifndef MANPLUGIN_H
#define MANPLUGIN_H

#include <QObject>

#define MP ManPlugin::instance()

class DaoClouds;

class ManPlugin : public QObject
{
    Q_OBJECT
public:
    explicit ManPlugin(QObject *parent = nullptr);

    static ManPlugin* instance();

    DaoClouds *clouds() const;

signals:

private:
    void installPlugins();

private:
    DaoClouds* m_clouds;    //不能使用派生类作为类型
};

#endif // MANPLUGIN_H

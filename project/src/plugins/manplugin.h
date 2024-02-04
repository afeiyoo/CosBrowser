#ifndef MANPLUGIN_H
#define MANPLUGIN_H

#include <QObject>

#define MP ManPlugin::instance()

class DaoClouds;
class Version;

class ManPlugin : public QObject
{
    Q_OBJECT
public:
    explicit ManPlugin(QObject *parent = nullptr);

    static ManPlugin* instance();

    DaoClouds *clouds() const;

    ~ManPlugin();

    void installPlugins(int argc, char* argv[]);
signals:

private:
    DaoClouds* m_clouds;    //不能使用派生类作为类型
    Version* m_version;
};

#endif // MANPLUGIN_H

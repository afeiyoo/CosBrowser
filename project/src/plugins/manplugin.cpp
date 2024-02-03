#include "manplugin.h"

#include "src/bend/dao/clouds/daocloudsmock.h"

Q_GLOBAL_STATIC(ManPlugin, ins)

ManPlugin::ManPlugin(QObject *parent)
    : QObject{parent}
{
    installPlugins();
}

ManPlugin* ManPlugin::instance()
{
    return ins();
}

void ManPlugin::installPlugins()
{
    m_clouds = new DaoCloudsMock(":/static/testing/buckets2.json");
}

DaoClouds *ManPlugin::clouds() const
{
    return m_clouds;
}

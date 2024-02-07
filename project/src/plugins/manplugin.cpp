#include "manplugin.h"

#include "src/bend/dao/clouds/daocloudsmock.h"
#include "src/bend/dao/configs/versionjson.h"
#include "src/config/globals.h"
#include "src/bend/dao/configs/versioncmd.h"
#include "src/bend/dao/logs/loggerqdebug.h"
#include "src/config/loggerproxy.h"
#include "src/middle/manglobal.h"

ManPlugin::ManPlugin(QObject *parent)
    : QObject{parent}
{

}

void ManPlugin::installPlugins(int argc, char* argv[])
{
    //如果输入命令行，则命令行参数优先级最高，否则直接加载配置文件中的配置信息
    VersionCmd version(argc, argv);
    if(version.isValid()){
        m_version = new VersionCmd(argc, argv);
    }else{
        m_version = new VersionJson(GLOBAL::VERSION::JSON_PATH);
    }

    m_version->setVersion();    //从配置文件中读取版本号
    if(m_version->major() == GLOBAL::VERSION::MAJOR_BUSINESS){
        m_clouds = new DaoCloudsMock(":/static/testing/business.json");
    }else{
        m_clouds = new DaoCloudsMock(":/static/testing/custom.json");
    }

    //为日志代理单例类安装插件
    MG->mLog->setLogger(new LoggerQDebug());
}

DaoClouds *ManPlugin::clouds() const
{
    return m_clouds;
}

ManPlugin::~ManPlugin()
{
    delete m_clouds;
    delete m_version;
    qDebug("delete ManPlugin ");
}

#include "gateway.h"
#include <QtConcurrent>
#include "src/bend/man/mancloud.h"
#include "src/config/api.h"
#include "src/config/loggerproxy.h"

Q_GLOBAL_STATIC(GateWay, ins)

GateWay::GateWay(QObject *parent)
    : QObject{parent}
{}

GateWay *GateWay::instance()
{
    return ins();
}

void GateWay::send(int api, const QJsonValue &value)
{
    QtConcurrent::run([=](){
        try{
            this->dispach(api, value);
        }catch(QString e){
            mError(e);
        }
    });
}

void GateWay::dispach(int api, const QJsonValue &value)
{
    //路由操作
    switch(api){
    case API::LOGIN::NORMAL:
        apiLogin(value);
        break;
    default:
        break;
    }
}

void GateWay::apiLogin(const QJsonValue &value)
{
    QString secretId = value["secretId"].toString();
    QString secretKey = value["secretKey"].toString();
    MC->login(secretId, secretKey);
}

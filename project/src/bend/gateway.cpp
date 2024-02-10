#include "gateway.h"
#include <QtConcurrent>
#include "src/bend/man/mancloud.h"
#include "src/config/api.h"
#include "src/config/loggerproxy.h"
#include "src/middle/signals/mansignals.h"
#include "src/middle/manglobal.h"
#include "src/config/exception.h"
#include "src/config/errorcode.h"

GateWay::GateWay(QObject *parent)
    : QObject{parent}
{}

GateWay::~GateWay()
{
    qDebug("delete GateWay ");
}

void GateWay::send(int api, const QJsonValue &value)
{
    QtConcurrent::run([=](){
        try{
            this->dispach(api, value);
        }catch(BaseException e){
            mError(e.msg());
            emit MG->mSignal->error(api, e.msg());
        }catch(...){
            BaseException e = BaseException(EC_100000, QString::fromLocal8Bit("未知错误"));
            mError(e.msg());
            emit MG->mSignal->error(api, e.msg());
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
    MG->mCloud->login(secretId, secretKey);
    emit MG->mSignal->loginSuccess();    //发送登录成功信号
}

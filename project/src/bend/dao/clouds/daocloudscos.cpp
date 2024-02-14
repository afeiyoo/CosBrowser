#include "src/middle/manglobal.h"
#include "daocloudscos.h"
#include "src/config/exception.h"
#include "src/config/errorcode.h"
#include <QDebug>

#include "cos_api.h"

using  namespace qcloud_cos;


DaoCloudsCos::DaoCloudsCos()
{
    m_config = new CosConfig();
    m_config->InitConf("./cosconfig.json");
}

DaoCloudsCos::~DaoCloudsCos()
{
    delete m_config;
    m_config = nullptr;
}


QList<MyBucket> DaoCloudsCos::buckets()
{
    QList<MyBucket> res;

    GetServiceReq req;
    GetServiceResp resp;
    CosAPI cos = qcloud_cos::CosAPI(*m_config);
    CosResult result = cos.GetService(req, &resp);

    if (result.IsSucc()) {
        std::vector<Bucket> bs = resp.GetBuckets();
        for (std::vector<Bucket>::const_iterator itr = bs.begin(); itr != bs.end(); ++itr)
        {
            const Bucket& v = *itr;

            MyBucket b;
            b.name = QString(v.m_name.c_str());
            b.location = QString(v.m_location.c_str());
            b.createDate = QString(v.m_create_date.c_str());
            res.append(b);
        }
    }
    else
    {
        QString msg = QString::fromLocal8Bit("腾讯云错误码【%1】： %2")
                          .arg(result.GetErrorCode().c_str(), result.GetErrorMsg().c_str());
        throw BaseException(EC_211000, msg);
    }
    //    throwError(result);

    return res;
}

QList<MyBucket> DaoCloudsCos::login(const QString &secretId, const QString &secretKey)
{

    m_config->SetAccessKey(secretId.toStdString());
    m_config->SetSecretKey(secretKey.toStdString());
    // m_config->SetRegion("ap-nanjing");

    return buckets();
}

bool DaoCloudsCos::isBucketExists(const QString &bucketName)
{
    QList<MyBucket> bs = buckets();
    for(const auto& b: qAsConst(bs)){
        if(b.name == bucketName)
            return true;
    }
    return false;
}

QString DaoCloudsCos::getBucketLocation(const QString &bucketName)
{
    CosAPI cos = CosAPI(*m_config);
    return QString(cos.GetBucketLocation(bucketName.toStdString()).c_str());
}

void DaoCloudsCos::putBucket(const QString &bucketName, const QString &location)
{
    if (isBucketExists(bucketName)) {
        return;
    }

    PutBucketReq req(bucketName.toLocal8Bit().data());
    PutBucketResp resp;

    m_config->SetRegion(location.toStdString());
    CosAPI cos(*m_config);
    CosResult result = cos.PutBucket(req, &resp);
    if (!result.IsSucc()) {
        throwError(EC_331100, result);
    }
}

void DaoCloudsCos::deleteBucket(const QString &bucketName)
{
    if (!isBucketExists(bucketName)) {
        return;
    }

    DeleteBucketReq req(bucketName.toLocal8Bit().data());
    DeleteBucketResp resp;
    QString location = getBucketLocation(bucketName);
    m_config->SetRegion(location.toStdString());
    CosAPI cos(*m_config);
    CosResult result = cos.DeleteBucket(req, &resp);
    if (!result.IsSucc()) {
        throwError(EC_331300, result);
    }
}

QList<MyObject> DaoCloudsCos::getObjects(const QString &bucketName, const QString &dir)
{
    GetBucketReq req(bucketName.toLocal8Bit().data());
    if(dir != "")
        req.SetPrefix(dir.toLocal8Bit().data());
    req.SetDelimiter("/");

    GetBucketResp resp;
    QString location = getBucketLocation(bucketName);
    m_config->SetRegion(location.toStdString());
    CosAPI cos(*m_config);
    CosResult result = cos.GetBucket(req, &resp);

    if(!result.IsSucc())
        throwError(EC_331200, result);

    return getDirList(resp, dir) + getFileList(resp, dir);
}

QList<MyObject> DaoCloudsCos::getDirList(qcloud_cos::GetBucketResp &resp, const QString &dir)
{
    QList<MyObject> res;
    //获取目录列表
    std::vector<std::string> cs = resp.GetCommonPrefixes();
    for(int i = 0; i < cs.size(); ++i){
        QString key(cs[i].c_str());
        // qDebug() << "dir: " << key;
        MyObject object;
        object.dir = dir;
        object.name = key.mid(dir.size());
        object.lastmodified = "-";
        res.append(object);
        qDebug() << "dirName: " << object.name;
    }

    return res;
}

QList<MyObject> DaoCloudsCos::getFileList(qcloud_cos::GetBucketResp &resp, const QString &dir)
{
    QList<MyObject> res;
    //获取文件列表
    const std::vector<Content>& contents = resp.GetContents();
    for(std::vector<Content>::const_iterator itr = contents.begin(); itr != contents.end(); ++itr){
        const Content& content = *itr;
        QString key(content.m_key.c_str());
        // qDebug() << "file: " << key;
        QString name = key.mid(dir.size());
        if(key != dir){
            MyObject object;
            object.name = name;
            object.lastmodified = QString(content.m_last_modified.c_str());
            object.size = QString(content.m_size.c_str()).toULongLong();
            object.dir = dir;
            res.append(object);
            qDebug() << "fileName: " << object.name;
        }
    }
    return res;
}

void DaoCloudsCos::throwError(const QString &code, qcloud_cos::CosResult &result)
{
    QString msg = QString::fromLocal8Bit("腾讯云错误码 【%1】：%2")
                      .arg(result.GetErrorCode().c_str(), result.GetErrorMsg().c_str());
    qDebug() << msg;
    throw BaseException(code, msg);
}


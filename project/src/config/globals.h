#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QDir>

#include "src/helper/filehelper.h"

//使用命名空间
namespace GLOBAL {

namespace PATH {
static const QString WORK = QDir::currentPath();
static const QString TMP = FileHelper::joinPath(WORK, "temp");
}

namespace SQLITE {
static const QString NAME = FileHelper::joinPath(PATH::TMP, "cos.db");
}

namespace SQL{
static const QString LOGIN_INFO_TABLE = ":/static/sql/login_info.sql";
}

namespace TABLES{
static const QString LOGIN_INFO = "login_info";
}

namespace VERSION{
static const QString MAJOR_CUSTOM = "custom";
static const QString MAJOR_BUSINESS = "business";
static const QString JSON_PATH = ":/static/versions/config_default.json";
}

namespace ENV{
static const QString ENV_DEV = "dev";
static const QString ENV_ALPHA = "alpha";
static const QString ENV_BETA = "beta";
static const QString ENV_PRE = "pre";
static const QString ENV_PROD = "prod";
}

static bool init(){
    return FileHelper::mkPath(PATH::TMP);
}

//程序启动时，调用init函数
static bool OK = init();
}

#endif // GLOBALS_H

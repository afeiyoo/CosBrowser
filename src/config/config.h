#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QDir>

#include "src/helper/filehelper.h"

//使用命名空间
namespace CONF {

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

static bool init(){
    return FileHelper::mkPath(PATH::TMP);
}

//程序启动时，调用init函数
static bool OK = init();
}

#endif // CONFIG_H

QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testcos.cpp \
    ../../project/src/bend/dao/clouds/daocloudscos.cpp \
    ../../project/src/config/exception.cpp \
    ../../project/src/helper/filehelper.cpp \
    ../../project/src/middle/models/cloudmodels.cpp

HEADERS += \
    ../../project/src/bend/dao/clouds/daoclouds.h \
    ../../project/src/bend/dao/clouds/daocloudscos.h \
    ../../project/src/config/errorcode.h \
    ../../project/src/config/exception.h \
    ../../project/src/helper/filehelper.h \
    ../../project/src/middle/models/cloudmodels.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../project/third/cos/libs/x64/ -lcossdk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../project/third/cos/libs/x64/ -lcossdkd
else:unix: LIBS += -L$$PWD/../../project/third/cos/libs/x64/ -lcossdk

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../project/third/cos/third_party/lib/x64/poco -lPocoFoundation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../project/third/cos/third_party/lib/x64/poco -lPocoFoundationd
else:unix: LIBS += -L$$PWD/../../project/third/cos/third_party/lib/x64/poco -lPocoFoundation

INCLUDEPATH += \
    $$PWD/../../project \
    $$PWD/../../project/third/cos/include \
    $$PWD/../../project/third/cos/third_party/include

DEPENDPATH += \
    $$PWD/../../project/third/cos/include \
    $$PWD/../../project/third/cos/third_party/include


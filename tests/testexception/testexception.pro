QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testexception.cpp \
    ../../project/src/config/exception.cpp \
    ../../project/src/helper/filehelper.cpp

HEADERS += \
    ../../project/src/config/exception.h \
    ../../project/src/helper/filehelper.h

INCLUDEPATH += $$PWD/../../project

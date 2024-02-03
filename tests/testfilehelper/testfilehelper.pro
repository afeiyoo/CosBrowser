QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    ../../project/src/helper/filehelper.cpp \
    tst_testfilehelper.cpp

INCLUDEPATH += $$PWD/../../project

RESOURCES += \
    resource.qrc

HEADERS += \
    ../../project/src/helper/filehelper.h

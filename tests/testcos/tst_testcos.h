#ifndef TESTCOS_H
#define TESTCOS_H

#include <QtTest>

#include "src/bend/dao/clouds/daocloudscos.h"

// add necessary includes here

class TestCos : public QObject
{
    Q_OBJECT

public:
    TestCos();
    ~TestCos();

private slots:
    // 调用所有测试用例之前，会先调用一次该函数
    void initTestCase();
    // 调用所有测试用例之后，会调用一次该函数
    void cleanupTestCase();
    void test_buckets();

private:
    DaoCloudsCos m_cos;
};

#endif // TESTCOS_H


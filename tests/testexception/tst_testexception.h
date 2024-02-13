#ifndef TESTEXCEPTION_H
#define TESTEXCEPTION

#include <QtTest>
#include <QDebug>

#include "../project/src/config/exception.h"

class TestException : public QObject
{
    Q_OBJECT

public:
    TestException();
    ~TestException();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_generateErrorCodeHFile();
};

#endif // TESTEXCEPTION

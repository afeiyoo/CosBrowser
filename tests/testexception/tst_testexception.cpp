#include <QtTest>
#include <QDebug>
#include "../../project/src/config/exception.h"

// add necessary includes here

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

TestException::TestException() {}

TestException::~TestException() {}

void TestException::initTestCase() {}

void TestException::cleanupTestCase() {}

void TestException::test_generateErrorCodeHFile() {
    BaseException::generateErrorCodeHFile(
        "../../../CosBrowser/project/static/docs/errorcode.csv",
        "../../../CosBrowser/project/src/config/errorcode.h");
}

QTEST_APPLESS_MAIN(TestException)

#include "tst_testexception.moc"

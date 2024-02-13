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

TestCos::TestCos() {}

TestCos::~TestCos() {}

void TestCos::initTestCase() {
    m_cos.login("AKIDypkgvHVfgYH0oeN0X5Tkw9TvKhAhCYn5",
                "KjJl6LOQf4bCoT5lJymXDxtwwATgvIeu");
}

void TestCos::cleanupTestCase() {}

void TestCos::test_buckets() {

    QList<MyBucket> bs = m_cos.buckets();

    // QVERIFY 进行BOOL表达式的判断，如果为真则表示通过，否则表示失败
    // QVERIFY(bs.size() > 0);

    // QCOMPARE 进行恒等比较
    QCOMPARE(m_cos.buckets().size(), 1);
}

QTEST_APPLESS_MAIN(TestCos)

#include "tst_testcos.moc"

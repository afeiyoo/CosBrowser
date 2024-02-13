#include "tst_testcos.h"

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

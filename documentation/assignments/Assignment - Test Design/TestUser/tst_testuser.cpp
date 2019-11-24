#include <QtTest>

#include "User.h"

class TestUser : public QObject
{
    Q_OBJECT

public:
    TestUser();
    ~TestUser();

private slots:
    void test_case1();
    //void testIsDefaultCommitment(Commitment c);
    //void testGetDefaultCommitment();
};
void TestUser::test_case1()
{

}

QTEST_APPLESS_MAIN(TestUser)

#include "tst_testuser.moc"

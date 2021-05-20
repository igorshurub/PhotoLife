#include <QtTest>
#include "C:/Qt/photolife/tests/photolife_tests_3/functions.h"

// add necessary includes here

class test_3 : public QObject
{
    Q_OBJECT

public:
    test_3();
    ~test_3();

private slots:
    void message_to_server_yes1();
    void message_to_server_yes2();
    void message_to_server_no();
};

test_3::test_3()
{

}

test_3::~test_3()
{

}

void test_3::message_to_server_yes1()
{
    std::string log = "user";
    std::string pass = "123";
    QString result = authorize(log,pass);
    QVERIFY("authorization yes " == result);
}

void test_3::message_to_server_yes2()
{
    std::string log = "user2";
    std::string pass = "124";
    QString result = authorize(log,pass);
    QVERIFY("authorization yes " == result);
}

void test_3::message_to_server_no()
{
    std::string log = "user";
    std::string pass = "12343424346";
    QString result = authorize(log,pass);
    QVERIFY("authorization error " == result);
}
QTEST_APPLESS_MAIN(test_3)

#include "tst_test_3.moc"

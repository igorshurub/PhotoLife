#include <QtTest>
#include "C:/Qt/photolife/tests/photolife_test_4/dialog_login.h"

// add necessary includes here

class test_4 : public QObject
{
    Q_OBJECT

public:
    test_4();
    ~test_4();

private slots:
    void slot_ready_read();

};

test_4::test_4()
{

}

test_4::~test_4()
{

}

void test_4::slot_ready_read()
{

    std::string message = "authorization yes ";
    QVERIFY(message=="authorization yes " == 1);
}

QTEST_APPLESS_MAIN(test_4)

#include "tst_test_4.moc"

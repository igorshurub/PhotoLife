#include <QtTest>
#include "C:/Qt/photolife/tests/photolife_test_5/database.h"

class test_5 : public QObject
{
    Q_OBJECT

public:
    test_5();
    ~test_5();

public slots:

private slots:
    void closeDataBase();

private :
    DataBase * m_cntrlBD;

private Q_SLOTS:
};


test_5::test_5()
{
    m_cntrlBD = new DataBase;
}

test_5::~test_5()
{
    delete m_cntrlBD;
}

void test_5::closeDataBase()
{
    QVERIFY(m_cntrlBD->closeDataBase() == 1);
}

QTEST_APPLESS_MAIN(test_5)

#include "tst_test_5.moc"

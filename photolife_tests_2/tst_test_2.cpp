#include <QtTest>
#include "C:/Qt/photolife/tests/photolife_tests/database.h"

// add necessary includes here

class test_2 : public QObject
{
    Q_OBJECT

public:
    test_2();
    ~test_2();

private slots:

    void connectToDataBase();

private :
    DataBase * m_cntrlBD;
};

test_2::test_2()
{
    m_cntrlBD = new DataBase;
}

test_2::~test_2()
{
    delete m_cntrlBD;
}

void test_2::connectToDataBase()
{
     QVERIFY(QFile("C:/Qt/photolife/" DATABASE_NAME).exists() == 1);
}

QTEST_APPLESS_MAIN(test_2)

#include "tst_test_2.moc"

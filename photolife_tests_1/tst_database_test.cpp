#include <QtTest>
#include "C:/Qt/photolife/tests/photolife_tests/database.h"

class database_test : public QObject
{
    Q_OBJECT

public:
    database_test();
    ~database_test();

public slots:
    void initTestCase();
    void cleanupTestCase();

private slots:
    void open_database();

private :
    DataBase * m_cntrlBD;

private Q_SLOTS:
};


database_test::database_test()
{
    m_cntrlBD = new DataBase;
}

database_test::~database_test()
{
    delete m_cntrlBD;
}

void database_test::initTestCase()
{
}

void database_test::cleanupTestCase()
{
}

void database_test::open_database()
{
    QVERIFY(m_cntrlBD->openDataBase()== 1);
}

QTEST_APPLESS_MAIN(database_test)

#include "tst_database_test.moc"

#include <QCoreApplication>
#include "mytcpserver.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include "database.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

//    db.setDatabaseName("DungeonStroll");

//    if (db.open()) {qDebug()<<"db is open";} else {qDebug()<<"db not open";}

/*    QSqlQuery query(db);

    query.exec("CREATE TABLE User("
"   login text not null"
"   password text not null"
"   )");

    query.prepare("insert into User(login, password)"
"   values (:login, :password)");

    query.bindValue(":login", "user1");
    query.bindValue(":password", "123");

    query.exec();

    query.prepare("insert into User(login, password)"
"   values (:login, :password)");

    query.bindValue(":login", "user2");
    query.bindValue(":password", "321");

    query.exec();
*/
    return a.exec();
}




























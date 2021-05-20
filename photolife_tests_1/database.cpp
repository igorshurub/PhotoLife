#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{
}

DataBase::~DataBase()
{
}

/* Функция для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    if(QFile("C:/Qt/photolife/" DATABASE_NAME).exists())
        this->openDataBase();
}

/* Функция для открытия базы данных
 * */
bool DataBase::openDataBase()
{
     db=QSqlDatabase::addDatabase("QSQLITE");
     db.setHostName(DATABASE_HOSTNAME);
     db.setDatabaseName("C:/Qt/photolife/"  DATABASE_NAME);
     if(db.open()){
         return 1;
     } else {
         return 0;
     }
 }

/* Функция для закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

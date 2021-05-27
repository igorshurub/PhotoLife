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
    if(QFile("D:/Qt/" DATABASE_NAME).exists())
        this->openDataBase();
}

/* Функция для открытия базы данных
 * */
bool DataBase::openDataBase()
{
     db=QSqlDatabase::addDatabase("QSQLITE");
     db.setHostName(DATABASE_HOSTNAME);
     db.setDatabaseName("D:/Qt/"  DATABASE_NAME);
     if(db.open()){
         return true;
     } else {
         return false;
     }
 }

/* Функция для закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}


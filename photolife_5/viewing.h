#ifndef VIEWING_H
#define VIEWING_H

#include <QDialog>
#include <QSqlTableModel>
#include "database.h"

namespace Ui {
class Viewing;
}

class Viewing : public QDialog
{
    Q_OBJECT

public:
    explicit Viewing(QWidget *parent = nullptr);
    ~Viewing();

private slots:
    // Слот для получения изображения из базы данных
    void slotCurrentPic(QModelIndex index);

private:
    Ui::Viewing *ui;
    DataBase *db;
    QSqlTableModel *model;

private:
void setupModel(const QString &tableName, const QStringList &headers);//получение таблицы из БД
void createUI();
};

#endif // VIEWING_H

#ifndef EDITING_H
#define EDITING_H

#include <QDialog>
#include <QSqlTableModel>
#include "database.h"
namespace Ui {
class Editing;
}

class Editing : public QDialog
{
    Q_OBJECT

public:
    explicit Editing(QWidget *parent = nullptr);
    ~Editing();
private slots:
    // Слот для получения изображения из базы данных
    void slotCurrentPic(QModelIndex index);

private:
    Ui::Editing *ui;

    DataBase *db;
    QSqlTableModel *model;
private:
void setupModel(const QString &tableName, const QStringList &headers);
void createUI();
};

#endif // EDITING_H

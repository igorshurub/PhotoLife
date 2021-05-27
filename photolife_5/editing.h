#ifndef EDITING_H
#define EDITING_H

#include <QImage>
#include <QPixmap> //для получения изображения из БД и работы с ним
#include <QColor> //для изменения характеристик фото
#include <QDialog>
#include <QSqlTableModel>
#include "database.h"

namespace Ui {
class Editing;
}

class Editing : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(int lightness READ lightness WRITE setLightness NOTIFY lightnessChanged)//бегунок для изменения яркости
    Q_PROPERTY(int saturation READ saturation WRITE setSaturation NOTIFY saturationChanged)//бегунок для изменения контрастности

public:
    explicit Editing(QWidget *parent = nullptr);
    ~Editing();
    int lightness() const;
    int saturation() const;

public slots:
    void setLightness(int lightness);//функция для устанавки значения яркости
    void setSaturation(int saturation);//функция для устанавки значения контрастности

signals:
    void lightnessChanged(int lightness);//функция для изменения яркости
    void saturationChanged(int saturation);//функция для изменения контрастности

private slots:
    void slotCurrentPic(QModelIndex index); //Слот для получения изображения из базы данных
    void changeImageLihtness(int value);//функция для изменения яркости фото
    void changeImageSaturation(int value);//функция для изменения контрастности фото

private:
    Ui::Editing *ui;
    DataBase *db;
    QSqlTableModel *model;

    QImage image;
    int m_lightness;
    int m_saturation;

private:
void setupModel(const QString &tableName, const QStringList &headers);//получение таблицы из БД
void createUI();
};
#endif // EDITING_H

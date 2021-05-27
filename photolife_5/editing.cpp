#include "editing.h"
#include "ui_editing.h"
#include "dialog_login.h"
#include <QImage>
#include <QPixmap>
#include <QColor>
#include <QDialog>

Editing::Editing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editing)
{
    ui->setupUi(this);
    db = new DataBase();
    db->connectToDataBase();
    //отображение столбцов БД в следующем виде
    this->setupModel(TABLE,
                    QStringList() << trUtf8("pict_id")
                                  << trUtf8("name_photo")
                                  << trUtf8("photo")
                                  << trUtf8("lightness (%)")
                                  << trUtf8("saturation (%)"));
    this->createUI();
}

//получение таблицы из БД
void Editing::setupModel(const QString &tableName, const QStringList &headers){
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    for (int i = 0,j = 0; i < model->columnCount();i++,j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    //Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setSort(0,Qt::AscendingOrder);

}

void Editing::createUI()
    {
     ui->tableView2->setModel(model);
     //Скрываем определенные поля из БД

     // ui->tableView2->setColumnHidden(0, true);
     ui->tableView2->setColumnHidden(0, true);
     //ui->tableView2->setColumnHidden(1, true);
     ui->tableView2->setColumnHidden(3, true);
     ui->tableView2->setColumnHidden(4, true);
     ui->tableView2->setColumnHidden(2, true);
     //ui->tableView2->setColumnHidden(6, true);

     ui->tableView2->setSelectionBehavior(QAbstractItemView::SelectRows);
     ui->tableView2->horizontalHeader()->setStretchLastSection(true);

     /* Подключаем сигнал об изменении выбора текущей строки в таблицу
          * к СЛОТу для установки изображения в picLabel
          * */
     connect(ui->tableView2->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                 this, SLOT(slotCurrentPic(QModelIndex)));

     model->select();
    }

Editing::~Editing()
{
    delete ui;
}

void Editing::slotCurrentPic(QModelIndex index)
{
    QPixmap outPixmap = QPixmap(); // Создаём QPixmap, который будет помещаться в picLabel
    /* Забираем данные об изображении из таблицы в качестве QByteArray
     * и помещаем их в QPixmap
     * */
     outPixmap.loadFromData(model->data(model->index(index.row(), 2)).toByteArray());
    // Устанавливаем изображение в picLabel
    image.loadFromData(model->data(model->index(index.row(), 2)).toByteArray());
    ui->picLabel2->setPixmap(outPixmap.scaled(500,400));
    ui->picLabel2->setPixmap(QPixmap::fromImage(image));
    // Отслеживаем изменение положения бегунка
    connect(ui->lightnessSlider, &QSlider::valueChanged, this, &Editing::setLightness);      // Яркость
    connect(ui->saturationSlider, &QSlider::valueChanged, this, &Editing::setSaturation);    // Насыщенность
    // Если яркость или насыщенность изменились, то изменяем изображение
    connect(this, &Editing::lightnessChanged, this, &Editing::changeImageLihtness);
    connect(this, &Editing::saturationChanged, this, &Editing::changeImageSaturation);
}

int Editing::lightness() const
{
    return m_lightness;
}

int Editing::saturation() const
{
    return m_saturation;
}

//функция для устанавки значения яркости
void Editing::setLightness(int lightness)
{
    if (m_lightness == lightness)
        return;

    m_lightness = lightness;
    emit lightnessChanged(lightness);
}

//функция для устанавки значения контрастности
void Editing::setSaturation(int saturation)
{
    if (m_saturation == saturation)
        return;

    m_saturation = saturation;
    emit saturationChanged(saturation);
}

//функция для изменения яркости фото
void Editing::changeImageLihtness(int value)
{

    /* Забираем данные об изображении из таблицы в качестве QByteArray
     * и помещаем их в QPixmap
     * */
    // Устанавливаем изображение в picLabel
    auto width = image.width();
    auto height = image.height();
    /* Проходим по каждому пикселю в картинке и меняем его яркость.
     * Для этого используем класс QColor и цветовую модель hsl.
     * */
    for (auto x = 0; x < width; x++)
    {
        for (auto y = 0; y < height; y++)
        {
            QColor color = image.pixelColor(x, y);
            color.setHslF(color.hslHueF(),
                          color.hslSaturationF(),
                          (qreal)value/100);
            image.setPixelColor(x, y, color);
        }
    }
      ui->picLabel2->setPixmap(QPixmap::fromImage(image));
}

//функция для изменения контрастности фото
void Editing::changeImageSaturation(int value)
{
    /* Забираем данные об изображении из таблицы в качестве QByteArray
     * и помещаем их в QPixmap
     * */
    // Устанавливаем изображение в picLabel
    auto width = image.width();
    auto height = image.height();

    /* Проходим по каждому пикселю в картинке и меняем его яркость.
     * Для этого используем класс QColor и цветовую модель hsl.
     * */
    for (auto x = 0; x < width; x++)
    {
        for (auto y = 0; y < height; y++)
        {
            QColor color = image.pixelColor(x, y);
            color.setHslF(color.hslHueF(),
                          (qreal)value/100,
                          color.lightnessF());
            image.setPixelColor(x, y, color);
        }
    }
   ui->picLabel2->setPixmap(QPixmap::fromImage(image));
}

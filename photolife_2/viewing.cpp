#include "viewing.h"
#include "ui_viewing.h"

Viewing::Viewing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Viewing)
{
    ui->setupUi(this);
    db = new DataBase();
    db->connectToDataBase();
    //QSqlQuery query(db);
    //query.exec("SELECT * FROM ");
    this->setupModel(TABLE,
                    QStringList() << trUtf8("pict_id")
                                  << trUtf8("photo")
                                  << trUtf8("property1")
                                  << trUtf8("property2")
                                  << trUtf8("property3")
                                  << trUtf8("property4")
                                  << trUtf8("property5"));
    this->createUI();



}

void Viewing::setupModel(const QString &tableName, const QStringList &headers){
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    for (int i = 0,j = 0; i < model->columnCount();i++,j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    //Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setSort(0,Qt::AscendingOrder);

}
    void Viewing::createUI()
    {
       // ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(1, true);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
     // ui->tableView->setSelectionMode(QAbstractItenView::SingleSelection);
     // ui->tableView->relizeColumnsToContents();
     // ui->tableView->setEditTriggers(QAbstractItenview::NoEditTriggers);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);

        /* Подключаем сигнал об изменении выбора текущей строки в таблицу
             * к СЛОТу для установки изображения в picLabel
             * */
        connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                    this, SLOT(slotCurrentPic(QModelIndex)));

        model->select();
    }
Viewing::~Viewing()
{
    delete ui;
}
void Viewing::slotCurrentPic(QModelIndex index)
{
    QPixmap outPixmap = QPixmap(); // Создаём QPixmap, который будет помещаться в picLabel
    /* Забираем данные об изображении из таблицы в качестве QByteArray
     * и помещаем их в QPixmap
     * */
    outPixmap.loadFromData(model->data(model->index(index.row(), 1)).toByteArray());
    // Устанавливаем изображение в picLabel
    ui->picLabel->setPixmap(outPixmap.scaled(500,400));
}

#include "editing.h"
#include "ui_editing.h"
#include "dialog_login.h"

Editing::Editing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editing)
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
        ui->tableView2->setColumnHidden(1, true);
        ui->tableView2->setSelectionBehavior(QAbstractItemView::SelectRows);
     // ui->tableView->setSelectionMode(QAbstractItenView::SingleSelection);
     // ui->tableView->relizeColumnsToContents();
     // ui->tableView->setEditTriggers(QAbstractItenview::NoEditTriggers);
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
    outPixmap.loadFromData(model->data(model->index(index.row(), 1)).toByteArray());
    // Устанавливаем изображение в picLabel
    ui->picLabel2->setPixmap(outPixmap.scaled(500,400));
}

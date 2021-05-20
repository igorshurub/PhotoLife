#include "viewing.h"
#include "ui_viewing.h"

Viewing::Viewing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Viewing)
{
    ui->setupUi(this);
}

Viewing::~Viewing()
{
    delete ui;
}

#include "editing.h"
#include "ui_editing.h"
#include "dialog_login.h"

Editing::Editing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editing)
{
    ui->setupUi(this);


}

Editing::~Editing()
{
    delete ui;
}

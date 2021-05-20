#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_login.h"
#include "viewing.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/img/biba/abstract-colors-unreal-clouds.jpg");
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    auth = new Dialog_login();
    view = new Viewing();


    connect(auth, &Dialog_login::ShowMW,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
    view->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    auth->show();
}

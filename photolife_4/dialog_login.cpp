#include "dialog_login.h"
#include "ui_dialog_login.h"
#include "QString"
#include <QMessageBox>
#include "functions.h"


Dialog_login::Dialog_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_login)
{
    ui->setupUi(this);
    ui->label_err->setVisible(false);

    edit = new Editing;

    client_socket = new QTcpSocket(this);
    client_socket->connectToHost("127.0.0.1",33333);

    connect(client_socket,SIGNAL(connected()),SLOT(slot_on_connected()));
    connect(client_socket,SIGNAL(readyRead()),SLOT(slot_ready_read()));
    //Возможно, нужно поменять название слота (read)
}

Dialog_login::~Dialog_login()
{
    delete ui;
    client_socket->close();//возможно надо закомментить
}

void Dialog_login::authorize(QString log, QString pass)
{
     //QString result;
    QString message_to_server;
    message_to_server = log+"&"+pass;
    //qDebug(message_to_server);
    slot_send_to_server(message_to_server);
    //bool flag = (log==QString("1"));
   /*bool flag_login = (log==QString("user"));
    bool flag_pass = (pass==QString("123"));
    //if (result=="authorization yes ")
    if (flag_login == 1 && flag_pass == 1)
    {
        return 1;
    }
    else {
        return 0;
    }
    //return flag;*/
    //

   // if ((ui->lineEdit_Login->text() == "user" && ui->lineEdit_Password->text() == "123") || (ui->lineEdit_Login->text() == "user2" && ui->lineEdit_Password->text() == "124"))
   //     {
   //         return 1;
   //     }
   //     else {
   //         return 0;
   //     }
}


void Dialog_login::on_Ok_clicked()
{

    slot_send_to_server(ui->lineEdit_Login->text() +"&"+ ui->lineEdit_Password->text());
    /*authorize(ui->lineEdit_Login->text(), ui->lineEdit_Password->text());
    if(slot_ready_read()=="authorization yes")
    {
        //edit->show();
        this->close();
        edit->show();
        //ui->label_err->setVisible(true);
    }
    else
    {
        //this->close();
        //edit->show();
        ui->label_err->setVisible(true);
    }*/
    }

void Dialog_login::slot_on_connected()
{
    QMessageBox Msg;
    Msg.setText("Connected!!!");
    Msg.exec();
}

void Dialog_login::slot_ready_read()
{
    QByteArray array;
    std::string message = "";

    while(client_socket->bytesAvailable()>0)
    {
        array = client_socket->readAll();
        message += array.toStdString();
    }
    //QMessageBox Msg;
    //Msg.setText(QString::fromStdString(message));
    //Msg.exec();




    if(message=="authorization yes ")
    {
        //edit->show();
        this->close();
        edit->show();
        //ui->label_err->setVisible(true);
    }
    else
    {
        //this->close();
        //edit->show();
        ui->label_err->setVisible(true);
    }

   /* std::string log = "";
    std::string pass = "";

    qDebug()<<QString::fromStdString(message);
    int pos = message.find("&");
    //message.erase(0,pos+1);//комментируем, чтобы не писать вначале &
    //find login
    pos = message.find("&");
    log = message.substr(0,pos);
    message.erase(0,pos+1);
    // find login
    pos = message.find("&");
    pass = message.substr(0,pos);
    message.erase(0,pos+1);
    //log.pop_back();
    //log.pop_back();
    //pass.pop_back();
    //pass.pop_back();
    */

}

void Dialog_login::slot_send_to_server(QString message)
{
    QByteArray array;
    array.append(message);
    client_socket->write(array);
}

void Dialog_login::slot_disconnected()
{
    client_socket->close();
}

void Dialog_login::on_Cancel_clicked()
{
    this->close();
    emit ShowMW();
}


#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include "functions.h"
MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    foreach(int i, SClients.keys())
    {
      QTextStream os (SClients[i]);
      SClients[i]->close();
      SClients.remove(i);
    }
    server_status=0;
    mTcpServer->close();
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        QTcpSocket *clientSocket= mTcpServer->nextPendingConnection();
        int idusersocs=(int)clientSocket->socketDescriptor();
        SClients[idusersocs]=clientSocket;
        SClients[idusersocs]->write("Hello, World!!! I am echo server!\r\n");
        connect(SClients[idusersocs], &QTcpSocket::readyRead,this,&MyTcpServer::slotServerRead);
        connect(SClients[idusersocs],&QTcpSocket::disconnected,this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *clientSocket=(QTcpSocket*)sender();
    int id =(int)clientSocket->socketDescriptor();
    QByteArray array;
     std::string message= "";

    while(clientSocket->bytesAvailable()>0)
    {
        array =clientSocket->readAll();

    message += array.toStdString();
    }
    std::string log = "";
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
    pass.pop_back();
    pass.pop_back();
    qDebug()<<"login = " <<QString::fromStdString(log)
           <<"password = "<<QString::fromStdString(pass)
          <<"result = "<< authorize(log,pass);
    array.clear();
    array.append(authorize(log,pass));
    clientSocket->write(array);
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket *clientSocket = (QTcpSocket*) sender();
    int id =(int)clientSocket->socketDescriptor();
    clientSocket->close();
    SClients.remove(id);
    qDebug() <<QString::fromUtf8("Client is disconnected \n");
}

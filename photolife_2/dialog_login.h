#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QDialog>
#include "editing.h"
#include <QTcpSocket>

namespace Ui {
class Dialog_login;
}

class Dialog_login : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_login(QWidget *parent = nullptr);
    ~Dialog_login();



private:
    Ui::Dialog_login *ui;
    Editing *edit;
    QTcpSocket *client_socket;


signals:
    void ShowMW();
    void toShowEditing();

private slots:
    void on_Ok_clicked();
    void on_Cancel_clicked();
    void authorize(QString log, QString pass);

private slots:
    void slot_on_connected();
    void slot_ready_read();
    void slot_send_to_server(QString message);
    void slot_disconnected();
};

#endif // DIALOG_LOGIN_H





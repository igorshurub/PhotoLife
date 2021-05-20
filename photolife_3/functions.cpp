#include "functions.h"
#include "QString"
#include "dialog_login.h"
#include "editing.h"
#include "QString"
#include <QMessageBox>

QString authorize(std::string login,std::string password)
{   //edit = new Editing();
    QString result;
    if (login == "u" && password == "1"){

    }
    else {
        result = "authorization error";
        return result;
    }
}

#include "dialog_login.h"
#include "QString"

bool slot_ready_read(std::string message)
{
    QByteArray array;
    message = "";
    message += array.toStdString();
    if(message=="authorization yes ")
    {
        return 1;
    }
    else if (message=="authorization error ")
    {
        return 0;
    }
}



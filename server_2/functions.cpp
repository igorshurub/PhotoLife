#include "functions.h"

QString authorize(std::string log,std::string pass)
{
    QString result;
    if (log == "user" && pass == "123")
        result = "authorization yes ";
    else
        result = "authorization error ";
    if (log == "user2" && pass == "124")
        result = "authorization yes ";
    else
        result = "authorization error ";
    return result;
}

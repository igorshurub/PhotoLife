#include "functions.h"

/* Функция проверки логина/пароля: на вход подаются переменные типа std::string log и pass, в которых
 * находятся данные, введенные пользователем,
если авторизация успешна, получаем сообщение: "authorization yes ", а если нет, то "authorization error " на выходе
*/
QString authorize(std::string log,std::string pass)
{
    QString  result;
    if (log == "user" && pass == "123")
        result = "authorization yes ";
    else   if (log == "user2" && pass == "124")
        result = "authorization yes ";
    else
        result = "authorization error ";
    return result;
}

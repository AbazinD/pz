#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    // Получаем локальное время
    time_t now = time(nullptr);
    tm localTime;
    localtime_r(&now, &localTime);

    // Массивы строк для русских названий дней недели и месяцев
    string daysOfWeek[] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    string months[] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};

    // Выводим текущее время с русскими названиями дней недели и месяцев
    cout << "Сегодня " << daysOfWeek[localTime.tm_wday] << ", " << localTime.tm_mday << " " << months[localTime.tm_mon] << " " << localTime.tm_year + 1900 << " года, ";
    cout << localTime.tm_hour << ":" << localTime.tm_min << ":" << localTime.tm_sec << endl;

    return 0;
}

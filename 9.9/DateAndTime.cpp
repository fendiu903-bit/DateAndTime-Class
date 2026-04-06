#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DateAndTime.h" 
using namespace std;
const int daysRecord_NoLeap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int daysRecord_Leap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

DateAndTime::DateAndTime(int month, int day, int year, int hour, int minute, int second)
{
    setTime(hour, minute, second); 
    setMonth(month);
    setDay(day);
    setYear(year);
}

void DateAndTime::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m); 
    setSecond(s); 
} 

void DateAndTime::setHour(int h)
{
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be 0-23");
} 

void DateAndTime::setMinute(int m)
{
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
} 

void DateAndTime::setSecond(int s)
{
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must be 0-59");
}

unsigned int DateAndTime::getHour() const
{
    return hour;
} 

unsigned int DateAndTime::getMinute() const
{
    return minute;
} 

unsigned int DateAndTime::getSecond() const
{
    return second;
} 

void DateAndTime::printUniversal() const
{
    cout << month << '/' << day << '/' << year << " ";
    cout << setfill('0') << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":" << setw(2) << getSecond();
} 


void DateAndTime::printStandard() const
{
    cout << month << '/' << day << '/' << year << " ";
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
        << ":" << setfill('0') << setw(2) << getMinute()
        << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
} 

void DateAndTime::tick()
{
    if (getSecond() == 59)
    {
        setSecond(00);
        if (getMinute() == 59)
        {
            setMinute(00);
            if (getHour() == 23)
            {
                setHour(00);
				nextDay();
            }
            else
            {
                setHour(getHour() + 1);
            }
        }
        else (setMinute(getMinute() + 1));

    }
    else
    {
        setSecond(getSecond() + 1);
    }
}

bool DateAndTime::checkLeap()
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    return false;
}

int DateAndTime::getDay()
{
    return day;
}

int DateAndTime::getMonth()
{
    return month;
}

int DateAndTime::getYear()
{
    return year;
}
void DateAndTime::setDay(int d)
{
    if (d <= 0 || d > (checkLeap() ? daysRecord_Leap[month - 1] : daysRecord_NoLeap[month - 1]))
    {
        throw invalid_argument("日期无效");
    }
    day = d;
}

void DateAndTime::setMonth(int m)
{
    if (m < 0 || m>12)
    {
        throw invalid_argument("月份无效");
    }
    month = m;
}

void DateAndTime::setYear(int y)
{
    if (y < 1000 || y>3000)
    {
        throw invalid_argument("年份无效");


    }
    year = y;
}

void DateAndTime::nextDay()
{
    if (getDay() == (checkLeap() ? daysRecord_Leap[month - 1] : daysRecord_NoLeap[month - 1]))
    {
        setDay(01);
        if (getMonth() == 12)
        {
            setMonth(1);
            setYear(getYear() + 1);
        }
        else setMonth(getMonth() + 1);
    }
    else setDay(getDay() + 1);

}


void DateAndTime::print()
{
    cout << month << '/' << day << '/' << year;
} 
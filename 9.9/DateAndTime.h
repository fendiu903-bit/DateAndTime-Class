#ifndef _DATEANDTIME_H_
#define _DATEANDTIME_H_

// class Date definition
class DateAndTime
{
public:
    explicit DateAndTime(int = 01, int = 01, int = 2000, int = 00, int = 00, int =00); // default constructor

    // set functions
    void setTime(int, int, int); // set hour, minute, second
    void setHour(int); // set hour (after validation)
    void setMinute(int); // set minute (after validation)
    void setSecond(int); // set second (after validation)
    void tick(); //新定义的函数tick

    // get functions
    unsigned int getHour() const; // return hour
    unsigned int getMinute() const; // return minute
    unsigned int getSecond() const; // return second

    void printUniversal() const; // output time in universal-time format
    void printStandard() const; // output time in standard-time format
    


    void print();
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void nextDay();
    bool checkLeap();
    int getDay();
    int getMonth();
    int getYear();
private:
    unsigned int month;
    unsigned int day;
    unsigned int year;
    unsigned int hour; // 0 - 23 (24-hour clock format)
    unsigned int minute; // 0 - 59
    unsigned int second; // 0 - 59
}; // end class Date

#endif
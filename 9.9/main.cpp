//用于测试的主程序
#include "DateAndTime.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    DateAndTime T1(5, 13, 2025, 22, 23, 59);
    DateAndTime T2(2, 28, 2025, 22, 59, 59);
    DateAndTime T3(2, 28, 2025, 23, 59, 59);
    std::cout << "测试时间1：";
    T1.printStandard();
    std::cout << endl;
    T1.tick();
    std::cout << "一秒过后变为：";
    T1.printStandard();
    std::cout << endl;
    std::cout << endl;

    std::cout << "测试时间2：";
    T2.printStandard();
    std::cout << endl;
    T2.tick();
    std::cout << "一秒过后变为：";
    T2.printStandard();
    std::cout << endl;
    std::cout << endl;

    std::cout << "测试时间3：";
    T3.printStandard();
    T3.tick();
    std::cout << endl;
    std::cout << "一秒过后变为：";
    T3.printStandard();
    std::cout << endl;
    std::cout << endl;


}
//
// Created by 罗瑞笛 on 2023/6/6.
//

#ifndef CHAPTER7_DATA_H
#define CHAPTER7_DATA_H
#include <string>
#include <vector>
using namespace std;
struct Data{
    int ival;
    string s;
};

class Account{
public:
    void calculate(){ amount += amount * interestRate; }
    static double rate() {return interestRate;}
    static void rate(double);

private:
    static constexpr int period = 30; //能给初始值的static变量，必须是 字面值类型且是constexpre
    double daily_tbl[period];
    std::string owner;
    double amount;
    static double interestRate; //所有对象只有这一个
    static double initRate();
    static Account ac1;
    Account *ac2;
    //Account ac3;
};



class Example{
public:
    static constexpr double rate = 6.4;
    static const int vecSize = 20;
    static vector<double> vec; //不能给static 在类内初始化
};



#endif //CHAPTER7_DATA_H

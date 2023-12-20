//
// Created by ����� on 2023/6/6.
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
    static double interestRate; //���ж���ֻ����һ��

    Account& operator= (const Account&)
    {
        return *this;
    }


private:
    static constexpr int period = 30; //�ܸ���ʼֵ��static������������ ����ֵ��������constexpre
    double daily_tbl[period];
    std::string owner;
    double amount;
    static double interestRate2;
    static double initRate();
    static Account ac1;
    Account *ac2;
    //Account ac3;
};



class Example{
public:
    static constexpr double rate = 6.4;
    static const int vecSize = 20;
    static vector<double> vec; //���ܸ�static �����ڳ�ʼ��
};



#endif //CHAPTER7_DATA_H

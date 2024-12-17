//
// Created by ����� on 2023/6/6.
//

#ifndef CHAPTER7_DATA_H
#define CHAPTER7_DATA_H
#include <string>
#include <vector>
#include <iostream>
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
    static const double va_2;   //类内的 static 可见性不止当前的编译单元
//
//    static void func_const_static() const{
//
//    }
};

static int share_va = 15;
static const int share_constva = 1555;

struct tes {
    static int i;              // declares, but doesn't define S::i
    inline static int x = 15;  // defines S::x ， 加上inline 变成定义
};


class this_ptrTest{
public:

    /// const func
    void printANS() const {
        std::cout << "ABA" << std::endl;
    }

    /// 从
    void printANS_noConst() {
        std::cout << "ABA" << std::endl;
    }

};



#endif //CHAPTER7_DATA_H

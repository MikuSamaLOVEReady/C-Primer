//
// Created by ����� on 2023/6/7.
//

#include "Data.h"

//ȫ�ֶ��� һ��
void Account::rate(double value) {
    interestRate = value;
}
vector<double> Example::vec(Example::vecSize);

const double Example::va_2 = 15.3f;
//static const double va_2 = 15.3f;
double Account::initRate(){
    interestRate = 10.0f;
    std::cout << Example::va_2 << std::endl;
    return interestRate;
}

double Account::interestRate = initRate();



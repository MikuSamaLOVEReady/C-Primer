//
// Created by ����� on 2023/6/7.
//

#include "Data.h"

//static ����д����
void Account::rate(double value) {
    interestRate = value;
}


//
double Account::initRate() {
    return 12.0f;
}
double Account::interestRate =123;



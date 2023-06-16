//
// Created by 罗瑞笛 on 2023/6/7.
//

#include "Data.h"

//static 不用写出来
void Account::rate(double value) {
    interestRate = value;
}


//
double Account::initRate() {
    return 12.0f;
}
double Account::interestRate =123;



//
// Created by ����� on 2023/6/7.
//

#include "Data.h"

//ȫ�ֶ��� һ��
void Account::rate(double value) {
    interestRate = value;
}
vector<double> Example::vec(Example::vecSize);

double Account::initRate(){
    interestRate = 10.0f;
}

double Account::interestRate = initRate();


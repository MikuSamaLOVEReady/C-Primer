//
// Created by YX on 2023/12/5.
//

#include "law_no_virtual_fuc_inCtr.h"


Transaction::Transaction()
{
    logTransaction(); //会找不到实现，因为是pure
}

MyTransction::MyTransction(const std::string &loginfo) {

    logTransaction(loginfo);
}


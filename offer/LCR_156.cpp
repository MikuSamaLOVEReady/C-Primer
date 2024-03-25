//
// Created by YX on 2024/1/23.
//

#include "LCR_156.h"

char *cur_str() {

        char arr[15] = "gawgw";
        return arr;
}

std::string cur_str2() {
    std::string sss = "woc";
    return sss;
}

int& getValue() {
    int vaav = 42;
    return vaav;  // 返回左值
}

std::vector<int> getVector() {
    std::vector<int> v = {1, 2, 3};
    return v;  // 返回一个右值
}




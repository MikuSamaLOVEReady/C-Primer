//
// Created by ÂÞÈðµÑ on 2024/1/28.
//

#include "Priority_learn.h"

///3. init Singleton

Priority_sigton_learn* Priority_sigton_learn::instancelPtr = nullptr;
std::priority_queue<int , std::vector<int>> Priority_sigton_learn::q_1{};
std::priority_queue<int , std::vector<int> , std::greater<int>> Priority_sigton_learn::q_2{};

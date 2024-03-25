//
// Created by ÂÞÈðµÑ on 2024/1/28.
//

#ifndef CHAPTER7_PRIORITY_LEARN_H
#define CHAPTER7_PRIORITY_LEARN_H

#include <queue>

///
class Priority_sigton_learn {

public:
    static Priority_sigton_learn* getInstance()
    {
        if(instancelPtr == nullptr)
        {
            instancelPtr = new Priority_sigton_learn();
        }
       return instancelPtr;
    }

    static std::priority_queue<int , std::vector<int>> q_1;
    static std::priority_queue<int , std::vector<int> , std::greater<int>> q_2;


/// 1. ALL CTR should be private
private:
    Priority_sigton_learn(const Priority_sigton_learn& rhs ) = delete;
    Priority_sigton_learn() = default;

    static Priority_sigton_learn* instancelPtr; /// 2. point to self



};


#endif //CHAPTER7_PRIORITY_LEARN_H

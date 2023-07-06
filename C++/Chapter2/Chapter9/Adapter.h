//
// Created by ÂÞÈðµÑ on 2023/6/24.
//

#ifndef CHAPTER7_ADAPTER_H
#define CHAPTER7_ADAPTER_H
#include <stack>
#include <queue>

void adaptor_deque(){
    deque<int> deq;
    stack<int> stk(deq);
}

void priority_queue_vs_queue(){
    priority_queue<int> p_queue;
    p_queue.push(0);
    p_queue.push(1);
    p_queue.push(2);
    p_queue.push(3);
    auto re = p_queue.top();
}





#endif //CHAPTER7_ADAPTER_H

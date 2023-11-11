//
// Created by 罗瑞笛 on 2023/6/24.
//

#ifndef CHAPTER7_ADAPTER_H
#define CHAPTER7_ADAPTER_H
#include <stack>
#include <queue>


void adaptor_deque(){
    deque<int> deq = {1,2,3,4}; //按顺序放入

    stack<int> stk(deq); //拷贝deque中的元素用于stack
    int v= stk.top();
    queue<int> myq(deq);
    vector<int> vvv = {1,2,3,5};
    priority_queue<int> my_pri(vvv.begin(),vvv.end());
    //my_pri.top
    //myq.t X

    std::cout << v << std::endl;
    return;
}

void stack_test(){
    stack<int> intStack;
    for(int i = 0 ; i< 10 ; ++i){
        intStack.push(i);
    }
}

bool brakets(string& s){

    stack<char> brastack;
    for(char sym : s){
        if(sym == '{')
        {
            brastack.push(sym);
        }
        else if(sym == '}'){
            brastack.pop();
        }
    }

    if(brastack.empty()) return true;
    else return false;
}

void priority_queue_vs_queue(){

    stack<string, vector<string>> str_stk;
    //stack<string, vector<string>> str_stk2()

    priority_queue<int> p_queue;
    p_queue.push(0);
    p_queue.push(1);
    p_queue.push(2);
    p_queue.push(3);
    auto re = p_queue.top();
}





#endif //CHAPTER7_ADAPTER_H

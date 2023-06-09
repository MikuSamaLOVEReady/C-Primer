//
// Created by 罗瑞笛 on 2023/5/20.
//

#ifndef OFFER_OFFER_30_H
#define OFFER_OFFER_30_H
#include <vector>
#include <stack>

using namespace std;
//C++实现 stack -> list or vector
//链表stack or arraystack？
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        //默认初始化
        data = vector<int>(0);
        minimin_data = vector<int>(0);
    }

    void push(int x) {
        data.push_back(x);
        if(minimin_data.empty() || x <= minimin_data.back() ){
            minimin_data.push_back(x);
        }else{
            minimin_data.push_back(minimin_data.back());
        }
    }

    void pop() {
        //vector的front为栈底，back为栈顶
        //data.front()
        data.pop_back();
        minimin_data.pop_back();
    }

    int top() {
        return data.back();
    }


    int min() {
        if(minimin_data.empty()){
            return 0;
        }
        else{
            return minimin_data.back();
        }
    }

private:
    vector<int> data;
    vector<int> minimin_data;

};


/// 差值计算,
///
class MinStack2 {
public:
    long long num_min;
    stack<long long> stack_diff; //栈存储与当前插入时 ， (X - 栈区所存在的最小值)差值

    /** initialize your data structure here. */
    MinStack2() {

    }

    void push(int x) {
        if(stack_diff.empty()){
            num_min = x;
            stack_diff.push(0);
        }
        else{
            stack_diff.push(x-num_min);
            if(x-num_min < 0){
                num_min = x;
            }
        }
    }

    void pop() {
        int val = stack_diff.top();
        //当前pop出的元素比插入他的时候的min还要小
        // 需要还原num_min
        if(val<0){
            num_min = num_min - val;
        }
        //如果val 更大，则num_min不改变
        stack_diff.pop();
    }

    int top() {
        int val = stack_diff.top();
        //如果是一个负数，则可以直接返回cur_min 此时它就是全体最小
        if(val<0){
           return num_min;
        }
        //如果是一个正数,则pop出得值+num_min 得到原来的数值
        else{
            return num_min+val;
        }

    }


    int min() {
        return num_min;
    }


};
#endif //OFFER_OFFER_30_H

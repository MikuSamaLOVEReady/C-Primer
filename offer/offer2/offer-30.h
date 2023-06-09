//
// Created by ����� on 2023/5/20.
//

#ifndef OFFER_OFFER_30_H
#define OFFER_OFFER_30_H
#include <vector>
#include <stack>

using namespace std;
//C++ʵ�� stack -> list or vector
//����stack or arraystack��
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        //Ĭ�ϳ�ʼ��
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
        //vector��frontΪջ�ף�backΪջ��
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


/// ��ֵ����,
///
class MinStack2 {
public:
    long long num_min;
    stack<long long> stack_diff; //ջ�洢�뵱ǰ����ʱ �� (X - ջ�������ڵ���Сֵ)��ֵ

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
        //��ǰpop����Ԫ�رȲ�������ʱ���min��ҪС
        // ��Ҫ��ԭnum_min
        if(val<0){
            num_min = num_min - val;
        }
        //���val ������num_min���ı�
        stack_diff.pop();
    }

    int top() {
        int val = stack_diff.top();
        //�����һ�������������ֱ�ӷ���cur_min ��ʱ������ȫ����С
        if(val<0){
           return num_min;
        }
        //�����һ������,��pop����ֵ+num_min �õ�ԭ������ֵ
        else{
            return num_min+val;
        }

    }


    int min() {
        return num_min;
    }


};
#endif //OFFER_OFFER_30_H

//
// Created by di on 2023/5/18.
//

#ifndef OFFER_OFFER_30_H
#define OFFER_OFFER_30_H
#include <stack>

using namespace std;
class MinStack {
public:

    stack<int> s1;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
    }

    void pop() {

    }

    int top() {

    }

    int min() {

    }
};


///��дһ��stack ��Cʵ�֣�
typedef struct tagMinStack{
    int value;
    struct tagMinStack *next;
    struct tagMinStack *pre;
}MyMinStack;

int g_currentNodeNum;
//����ջ��
int g_tempMinNumArray[20000];
int g_index;


#endif //OFFER_OFFER_30_H

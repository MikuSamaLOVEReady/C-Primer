//
// Created by ����� on 2023/5/4.
//

#ifndef OFFER_OFFER_09_H
#define OFFER_OFFER_09_H

#include <stack>

class CQueue {
private:
    std::stack<int> in; //������ɺ�
    std::stack<int> out;

public:
    CQueue() {
    }

    void appendTail(int value) {
        while(!out.empty()){
            in.push( out.top());
            out.pop();
        }
        in.push(value);
    }

    int deleteHead() {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        //���outstackΪ��������pop
        if(out.empty()) return -1;

        int value =  out.top();
        out.pop();
        return value;
    }

};



#endif //OFFER_OFFER_09_H

//
// Created by 罗瑞笛 on 2024/7/19.
//

#ifndef OFFER_LCR_7_19_H
#define OFFER_LCR_7_19_H

#include <queue>

using namespace std;
/// add remove 队列
/// 重点在于max值， 我需要用一个 、
class Checkout {
public:
    Checkout() {

    }

    int get_max() {
        if(max_que.empty()) return -1;
        else return max_que.front()
    }

    void add(int value) {
        que.push(value);
        if( max_que.empty() ) {
            max_que.push(value);
        }else{
            if( max_que.front() <= value )
                max_que.push(value);
            else
                max_que.push(max_que.front());
        }
    }

    int remove() {
        int va = que.front();
        que.pop();
        return va;
    }

private:
    queue<int> que;
    queue<int> max_que;

};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */


#endif //OFFER_LCR_7_19_H

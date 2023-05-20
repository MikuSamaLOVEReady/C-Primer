//
// Created by di on 2023/5/15.
//

#ifndef OFFER_OFFER2_41_H
#define OFFER_OFFER2_41_H


#include <algorithm>
class MovingAverage {
public:
    /** Initialize your data structure here. */
    //窗口大小是多少
    MovingAverage(int size) {
        pre_sum = 0;
        count = 0;
        this->size = size;
        arr = new int[size];
        // 将数组元素设置为 0
        std::fill_n(arr, size, 0);
        //arr = {};
    }

    double next(int val) {
        count++;
        int pre_val =  arr[(count-1)%size];
        arr[(count-1)%size] = val;
        pre_sum += val;
        pre_sum -= pre_val;

        if(count >= size){
            return (double)pre_sum / size;
        }else{
            return (double)pre_sum / count;
        }
    }

private:
    int size;
    int* arr;
    int count;
    int pre_sum;
};



#endif //OFFER_OFFER2_41_H

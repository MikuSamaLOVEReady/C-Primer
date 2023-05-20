//
// Created by 罗瑞笛 on 2023/5/13.
//

#ifndef OFFER_OFFER_15_H
#define OFFER_OFFER_15_H
#include <cstdint>
int hammingWeight(uint32_t n) {
    //可以每次右移动1位，如果值不再改变则返回计数器
    int count  = 0;
    uint32_t pre_n = -1;
    while( (n>>1)!= pre_n ){
        if( (n%2) == 1 ){
            count++;
        }
        pre_n = n>>1;
        n = n>>1;
    }
    return count;
}


#endif //OFFER_OFFER_15_H

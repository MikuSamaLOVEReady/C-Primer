//
// Created by ����� on 2023/5/13.
//

#ifndef OFFER_OFFER_15_H
#define OFFER_OFFER_15_H
#include <cstdint>
int hammingWeight(uint32_t n) {
    //����ÿ�����ƶ�1λ�����ֵ���ٸı��򷵻ؼ�����
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

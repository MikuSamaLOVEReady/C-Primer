//
// Created by ÂÞÈðµÑ on 2023/5/30.
//

#ifndef OFFER_1480_H
#define OFFER_1480_H

#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int cur_sum = 0;
    vector<int> result;
    for( int it : nums){
        cur_sum  += it;
        result.push_back(cur_sum);
    }
    return result;
}


#endif //OFFER_1480_H

//
// Created by di on 2023/5/17.
//

#ifndef OFFER_OFFER_21_H
#define OFFER_OFFER_21_H
#include <vector>

using namespace std;
vector<int> exchange(vector<int>& nums) {
    if(nums.empty()) return vector<int>(0);
    //需要一个起步index odd 与 index even, 但不做任何转换
    int index_odd = 0 , index_even =0;
    while(nums[index_even]%2 != 0){
        index_even++;
        //没有偶数捏
        if(index_even == nums.size()) return nums;
    }
    index_odd = index_even+1;
    if(index_odd == nums.size()) return nums;
    while (true){
         //找到当前最靠前的偶数
        while(nums[index_even]%2 != 0){
            index_even++;
            //没有偶数捏
            if(index_even == nums.size()) return nums;
        }
        int temp = nums[index_even];
        while(nums[index_odd]%2 != 1){
            index_odd++;
            if(index_odd == nums.size()) return nums;
        }
        nums[index_even] = nums[index_odd];
        nums[index_odd] = temp;
    }
}

#endif //OFFER_OFFER_21_H

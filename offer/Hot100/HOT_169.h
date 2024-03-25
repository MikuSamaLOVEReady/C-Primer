
//
// Created by 罗瑞笛 on 2024/3/23.
//

#ifndef OFFER_HOT_169_H
#define OFFER_HOT_169_H

#include <queue>

class Solution_169 {
public:

    // O(n^2)
    int majorityElement_slow(vector<int>& nums) {

        /// priority_queue<int> que;
        unordered_map<int , int > mp;       /// hash 表 O(1)
        map<int , int > order_map ;         /// RB-Tree

        int count = 0;
        int majority = 0;
        for( int num : nums){
            mp[num] += 1;
            if( mp[num] > count){
                majority = num;
                count = mp[num];
            }
        }
        return majority;
    }

    int majorityElement(vector<int>& nums) {

        int cur_major = nums[0];
        int count = 1;

        for(int i = 1 ; i<nums.size() ;++i) {

            ///如果遇到不同的 元素则相减
            if( cur_major != nums[i] )
                count--;
            else
                count++;

            if( count < 0){
                cur_major = nums[i];
                count =1;
            }
        }
        return cur_major;

    }



};

#endif //OFFER_HOT_169_H

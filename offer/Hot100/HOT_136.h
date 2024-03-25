//
// Created by 罗瑞笛 on 2024/3/19.
//

#ifndef OFFER_HOT_136_H
#define OFFER_HOT_136_H

class Solution_136 {
public:
    int singleNumber(vector<int>& nums) {

        /// value ， 对应出现的次数
        map<int , int> pair_map;

        for( int va : nums){
            pair_map[va] += 1;
        }

        for( auto pair : pair_map){
            if (pair.second == 1) return pair.first;
        }
        return -1;
    }
};

#endif //OFFER_HOT_136_H

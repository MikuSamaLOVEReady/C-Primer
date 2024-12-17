//
// Created by 罗瑞笛 on 2024/3/26.
//

#ifndef OFFER_HOT_300_H
#define OFFER_HOT_300_H

#include "../classics-Alg/BinarySearch.h"

class Solution_300 {

public:
    /// greedy
    int lengthOfLIS(vector<int>& nums) {

        vector<int> ans;
        for( int va : nums ) {
            if(ans.empty()) {
                ans.push_back(va);
                continue;
            }
            auto it = binary_search(ans.begin() , ans.end() , va);
            //std::lower_bound()
            if( it != ans.end()) *it = va;  /// 在已在答案中的数字中找第一个 >= va 的值it指向 、并将it的值改变
            else ans.push_back(va);
        }
        return ans.size();
    }


};

#endif //OFFER_HOT_300_H

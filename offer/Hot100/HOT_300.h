//
// Created by ����� on 2024/3/26.
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
            if( it != ans.end()) *it = va;  /// �����ڴ��е��������ҵ�һ�� >= va ��ֵitָ�� ������it��ֵ�ı�
            else ans.push_back(va);
        }
        return ans.size();
    }


};

#endif //OFFER_HOT_300_H

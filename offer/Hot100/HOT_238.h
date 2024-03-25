//
// Created by 罗瑞笛 on 2024/3/18.
//

#ifndef OFFER_HOT_238_H
#define OFFER_HOT_238_H

class Solution_238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int cur = 1;
        int pre = 1;
        for( int va : nums){
            cur *= va;          ///总乘积
        }

        for( int i = 0 ; i<nums.size() ; ++i)
        {
            /// 特殊情况
            if(nums[i] == 0) {
                cur = 1;
                for(int j = 0  ; j<nums.size() ; ++j )  if(j!=i ) cur *= nums[j];
            }
            else{
                cur = cur / nums[i] * pre;
            }
            pre = nums[i];
            res.push_back(cur);
        }
        return  res;
    }
};


#endif //OFFER_HOT_238_H

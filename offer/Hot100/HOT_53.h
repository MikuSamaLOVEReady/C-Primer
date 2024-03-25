//
// Created by 罗瑞笛 on 2024/3/11.
//

#ifndef OFFER_HOT_53_H
#define OFFER_HOT_53_H



class Solution_53 {
public:
    int maxSubArray(vector<int>& nums) {

            if(nums.empty()) return 0;
            vector<int> dp(nums.size() , 0);
            dp[0] = nums[0];
            int res = nums[0];

            for(int i = 1 ; i<nums.size() ;++i)
            {
                if(dp[i-1] < 0) {
                    dp[i] = nums[i];        /// nums[i] 一定会被选入
                 }
                else{
                    dp[i] = dp[i-1] + nums[i];
                }
                dp[i] = max(dp[i-1]+nums[i] , nums[i]);
                if(dp[i] > res)  res = dp[i];
            }
            return res;
    }


};

#endif //OFFER_HOT_53_H

//
// Created by 罗瑞笛 on 2024/3/26.
//

#ifndef OFFER_HOT_198_H
#define OFFER_HOT_198_H


class Solution_198 {
public:
    int rob(vector<int>& nums) {

        if(nums.empty()) return 0;
        vector<vector<int>> dp ( nums.size() , vector<int>(2) );    /// 当前最大收益
        dp[0][0] = 0;           /// dp[i][0]  第i天偷了 ，前提昨天没偷
        dp[0][1] = nums[0];     /// dp[i][1]  第i天没偷、 昨天也没 ｜｜ 昨天偷过了

        for( int i =1 ; i<nums.size() ; ++i ){
            dp[i][0] = dp[i-1][1] + nums[i];
            dp[i][1] = std::max( dp[i-1][1] , dp[i-1][0]);
        }
        return dp[nums.size()-1][0] > dp[nums.size()][1] ? dp[nums.size()-1][0] : dp[nums.size()-1][1];
    }
};

#endif //OFFER_HOT_198_H

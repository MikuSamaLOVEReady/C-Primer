//
// Created by ����� on 2024/3/26.
//

#ifndef OFFER_HOT_198_H
#define OFFER_HOT_198_H


class Solution_198 {
public:
    int rob(vector<int>& nums) {

        if(nums.empty()) return 0;
        vector<vector<int>> dp ( nums.size() , vector<int>(2) );    /// ��ǰ�������
        dp[0][0] = 0;           /// dp[i][0]  ��i��͵�� ��ǰ������û͵
        dp[0][1] = nums[0];     /// dp[i][1]  ��i��û͵�� ����Ҳû ���� ����͵����

        for( int i =1 ; i<nums.size() ; ++i ){
            dp[i][0] = dp[i-1][1] + nums[i];
            dp[i][1] = std::max( dp[i-1][1] , dp[i-1][0]);
        }
        return dp[nums.size()-1][0] > dp[nums.size()][1] ? dp[nums.size()-1][0] : dp[nums.size()-1][1];
    }
};

#endif //OFFER_HOT_198_H

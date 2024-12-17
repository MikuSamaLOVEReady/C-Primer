//
// Created by ����� on 2024/5/12.
//

#ifndef OFFER_DP_416_H
#define OFFER_DP_416_H


class Solution_416 {
public:

    /// ��ǰ����
    bool find_tar(vector<int>& nums , int target){

        /// dp��i����c�� ��ʾǰi��Ԫ�����ܹ���c��
        vector<vector<bool>> dp (nums.size()+1 , vector<bool>(target+1 , false)) ;
        dp[0][0] = true;

        /// ����ÿ��ֻ��
        for(int i = 0 ; i<nums.size() ; ++i){
            for(int c = 0 ; c <= target  ; ++c ){
                if( c < nums[i] ) dp[i+1][c] = dp[i][c];
                else dp[i+1][c]  = dp[i][c] || dp[i][c-nums[i]] ;
            }
        }

        return dp[nums.size()][target];
    }

    bool canPartition(vector<int>& nums) {
        int target  = accumulate(nums.begin() , nums.end() , 0);
        if(target % 2 == 1) return false;
        else target = target/2;     /// capacity = target

        /// ��nums���ҵ�һ������ ���� target
       return find_tar(nums , target);
    }
};

#endif //OFFER_DP_416_H

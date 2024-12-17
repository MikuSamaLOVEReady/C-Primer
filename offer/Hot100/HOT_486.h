//
// Created by 罗瑞笛 on 2024/5/17.
//

#ifndef OFFER_HOT_486_H
#define OFFER_HOT_486_H

class Solution_486 {
public:
    bool predictTheWinner(vector<int>& nums) {

        int left = 0;
        int right = nums.size()-1;

        vector<vector<int>> dp ( nums.size() , vector<int>(nums.size()) );
        for(int i = 0 ; i<nums.size() ; ++i){
            dp[i][i] = nums[i];
        }


        /// nums.size() - 1 已经被初始化过饿了
        for(int i = nums.size() -2  ; i>=0 ; --i ){
            for( int j =  i+1 ; j<= nums.size()-1 ; ++j ){
                dp[i][j] = max( nums[i] - dp[i+1][j]  , nums[j] - dp[i][j-1] );
            }
        }
        return dp[left][right] >= 0 ? true : false;
    }


};

#endif //OFFER_HOT_486_H

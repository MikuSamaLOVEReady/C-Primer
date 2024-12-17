//
// Created by 罗瑞笛 on 2024/5/16.
//

#ifndef OFFER_HOT_322_H
#define OFFER_HOT_322_H

class Solution_322 {
public:
    int coinChange(std::vector<int>& coins, int amount) {

        /// dp[i][j] 在前i个中，构成j时候，所用的最小数字个数。 ///  由于求最小，初始化为amount+1 ， 因为最多全拿1元构成，也就是amount个
        /// 初始化dp[i][j] = 不可能构造（INT_MAX）
        std::vector< std::vector<int> > dp (coins.size()+1 , std::vector<int>(amount+1 , amount+1) );

        dp[0][0] = 0;

        ///  dp[i-1][j]表示 能够构成

        for( int i = 1; i <= coins.size()  ; ++i ){
            for( int j = 1 ; j<= amount ; ++j )
            {
                if(coins[i] > j ) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = min ( dp[i-1][j] , dp[i][j-coins[i]] + 1 );
                }
            }
        }
        int ans =  dp[coins.size()][amount];
        return ans < amount+1 ? ans : -1;
    }
};

#endif //OFFER_HOT_322_H

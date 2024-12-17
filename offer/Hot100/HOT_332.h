//
// Created by 罗瑞笛 on 2024/4/1.
//

#ifndef OFFER_HOT_332_H
#define OFFER_HOT_332_H

class Solution_332 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        /// index  与 amount 一一对应
        vector<int> dp (amount+1 , amount+1);      /// dp[i] 表示构成i所需的硬币个数 、默认值为amount+1、表示不可能组合出结果
        dp[0] = 0;

        for( int i = 1 ; i < dp.size() ; i++ ) {
            /// dp[i] = min { dp[i- coin1] + 1 , dp[i - coin2] + 1 , dp[i - coin3] + 1  ....... dp[i - coin_j] + 1}
            for( int j = 0 ; j < coins.size()  ; j++ ) {
                if( i - coins[j] >= 0){
                    dp[i] = min ( dp[i] , dp[ i-coins[j] ] + 1);
                }
            }
        }
        if(dp[amount]  == amount+1) return -1;
        return dp[amount];  ///
    }
};

#endif //OFFER_HOT_332_H

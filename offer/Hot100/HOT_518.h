//
// Created by 罗瑞笛 on 2024/5/16.
//

#ifndef OFFER_HOT_518_H
#define OFFER_HOT_518_H

class Solution_518 {
public:
    int change(int amount, vector<int>& coins) {

        /// dp[i][j] = 前i个元素构成j有几种办法
        vector<vector<int>> dp( coins.size()+1 , vector<int>(amount+1)  );
        dp[0][0] = 1;

        for( int i = 0; i < coins.size() ; ++i) {

            for( int j = 0 ;  j <= amount ; ++j ){
                /// 背包容量不够
                 if( j < coins[i] ) dp[i+1][j] = dp[i][j];
                 else
                     /// dp[i+1][j] = dp[i][j] + dp[i][j-coins[i]]; ///前i个元素，则coin当前index = i
                     /// 可重复选择
                     dp[i+1][j] = dp[i][j] + dp[i+1][j-coins[i]];
            }
        }

        return dp[coins.size()][amount];
    }


    ///仅仅考虑能够组合成 amount 、 没有考虑顺序
    int change_fast(int amount, vector<int>& coins) {

        /// dp[j] =  构成j有几种办法
        vector<int> dp( amount+1  );
        dp[0] = 1;

        for(int i = 0 ; i< coins.size() ; ++i ) {
            for( int j = coins[i] ; j <= amount  ; ++j ){
                dp[j] = dp[j] + dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};


#endif //OFFER_HOT_518_H

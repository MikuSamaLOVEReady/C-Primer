//
// Created by ����� on 2024/5/16.
//

#ifndef OFFER_HOT_518_H
#define OFFER_HOT_518_H

class Solution_518 {
public:
    int change(int amount, vector<int>& coins) {

        /// dp[i][j] = ǰi��Ԫ�ع���j�м��ְ취
        vector<vector<int>> dp( coins.size()+1 , vector<int>(amount+1)  );
        dp[0][0] = 1;

        for( int i = 0; i < coins.size() ; ++i) {

            for( int j = 0 ;  j <= amount ; ++j ){
                /// ������������
                 if( j < coins[i] ) dp[i+1][j] = dp[i][j];
                 else
                     /// dp[i+1][j] = dp[i][j] + dp[i][j-coins[i]]; ///ǰi��Ԫ�أ���coin��ǰindex = i
                     /// ���ظ�ѡ��
                     dp[i+1][j] = dp[i][j] + dp[i+1][j-coins[i]];
            }
        }

        return dp[coins.size()][amount];
    }


    ///���������ܹ���ϳ� amount �� û�п���˳��
    int change_fast(int amount, vector<int>& coins) {

        /// dp[j] =  ����j�м��ְ취
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

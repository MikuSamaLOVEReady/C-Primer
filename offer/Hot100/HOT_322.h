//
// Created by ����� on 2024/5/16.
//

#ifndef OFFER_HOT_322_H
#define OFFER_HOT_322_H

class Solution_322 {
public:
    int coinChange(std::vector<int>& coins, int amount) {

        /// dp[i][j] ��ǰi���У�����jʱ�����õ���С���ָ����� ///  ��������С����ʼ��Ϊamount+1 �� ��Ϊ���ȫ��1Ԫ���ɣ�Ҳ����amount��
        /// ��ʼ��dp[i][j] = �����ܹ��죨INT_MAX��
        std::vector< std::vector<int> > dp (coins.size()+1 , std::vector<int>(amount+1 , amount+1) );

        dp[0][0] = 0;

        ///  dp[i-1][j]��ʾ �ܹ�����

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

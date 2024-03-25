//
// Created by ����� on 2024/3/24.
//

#ifndef OFFER_HOT_309_H
#define OFFER_HOT_309_H

class Solution_309 {
public:
    int maxProfit(vector<int>& prices) {

        ///  dp[i][0] δ����    -> 1.��������_����CD   -> 2.���յ���Ҳû�С����ڷ�CD�׶Ρ���Ӱ�����졿
        ///  dp[i][2] δ����   -> 1.�������� ������CD�׶Ρ�Ӱ�����졿
        ///// **** ֮����Ҫ��δ���з�Ϊ ��������������������� Ŀ����Ϊ���ڳ���״̬�� ����
        ///  dp[i][1] ����     -> 1.�����ǵ�������(���ձض�����)  2.Ҳ���������ճ���ת�Ƶ�����

        ///dp ��ʾ��i���ӯ��
        vector<vector<int> > dp( prices.size() , vector<int>(3));

        /// ��ʼ״̬
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;

        for(int i = 1 ; i<prices.size() ;++i) {

            dp[i][0] = std::max( dp[i-1][2] , dp[i-1][0]);
            dp[i][1] = std::max( dp[i-1][0] - prices[i] , dp[i-1][1]  );
            dp[i][2] =   dp[i-1][1] + prices[i];
        }

        return dp[prices.size() -1][0] >=  dp[prices.size() -1][2] ? dp[prices.size() -1][0] : dp[prices.size() -1][2];
    }
};

#endif //OFFER_HOT_309_H

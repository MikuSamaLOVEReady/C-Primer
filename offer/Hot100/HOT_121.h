//
// Created by ����� on 2024/3/25.
//

#ifndef OFFER_HOT_121_H
#define OFFER_HOT_121_H

class Solution_121 {
public:

    /// ��ι���_�۳�
    int maxProfit_multi(vector<int>& prices) {
        vector<vector<int>> dp ( prices.size() , vector<int>(2) );
        dp[0][0] = 0;     /// dp[i][0] δ����
        dp[0][1] = -prices[0];     /// dp[i][1] ���չ���
        for(int i = 1 ; i<prices.size() ; ++i){
            dp[i][0] = std::max(dp[i-1][0] , dp[i-1][1]+prices[i] ); /// ��ǰδ���� --> 1.����δ���С�ת��  2.���ճ��н�������
            dp[i][1] = std::max(dp[i-1][1] , dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }

    /// Ŀ������������ʱ�򡢿�������ĳһ��
    int maxProfit_wrong(vector<int>& prices) {
        vector<vector<int>> dp ( prices.size() , vector<int>(2) );
        dp[0][0] = 0;     /// dp[i][0] δ����
        dp[0][1] = -prices[0];     /// dp[i][1] ���չ���
        for(int i = 1 ; i<prices.size() ; ++i){
            dp[i][0] = std::max(dp[i-1][0] , dp[i-1][1]+prices[i] ); /// ��ǰδ���� --> 1.����δ���С�ת��  2.���ճ��н�������
            dp[i][1] = std::max(dp[i-1][1] , dp[i-1][0] - prices[i]);
        }
        /// ǰ��������ÿһ�ʲ������������
        int pre = dp[0][0];
        int max_op  = 0;
        for(int i = 1 ; i<prices.size() ; ++i ){
            int cur_op = dp[i][0] - pre;     /// ÿ����֮��Ĳ�ֵ
            if(max_op < cur_op) max_op = cur_op;
            pre = dp[i][0];
        }
        return max_op;
    }

    int maxProfit_timeOut(vector<int>& prices) {

        ///�����ڵ�i������
        int cur_va = 0;
        for(int i =0 ; i < prices.size() ;i++){
            for(int j= i+1 ; j < prices.size() ; j++ ){
                int dis = prices[j] - prices[i];
                if( dis > cur_va ) cur_va = dis;
            }
        }
        return cur_va;
    }


    /// ��¼һ����ǰmin�� �������飬cur-min ����ÿһ��Ԫ�ض������ڵ�����������minʱ����
    int maxProfit(vector<int>& prices) {

        int min_price = 1e9;
        int max_profit = 0;
        for( int price : prices){
            int cur_va = price - min_price;
            min_price = min_price > price ? price : min_price;
            max_profit = max_profit > cur_va ? max_profit : cur_va;
        }
        return max_profit;
    }


};


#endif //OFFER_HOT_121_H

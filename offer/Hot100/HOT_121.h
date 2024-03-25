//
// Created by 罗瑞笛 on 2024/3/25.
//

#ifndef OFFER_HOT_121_H
#define OFFER_HOT_121_H

class Solution_121 {
public:

    /// 多次购入_售出
    int maxProfit_multi(vector<int>& prices) {
        vector<vector<int>> dp ( prices.size() , vector<int>(2) );
        dp[0][0] = 0;     /// dp[i][0] 未持有
        dp[0][1] = -prices[0];     /// dp[i][1] 当日购入
        for(int i = 1 ; i<prices.size() ; ++i){
            dp[i][0] = std::max(dp[i-1][0] , dp[i-1][1]+prices[i] ); /// 当前未持有 --> 1.昨日未持有、转移  2.昨日持有今日卖出
            dp[i][1] = std::max(dp[i-1][1] , dp[i-1][0] - prices[i]);
        }
        return dp[prices.size()-1][0];
    }

    /// 目的是最大化利益的时候、可能牺牲某一步
    int maxProfit_wrong(vector<int>& prices) {
        vector<vector<int>> dp ( prices.size() , vector<int>(2) );
        dp[0][0] = 0;     /// dp[i][0] 未持有
        dp[0][1] = -prices[0];     /// dp[i][1] 当日购入
        for(int i = 1 ; i<prices.size() ; ++i){
            dp[i][0] = std::max(dp[i-1][0] , dp[i-1][1]+prices[i] ); /// 当前未持有 --> 1.昨日未持有、转移  2.昨日持有今日卖出
            dp[i][1] = std::max(dp[i-1][1] , dp[i-1][0] - prices[i]);
        }
        /// 前后做差、获得每一笔操作的最大利润
        int pre = dp[0][0];
        int max_op  = 0;
        for(int i = 1 ; i<prices.size() ; ++i ){
            int cur_op = dp[i][0] - pre;     /// 每两步之间的差值
            if(max_op < cur_op) max_op = cur_op;
            pre = dp[i][0];
        }
        return max_op;
    }

    int maxProfit_timeOut(vector<int>& prices) {

        ///假设在第i天买入
        int cur_va = 0;
        for(int i =0 ; i < prices.size() ;i++){
            for(int j= i+1 ; j < prices.size() ; j++ ){
                int dis = prices[j] - prices[i];
                if( dis > cur_va ) cur_va = dis;
            }
        }
        return cur_va;
    }


    /// 记录一个当前min、 遍历数组，cur-min 访问每一个元素都当成在当日卖出、在min时买入
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

//
// Created by 罗瑞笛 on 2024/3/24.
//

#ifndef OFFER_HOT_309_H
#define OFFER_HOT_309_H

class Solution_309 {
public:
    int maxProfit(vector<int>& prices) {

        ///  dp[i][0] 未持有    -> 1.昨日卖掉_今日CD   -> 2.昨日单纯也没有【处于非CD阶段、不影响明天】
        ///  dp[i][2] 未持有   -> 1.今日卖掉 【处于CD阶段、影响明天】
        ///// **** 之所以要把未持有分为 当日卖出、和其他情况， 目的是为了在持有状态下 区分
        ///  dp[i][1] 持有     -> 1.可能是当日买入(昨日必定不卖)  2.也可能是昨日持有转移到今日

        ///dp 表示第i天的盈利
        vector<vector<int> > dp( prices.size() , vector<int>(3));

        /// 初始状态
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

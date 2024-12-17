//
// Created by 罗瑞笛 on 2024/7/18.
//

#ifndef OFFER_122_STOCK_TIME2_H
#define OFFER_122_STOCK_TIME2_H

#include <vector>
using namespace  std;

class Solution_122 {
public:
    /// 第i天结束时 , has_stock = true  ，持有股票时的收益
    /// 第i天结束时 , has_stock = false ，未持有股票时的收益
    int dfs( int i , bool has_stock ,vector<int>& prices ) {

        if(i < 0 && !has_stock) return 0;
        if(i < 0 && has_stock) return -INT_MAX;

        /// 当前i结束时， 拥有 stock  = i-1 无stock - prices[i] 买入 || 之前就一直拥有
        if( has_stock )
            return  max( dfs(i-1 , true , prices)
                    , dfs(i-1 , false , prices) - prices[i] );

        /// 当前i结束时， 未拥有stock  = i-1 无stock  || + prices[i] 卖出

        return max( dfs(i-1 , false , prices)
                , dfs(i-1 , true , prices) + prices[i] );

    }
    ///  递归从最终结果开始  ///
    int maxProfit(vector<int>& prices) {
        int m = prices.size()-1;
        return dfs(m , false , prices);
    }



};

#endif //OFFER_122_STOCK_TIME2_H

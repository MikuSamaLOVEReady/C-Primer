//
// Created by ����� on 2024/7/18.
//

#ifndef OFFER_122_STOCK_TIME2_H
#define OFFER_122_STOCK_TIME2_H

#include <vector>
using namespace  std;

class Solution_122 {
public:
    /// ��i�����ʱ , has_stock = true  �����й�Ʊʱ������
    /// ��i�����ʱ , has_stock = false ��δ���й�Ʊʱ������
    int dfs( int i , bool has_stock ,vector<int>& prices ) {

        if(i < 0 && !has_stock) return 0;
        if(i < 0 && has_stock) return -INT_MAX;

        /// ��ǰi����ʱ�� ӵ�� stock  = i-1 ��stock - prices[i] ���� || ֮ǰ��һֱӵ��
        if( has_stock )
            return  max( dfs(i-1 , true , prices)
                    , dfs(i-1 , false , prices) - prices[i] );

        /// ��ǰi����ʱ�� δӵ��stock  = i-1 ��stock  || + prices[i] ����

        return max( dfs(i-1 , false , prices)
                , dfs(i-1 , true , prices) + prices[i] );

    }
    ///  �ݹ�����ս����ʼ  ///
    int maxProfit(vector<int>& prices) {
        int m = prices.size()-1;
        return dfs(m , false , prices);
    }



};

#endif //OFFER_122_STOCK_TIME2_H

//
// Created by ����� on 2024/3/20.
//

#ifndef OFFER_HOT_96_H
#define OFFER_HOT_96_H

class Solution_96 {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);  /// n���ڵ��ܹ��ɶ��ٸ� ����������    // size = n+1 ��n��ʾ1,2,3...n���ĸ���
        dp[0]  = 1;
        dp[1]  = 1;

        ///  ������������ 1 , 2 , 3 .... n �ֱ�Ϊroot��ʱ���ܹ��ɶ��ٸ��� ��Ϊ:f(i)

        /// G(n) = G(0) * G(n?1) + G(1) * (n?2) +...+ G(n?1) * G(0); /// �۲췢�� G��n�� ֮ǰһ��Ҫ����� G(n-1)
        ///  ���� i ������n
        for(int i = 2 ; i <= n  ; ++i)
            for( int j = 1 ; j<= i ; ++j )      /// ���� i ͬ�������� n
                dp[i] += dp[i-j] * dp[j-1];
        return dp[n];
    }
};

#endif //OFFER_HOT_96_H

//
// Created by 罗瑞笛 on 2024/3/20.
//

#ifndef OFFER_HOT_96_H
#define OFFER_HOT_96_H

class Solution_96 {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);  /// n个节点能构成多少个 二叉搜索树    // size = n+1 （n表示1,2,3...n）的个数
        dp[0]  = 1;
        dp[1]  = 1;

        ///  二叉搜索，以 1 , 2 , 3 .... n 分别为root的时候能构成多少个树 记为:f(i)

        /// G(n) = G(0) * G(n?1) + G(1) * (n?2) +...+ G(n?1) * G(0); /// 观察发现 G（n） 之前一定要先算出 G(n-1)
        ///  这里 i 更像是n
        for(int i = 2 ; i <= n  ; ++i)
            for( int j = 1 ; j<= i ; ++j )      /// 这里 i 同样更像是 n
                dp[i] += dp[i-j] * dp[j-1];
        return dp[n];
    }
};

#endif //OFFER_HOT_96_H

//
// Created by ÂÞÈðµÑ on 2024/3/12.
//

#ifndef OFFER_HOT_70_H
#define OFFER_HOT_70_H

class Solution_70 {
public:
    int climbStairs_timeOut(int n) {
        if(n == 1) return 1;
        else if( n== 2) return 2;

        return climbStairs(n-1) + climbStairs(n-2);
    }

    int climbStairs(int n) {

        if( n ==1 )return 1;
        else if(n ==2 ) return 2;
        else if( n==0 ) return 0;

        vector<int> dp(n+1);
        dp[0] = 0; dp[1] = 1 ; dp[2] = 2;
        for(int i = 3 ; i<=n ; ++i )
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

#endif //OFFER_HOT_70_H

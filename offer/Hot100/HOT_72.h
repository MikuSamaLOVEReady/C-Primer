//
// Created by 罗瑞笛 on 2024/3/12.
//

#ifndef OFFER_HOT_72_H
#define OFFER_HOT_72_H

class Solution_72 {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return dfs(n , m , word1 , word2 );
    }

    int dfs( int i , int j  , string& s , string& d  )
    {
        if( i<0 ) return j+1;
        if( j<0 ) return i+1;

        if( s[i] == d[j] ) {
            return dfs( i-1 , j-1 , s , d);
        } else {
            return min( min( dfs(i-1,j ,s,d) ,dfs(i , j-1 ,s ,d) ) ,
                        dfs( i-1 , j-1 , s , d) ) + 1;
        }
    }

    int minDistance_dp(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp( n+1 , vector<int>( m+1 ) );
        /// 初始化
        for( int i = 0 ; i<m+1 ; ++i ){
            dp[0][i] = i;
        }

        /// 这些都是想象、没有什么缘由
        for( int i = 0 ; i < n+1 ; ++i ){
            dp[i+1][0] = i+1;       /// 这里初始化的时候 是从 f[i+1] = i+1
            for( int j = 0 ; j < m+1 ; ++j){
                if( word1[i] == word2[j] ) {
                    dp[i+1][j+1] = dp[i][j];
                }
                else{
                    dp[i+1][j+1] = min ( min(dp[i][j+1] , dp[i+1][j]) , dp[i][j] ) + 1;
                }
            }
        }

        return dp[n][m];
    }


};

#endif //OFFER_HOT_72_H

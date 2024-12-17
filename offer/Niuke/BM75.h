//
// Created by 罗瑞笛 on 2024/9/7.
//

#ifndef OFFER_BM75_H
#define OFFER_BM75_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str1 string字符串
     * @param str2 string字符串
     * @return int整型
     */
    int editDistance(string str1, string str2) {
        // write code here
        vector<vector<int>> dp( str1.size() , vector<int>(str2.size() , 0) );

        /// 这种初始化有误，不能保证 dp[0][2]也被运算出来、并且如果index按照str的来算，无法解决输入为空的情况
//        if( str1[0] == str2[0] )
//            dp[0][0] = 0;           ///  dp[i][j] str1[i] 变成 str2[j] 所需要的操作
//        else
//            dp[0][0] = 1;
//
//        if( str1[0] == str2[1]  ) /// 由于需要 i-1 j-1
//            dp[0][1] = 1;
//        else
//            dp[0][1] = dp[0][0] + 1;
//
//        if( str1[1] == str2[0] )
//            dp[1][0] = 1;
//        else
//            dp[1][0] = dp[0][0] + 1;

        for(int i = 1 ; i<str1.size() ; ++i){
            for( int j = 1 ; j<str2.size() ; ++j){
                if( str1[i] == str2[j] )
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min( min( dp[i][j-1] , dp[i-1][j] ) , dp[i-1][j-1] ) + 1;
            }
        }

        return dp[str1.size()-1][str2.size()-1];
    }
};

#endif //OFFER_BM75_H

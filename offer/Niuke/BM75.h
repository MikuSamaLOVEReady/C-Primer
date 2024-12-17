//
// Created by ����� on 2024/9/7.
//

#ifndef OFFER_BM75_H
#define OFFER_BM75_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param str1 string�ַ���
     * @param str2 string�ַ���
     * @return int����
     */
    int editDistance(string str1, string str2) {
        // write code here
        vector<vector<int>> dp( str1.size() , vector<int>(str2.size() , 0) );

        /// ���ֳ�ʼ�����󣬲��ܱ�֤ dp[0][2]Ҳ������������������index����str�����㣬�޷��������Ϊ�յ����
//        if( str1[0] == str2[0] )
//            dp[0][0] = 0;           ///  dp[i][j] str1[i] ��� str2[j] ����Ҫ�Ĳ���
//        else
//            dp[0][0] = 1;
//
//        if( str1[0] == str2[1]  ) /// ������Ҫ i-1 j-1
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

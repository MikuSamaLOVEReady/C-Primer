//
// Created by 罗瑞笛 on 2024/2/24.
//

#ifndef OFFER_HOT_05_H
#define OFFER_HOT_05_H

#include <string>
#include <vector>

using namespace std;

class Solution_05 {

public:
    string longestPalindrome(string s) {
        vector<vector<bool>> is_huiwen(s.size(), vector<bool>(s.size()));
        //vector<vector<int>> is_huiwen2( s.size() , vector<int>(s.size()));

        int maxLen = 0;
        int max_begin = 0;

        for( int i =0 ; i< s.size()-1 ; ++i)
        {
            is_huiwen[i][i] = true;
        }

        for(int L = 2 ; L<s.size() ; ++L)
        {
            for(int i = 0 ; i< s.size()-1 ;++i)
            {
                int j = i + L - 1; /// 字符串末尾字符

                if( j >= s.size() ) break;

                /// 头尾直接不同、一定不是回文
                if(  s[i] != s[j])
                {
                    is_huiwen[i][j] = false;
                }
                else
                {
                    if( j-i == 2) is_huiwen[i][j] = true;
                    else    is_huiwen[i][j] = is_huiwen[i+1][j-1];
                }

                /// 更新结果
                if(is_huiwen[i][j] && maxLen < L )
                {
                    maxLen =  L;
                    max_begin = i;
                }
            }
        }

        return  s.substr(max_begin,maxLen);
    }

};


#endif //OFFER_HOT_05_H

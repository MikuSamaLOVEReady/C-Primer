//
// Created by 罗瑞笛 on 2023/5/24.
//

#ifndef OFFER_05_H
#define OFFER_05_H
#include <string>

using namespace std;

//
bool isHuiwen(string& s1, int low , int high){
    //两个指针(head  tail) 一个从后往前，一个从前往后
    while(low < high){
        if(s1[low] == s1[high]){
            low++;
            high--;
        }
        else{
            return false;
        }
    }
    return true;
}

string longestPalindrome(string s) {
    string result;
    int pre_length = -1;
    for(int i = 0 ; i < s.size() ; i++){
        for(int j = i ; j<s.size() ; j++ ){
            bool huiwen = isHuiwen(s ,i,j);
            if(huiwen && (j-i)>pre_length ){
                    pre_length = j-i;
                    result =  s.substr(i,j-i+1);
            }
        }
    }
    return result;
}

//
string longestPalindrome2(string s){
    int n = s.size();
    if(n<2){
        return s;
    }

    int maxLen = 1;
    int begin = 0;

    //dp[i][j] 状态转移函数，表示s[i....j]是否是回文
    vector<vector<int>> dp(n , vector<int>(n));
    for(int i = 0 ; i<n ; i++){
        dp[i][i] = true;
    }

    // 递推 枚举字串长度，因为dp的本质就是先解决出一个个的子问题
    // 再用子问题构成大问题的解
    // 默认两个及以上起步
    for(int L = 2 ; L <= n ;L++){
        //枚举 left
        for(int i = 0  ; i<n ; i++){
            // j - i + 1 = L
            int j = L + i - 1;

            //如果超出字符串长度，则表示当前长度结束，该从下一个开始
            if(j>=n){
                break;
            }

            //把首尾两个字母先判断
            if( s[i] != s[j]){
                dp[i][j] = false;
            }
            // 除去前后俩字母后
            else{
                //如果还剩 1个字母或者0个字母的话，则一定是会文
                if( j-i <3){
                    dp[i][j] = true;
                }
                //如果剩余过多，则根据组件找答案
                else{
                    dp[i][j] = dp[i+1][j-1];
                }
            }

            if(dp[i][j] && j-i+1 > maxLen){
                maxLen = j-i+1;
                begin = i;
            }
        }
    }

    return s.substr(begin,maxLen);
}

#endif //OFFER_05_H

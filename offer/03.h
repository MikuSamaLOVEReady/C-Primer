//
// Created by 罗瑞笛 on 2023/5/25.
//

#ifndef OFFER_03_H
#define OFFER_03_H
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 可以替换成 unordered_set<char> occ;
bool has_char(char target , string& sub){
    for(char c : sub){
        if(c == target){
            return true;
        }
    }
    return false;
}

//无重复子串 // DP 空间不够
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n < 1 ) return 0;
    else if ( n ==1 ) return 1;
    int maxlen = 1;
    //dp[i][j] 表示 s[i...j]不含重复字符
    vector<vector<int>> dp(n , vector<int>(n));
    for(int i = 0 ; i<n ; i++){
        dp[i][i] = true;
    }

    //从短到到长
    for(int L = 2 ; L<= n ; ++L){
        //left起点
        for(int i = 0 ;  i<n ; ++i ){
            //right
             int j = L+i-1;
             if(j >= n) break;
             //如果s[i...j-1]不重复,
             if(dp[i][j-1]){
                 //取出目前最后一个字符,判断是否在其中
                 //s[j]
                 string s_pre = s.substr(i,L-1);
                 if(has_char(s[j],s_pre)){
                     dp[i][j] = false;
                 }
                 else{
                     dp[i][j] = true;
                     if(maxlen < L)  maxlen = L;
                 }
             }
             //如果重复了则直接跳过
        }
    }

    return maxlen;
}

//
int lengthOfLongestSubstring2(string s){
    //存放当前搜索过程中，所检查到的所有不重复字符
   unordered_set<char> occ;
   int n = s.size();
   int rk = -1 , ans = 0;

   for(int i = 0 ; i<n ; ++i){
       //每次i增加后，向后
       if(i!=0){
            occ.erase(s[i-1]);
       }
       //如果右指针没有超界，并且字符不重复,则可以继续延长字符串
       while(rk+1 < n && !occ.count(s[rk+1])){
           occ.insert(s[rk+1]);
           ++rk;
       }
        ans = max(ans,rk-i+1);
   }

   return ans;
}



#endif //OFFER_03_H

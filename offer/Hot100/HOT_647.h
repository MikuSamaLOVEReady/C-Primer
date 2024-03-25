//
// Created by 罗瑞笛 on 2024/3/22.
//

#ifndef OFFER_HOT_647_H
#define OFFER_HOT_647_H

class Solution_647 {
public:
    int countSubstrings(string s) {

        vector<vector<char>> dp (s.size() , vector<char>(s.size()) );
        int res = 0;
        for(int i = 0 ; i<s.size() ;i++){
            dp[i][i] = true;
            res++;
        }
        for( int len = 2; len <= s.size() ; ++len) {
            for(int i = 0 ; i <= s.size() - len ; ++i){
                /// 先判定_头尾
                if ( s[i] == s[i+len-1] ){
                    /// 再判定 掐头去尾后中间长度是否有元素
                    if( i+1 <= i+len-2 ) {
                        dp[i][i+len-1] = dp[i+1][i+len-2];
                        if(dp[i][i+len-1])  res++;
                    }
                    /// 如果不存在元素、即总长度=2（只含有头尾）
                    else {
                        dp[i][i+len-1] = true;
                        res++;
                    }
                }
                else{
                    dp[i][i+len-1] = false;
                }
            }
        }

        return res;
    }
};


#endif //OFFER_HOT_647_H

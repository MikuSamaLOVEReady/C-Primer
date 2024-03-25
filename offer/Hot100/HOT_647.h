//
// Created by ����� on 2024/3/22.
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
                /// ���ж�_ͷβ
                if ( s[i] == s[i+len-1] ){
                    /// ���ж� ��ͷȥβ���м䳤���Ƿ���Ԫ��
                    if( i+1 <= i+len-2 ) {
                        dp[i][i+len-1] = dp[i+1][i+len-2];
                        if(dp[i][i+len-1])  res++;
                    }
                    /// ���������Ԫ�ء����ܳ���=2��ֻ����ͷβ��
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

//
// Created by ����� on 2023/5/25.
//

#ifndef OFFER_03_H
#define OFFER_03_H
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// �����滻�� unordered_set<char> occ;
bool has_char(char target , string& sub){
    for(char c : sub){
        if(c == target){
            return true;
        }
    }
    return false;
}

//���ظ��Ӵ� // DP �ռ䲻��
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n < 1 ) return 0;
    else if ( n ==1 ) return 1;
    int maxlen = 1;
    //dp[i][j] ��ʾ s[i...j]�����ظ��ַ�
    vector<vector<int>> dp(n , vector<int>(n));
    for(int i = 0 ; i<n ; i++){
        dp[i][i] = true;
    }

    //�Ӷ̵�����
    for(int L = 2 ; L<= n ; ++L){
        //left���
        for(int i = 0 ;  i<n ; ++i ){
            //right
             int j = L+i-1;
             if(j >= n) break;
             //���s[i...j-1]���ظ�,
             if(dp[i][j-1]){
                 //ȡ��Ŀǰ���һ���ַ�,�ж��Ƿ�������
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
             //����ظ�����ֱ������
        }
    }

    return maxlen;
}

//
int lengthOfLongestSubstring2(string s){
    //��ŵ�ǰ���������У�����鵽�����в��ظ��ַ�
   unordered_set<char> occ;
   int n = s.size();
   int rk = -1 , ans = 0;

   for(int i = 0 ; i<n ; ++i){
       //ÿ��i���Ӻ����
       if(i!=0){
            occ.erase(s[i-1]);
       }
       //�����ָ��û�г��磬�����ַ����ظ�,����Լ����ӳ��ַ���
       while(rk+1 < n && !occ.count(s[rk+1])){
           occ.insert(s[rk+1]);
           ++rk;
       }
        ans = max(ans,rk-i+1);
   }

   return ans;
}



#endif //OFFER_03_H

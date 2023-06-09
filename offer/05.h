//
// Created by ����� on 2023/5/24.
//

#ifndef OFFER_05_H
#define OFFER_05_H
#include <string>

using namespace std;

//
bool isHuiwen(string& s1, int low , int high){
    //����ָ��(head  tail) һ���Ӻ���ǰ��һ����ǰ����
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

    //dp[i][j] ״̬ת�ƺ�������ʾs[i....j]�Ƿ��ǻ���
    vector<vector<int>> dp(n , vector<int>(n));
    for(int i = 0 ; i<n ; i++){
        dp[i][i] = true;
    }

    // ���� ö���ִ����ȣ���Ϊdp�ı��ʾ����Ƚ����һ������������
    // ���������⹹�ɴ�����Ľ�
    // Ĭ��������������
    for(int L = 2 ; L <= n ;L++){
        //ö�� left
        for(int i = 0  ; i<n ; i++){
            // j - i + 1 = L
            int j = L + i - 1;

            //��������ַ������ȣ����ʾ��ǰ���Ƚ������ô���һ����ʼ
            if(j>=n){
                break;
            }

            //����β������ĸ���ж�
            if( s[i] != s[j]){
                dp[i][j] = false;
            }
            // ��ȥǰ������ĸ��
            else{
                //�����ʣ 1����ĸ����0����ĸ�Ļ�����һ���ǻ���
                if( j-i <3){
                    dp[i][j] = true;
                }
                //���ʣ����࣬���������Ҵ�
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

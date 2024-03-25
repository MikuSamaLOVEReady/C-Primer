//
// Created by ����� on 2024/2/28.
//

#ifndef OFFER_HOT_32_H
#define OFFER_HOT_32_H

#include <string>
#include <stack>

class Solution_32 {
public:
    int longestValidParentheses_WRONG(string s) {
            int max_len = 0;
            int cur_result = 0;

            stack<char> stk;
            for(char ch : s)
            {
                if(ch == '(')
                {
                    stk.push(ch);
                }
                /// ch == ')' ����������š��򵯳������š����Ҹ����+2
                /// ���û�������š����ʾƥ��ʧ�ܡ�result���������һ��
                else{
                    if(!stk.empty() && stk.top()=='(')
                    {
                        stk.pop();
                        cur_result += 2;
                    }
                    else if (stk.empty() || stk.top() ==')') {
                        max_len = max_len > cur_result ? max_len : cur_result;
                        cur_result = 0;
                        continue;
                    }
                }
            }
                /// �����ַ���������ɡ��������һ�ν���Ա�
            max_len = max_len > cur_result ? max_len : cur_result;
            return max_len;
    }


    /// DP ��̬�滮
    /// \param s
    /// \return
    int longestValidParentheses(string s) {

        vector<int> dp(s.size() , 0);
        // int dp[s.size()] ; //��Щcompiler��֧��
        int max_len = 0;

        for( int i = 1 ; i<s.size() ; ++i )
        {
           if( s[i] == ')')
           {
               /// ���ǰһλ�պ�ƥ�䡢������ⲿ ���ڲ�Ϊ2
               if( s[i-1] == '(' )
               {
                  dp[i] =  2 +  ( i>=2 ? dp[i-2] : 0 );
               }
               ///     [ i-dp[i-1]-2] �ⲿ ���� [ i-dp[i-1]-1 ] [][] �ڲ� [i]
               else if (  i-dp[i-1]-1 >=0 && s[i-dp[i-1]-1] == '(' )
               {
                   dp[i] = 2 + dp[i-1] + ( i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0 );           /// 2 + �ڲ� + �ⲿ
                                                                    /// ���� i-dp[i-1]-2 Ҳ����Խ��
               }
               max_len = max_len > dp[i] ? max_len : dp[i];
           }
        }
        return max_len;

    }






};

#endif //OFFER_HOT_32_H

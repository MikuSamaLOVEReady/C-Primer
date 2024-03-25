//
// Created by 罗瑞笛 on 2024/2/28.
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
                /// ch == ')' 如果有左括号、则弹出左括号、并且给结果+2
                /// 如果没有左括号、则表示匹配失败、result清零访问下一个
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
                /// 最终字符串搜索完成、则做最后一次结果对比
            max_len = max_len > cur_result ? max_len : cur_result;
            return max_len;
    }


    /// DP 动态规划
    /// \param s
    /// \return
    int longestValidParentheses(string s) {

        vector<int> dp(s.size() , 0);
        // int dp[s.size()] ; //有些compiler不支持
        int max_len = 0;

        for( int i = 1 ; i<s.size() ; ++i )
        {
           if( s[i] == ')')
           {
               /// 如果前一位刚好匹配、则计算外部 、内部为2
               if( s[i-1] == '(' )
               {
                  dp[i] =  2 +  ( i>=2 ? dp[i-2] : 0 );
               }
               ///     [ i-dp[i-1]-2] 外部 ｜｜ [ i-dp[i-1]-1 ] [][] 内部 [i]
               else if (  i-dp[i-1]-1 >=0 && s[i-dp[i-1]-1] == '(' )
               {
                   dp[i] = 2 + dp[i-1] + ( i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0 );           /// 2 + 内部 + 外部
                                                                    /// 这里 i-dp[i-1]-2 也可能越界
               }
               max_len = max_len > dp[i] ? max_len : dp[i];
           }
        }
        return max_len;

    }






};

#endif //OFFER_HOT_32_H

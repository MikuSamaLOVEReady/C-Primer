//
// Created by ����� on 2024/2/1.
//

#ifndef OFFER_BM49_H
#define OFFER_BM49_H
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

static  stack<int> value;
static  stack<char> symbol;

   static int solve(string s) {
        char pre_op = 'x';
        std::string s1 = "";        /// ƴ������
        unordered_map<int , int> unorder_{
                {1,2}, {1,3}
        };

        for(int i = 0 ; i<s.size() ; ++i)
        {
            char ch = s[i];
            if( ch == '+' || ch == '-' || ch == '(' || ch == '*')
            {
                symbol.push(ch);
            }
            else if( ch == ')')
            {
                while (symbol.top() != '(') {
                    //char opera = symbol.top();
//                    symbol.pop();
                    cal();
//                    if(opera == '+')
//                    {
//                        int va1 = value.top();
//                        value.pop();
//                        int va2 = value.top();
//                        value.pop();
//                        value.push(va1 + va2);
//                    }
//                    else if( opera == '-')
//                    {
//                        int va1 = value.top();  // ����
//                        value.pop();
//                        int va2 = value.top();  // ������
//                        value.pop();
//                        value.push(va2 - va1);
//                    }
//                    else if(opera == '*')
//                    {
//                        int va1 = value.top();
//                        value.pop();
//                        int va2 = value.top();
//                        value.pop();
//                        value.push(va2 * va1);
//                    }
                    //ch = symbol.top();      /// ��ȡ��һ����������
                }
                //���� '(' �� �����pop
                symbol.pop();
            }
                /// �����������Ҫ�ж�ǰһ���Ƿ�Ϊ*���������������Ҫ��������
            else{
                while( ch >= '0' && ch <= '9' )
                {
                    s1 += ch;       ///������
                    i++;
                    ch = s[i];
                }
                i--;
                value.push(std::stoi(s1));
                s1.clear();
                if(pre_op == '*')
                {
                    int va1 = value.top();  // ����
                    value.pop();
                    int va2 = value.top();  // ������
                    value.pop();
                    value.push(va2 * va1);
                    symbol.pop();
                }
            }
            pre_op = ch;
        }

        while(!symbol.empty())
        {
            char op = symbol.top();
            symbol.pop();
            int va1 = value.top();  // ����
            value.pop();
            int va2 = value.top();  // ������
            value.pop();
            if(op == '+')
            {
                value.push(va1 + va2);
            }
            else if( op == '-')
            {
                value.push(va2 - va1);
            }
            else if(op == '*')
            {
                value.push(va2 * va1);
            }
        }

        return value.top();
   }


   /// ����ʱ����
   static void cal()
   {
       if(symbol.empty() || value.empty() || value.size() < 2) return ;
       char opera = symbol.top();
       symbol.pop();
       int va1 = value.top();
       value.pop();
       int va2 = value.top();
       value.pop();

       if(opera == '+') value.push(va1 + va2);
       else if( opera == '-') value.push(va2 - va1);
       else if(opera == '*') value.push(va2 * va1);
   }

   /// �ص㣺��push ������ʱ,stack�� �� ��ǰ���� ���ȼ��� ʱ���Ȱ�stack�еĲ�����������
   ///
   static int solve_2(){


   }

};


#endif //OFFER_BM49_H

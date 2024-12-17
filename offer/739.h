//
// Created by ����� on 2024/7/20.
//

#ifndef OFFER_739_H
#define OFFER_739_H

#include <vector>
#include <stack>

using namespace std;
class Solution_739 {
public:
    vector<int> dailyTemperatures_back_to_front(vector<int>& temperatures) {
        vector<int> res(temperatures.size() , -1);
        /// �Ӻ���ǰ
        stack<int> st; ///�ݼ���stack �����ϴ洢�Ӻ���ǰ�� 3��4��6 ��size �� ������5��ʱ�򵯳�����С�ģ�Ѱ��6��index����
        /// stack�д�Ķ���index �� stack.top() ��ʾ��ǰ����
        for(int i = temperatures.size()-1 ; i >= 0 ;i--) {

            if(st.empty()) st.push(i);
            /// С��top��Ԫ��ʱ���ɻ��size
            if( temperatures[i] < temperatures[st.top()] ) {
                res[i] = st.top() - i;
            }
            else{
                /// ���topԪ�رȵ�ǰС����û��Ҫ����
                while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                    st.pop();
                }
                if(st.empty()) res[i] = 0;
                else res[i] = st.top() - i;
            }
            st.push(i);  ///1,1,4,2,1,1,0,0
        }
        return res;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size() , -1);
        stack<int> st;
        /// ��ǰ����stack�д�ʲô���滹δ�ҵ����ȵ�Ԫ��index
        for( int i = 0 ; i<temperatures.size() ;++i ) {

            if(st.empty()) st.push(i);
            /// ����ȴ�Ѱ�ҵ���໹С����ֱ��push
            if(  temperatures[i] <= temperatures[st.top()] ){
                st.push(i);
            }else{
                /// ��� tem[i] �Ȳ�����stack�еĴ������ֱ�Ӹ���res
                while(  !st.empty() && temperatures[i] > temperatures[st.top()] ) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }

        /// �ѻ�������ȫ����0
        while(!st.empty()){
            res[st.top()] = 0;
            st.pop();
        }

        return res;
    }


};

#endif //OFFER_739_H

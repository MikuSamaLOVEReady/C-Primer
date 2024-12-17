//
// Created by 罗瑞笛 on 2024/7/20.
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
        /// 从后向前
        stack<int> st; ///递减的stack 本质上存储从后向前的 3、4、6 的size ， 当遇到5的时候弹出比他小的，寻找6的index即可
        /// stack中存的都是index 。 stack.top() 表示当前近的
        for(int i = temperatures.size()-1 ; i >= 0 ;i--) {

            if(st.empty()) st.push(i);
            /// 小于top的元素时即可获得size
            if( temperatures[i] < temperatures[st.top()] ) {
                res[i] = st.top() - i;
            }
            else{
                /// 如果top元素比当前小，则没必要保留
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
        /// 从前到后，stack中存什么？存还未找到长度的元素index
        for( int i = 0 ; i<temperatures.size() ;++i ) {

            if(st.empty()) st.push(i);
            /// 如果比待寻找的左侧还小，则直接push
            if(  temperatures[i] <= temperatures[st.top()] ){
                st.push(i);
            }else{
                /// 如果 tem[i] 比残留在stack中的大，则可以直接更新res
                while(  !st.empty() && temperatures[i] > temperatures[st.top()] ) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }

        /// 把还残留的全部给0
        while(!st.empty()){
            res[st.top()] = 0;
            st.pop();
        }

        return res;
    }


};

#endif //OFFER_739_H

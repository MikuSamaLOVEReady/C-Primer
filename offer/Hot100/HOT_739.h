//
// Created by 罗瑞笛 on 2024/3/21.
//

#ifndef OFFER_HOT_739_H
#define OFFER_HOT_739_H

#include <stack>

class Solution_739 {
public:

    vector<int> dailyTemperatures_timeOut(vector<int>& temperatures) {
            vector<int> res;
            for( int i = 0 ; i<temperatures.size() ; ++i ) {
                int cur_tar = temperatures[i];
                /// 如果遍历完、后续不再有更高温度则直接下一轮
                bool find_higher = false;
                for(int j = i+1 ; j < temperatures.size() ; ++j){
                    if(cur_tar <  temperatures[j]){
                        res.push_back(j-i);
                        find_higher = true;
                        break;
                    }
                }
                if(!find_higher) res.push_back(0);
            }
            return res;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures){

        /// <index , value>
            stack<pair<int , int>> cur_visit;
            vector<int> res(temperatures.size() , 0 );
            for( int i = 0 ; i<temperatures.size() ;++i ){
                int value = temperatures[i];
                /// 如果没有元素、或者当前stack中【之前放入的值】 比 当前【后面的值】更大 则继续放入
                if( cur_visit.empty() || cur_visit.top().second >= value ) {
                    cur_visit.emplace(i , value);   /// emplace ??? 直接拿着元素构造
                    continue;
                }
                while ( !cur_visit.empty() && cur_visit.top().second < value ){
                    ///  i 表示本次待插入的元素的index
                    res[ cur_visit.top().first ] =  i - cur_visit.top().first ;
                    cur_visit.pop();
                }
                cur_visit.emplace(i , value);
            }

            while(cur_visit.empty()) ///如果还有空余、则在他们之后没有更高温度
            {
                res[cur_visit.top().first] = 0;
                cur_visit.pop();
            }
            return res;
    }


};


#endif //OFFER_HOT_739_H

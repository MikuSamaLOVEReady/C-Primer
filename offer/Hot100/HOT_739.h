//
// Created by ����� on 2024/3/21.
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
                /// ��������ꡢ���������и����¶���ֱ����һ��
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
                /// ���û��Ԫ�ء����ߵ�ǰstack�С�֮ǰ�����ֵ�� �� ��ǰ�������ֵ������ ���������
                if( cur_visit.empty() || cur_visit.top().second >= value ) {
                    cur_visit.emplace(i , value);   /// emplace ??? ֱ������Ԫ�ع���
                    continue;
                }
                while ( !cur_visit.empty() && cur_visit.top().second < value ){
                    ///  i ��ʾ���δ������Ԫ�ص�index
                    res[ cur_visit.top().first ] =  i - cur_visit.top().first ;
                    cur_visit.pop();
                }
                cur_visit.emplace(i , value);
            }

            while(cur_visit.empty()) ///������п��ࡢ��������֮��û�и����¶�
            {
                res[cur_visit.top().first] = 0;
                cur_visit.pop();
            }
            return res;
    }


};


#endif //OFFER_HOT_739_H

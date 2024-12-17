//
// Created by 罗瑞笛 on 2024/7/11.
//

#ifndef OFFER_HOT_621_H
#define OFFER_HOT_621_H

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace  std;
class Solution_621 {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char , int> task_map;
        /// 统计 完后 这个map 便可产生2个vector
        /// 只要每次 选择 在时间范围内，并且数量最多的即可
        for( const char& ch : tasks ){
            task_map[ch]++;
        }

        /// 其实 究竟是哪个task 已经不重要关键是个数
        vector<int>  next_time;
        vector<int>  rest_count;
        for( auto pair : task_map ){
            next_time.push_back(1);
            rest_count.push_back(pair.second);
        }

        int cur_time =1;
        for(int i = 0 ; i<tasks.size() ; ++i){
            ///筛选符合时间的
            int min_time = INT_MAX;
            for(int j = 0 ; j<next_time.size() ; ++j){
                if(rest_count[j] != 0){
                    min_time = min(min_time , next_time[j]);
                }
            }
            cur_time = min_time;    /// 需要比较这个吗？ time = max(time, minNextValid);
            ///筛选个数最多的

            int best_index = -1;
            for( int k = 0 ; k<rest_count.size() ; ++k ){
                if(rest_count[k] !=0 && cur_time >= next_time[k]){      /// 指筛选剩余仍无 ， 并且时间满足的情况
                      if(  best_index ==-1 && rest_count[k] > rest_count[best_index] ){
                          best_index = k;
                      }
                }
            }
            next_time[best_index] = cur_time + n +1;
            rest_count[best_index]--;
        }
        return cur_time;
    }
};


#endif //OFFER_HOT_621_H

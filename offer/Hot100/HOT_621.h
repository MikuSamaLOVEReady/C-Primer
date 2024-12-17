//
// Created by ����� on 2024/7/11.
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
        /// ͳ�� ��� ���map ��ɲ���2��vector
        /// ֻҪÿ�� ѡ�� ��ʱ�䷶Χ�ڣ������������ļ���
        for( const char& ch : tasks ){
            task_map[ch]++;
        }

        /// ��ʵ �������ĸ�task �Ѿ�����Ҫ�ؼ��Ǹ���
        vector<int>  next_time;
        vector<int>  rest_count;
        for( auto pair : task_map ){
            next_time.push_back(1);
            rest_count.push_back(pair.second);
        }

        int cur_time =1;
        for(int i = 0 ; i<tasks.size() ; ++i){
            ///ɸѡ����ʱ���
            int min_time = INT_MAX;
            for(int j = 0 ; j<next_time.size() ; ++j){
                if(rest_count[j] != 0){
                    min_time = min(min_time , next_time[j]);
                }
            }
            cur_time = min_time;    /// ��Ҫ�Ƚ������ time = max(time, minNextValid);
            ///ɸѡ��������

            int best_index = -1;
            for( int k = 0 ; k<rest_count.size() ; ++k ){
                if(rest_count[k] !=0 && cur_time >= next_time[k]){      /// ָɸѡʣ������ �� ����ʱ����������
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

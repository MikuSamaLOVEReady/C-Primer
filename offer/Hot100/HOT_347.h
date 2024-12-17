//
// Created by ����� on 2024/3/27.
//

#ifndef OFFER_HOT_347_H
#define OFFER_HOT_347_H

#include <map>
#include <queue>
#include <unordered_map>

class Solution_347 {
public:
    vector<int> topKFrequent_wrong(vector<int>& nums, int k) {
        /// { num , ���ִ��� }
        map<int , int> num_ocr;
        vector<int> res;

        for ( int va : nums){
            num_ocr[va] += 1;
        }

        auto it = num_ocr.begin();
        while ( k > 0 ){
            res.push_back(it->first);
            it++;
            k--;
        }

        return res;
    }
    struct count_num{
        int num;
        int count;
        count_num(int num , int count):num(num) , count(count){}

        /// С��heap
         bool operator < (const count_num& rhs) {
            this->count < rhs.count;
        }
    };


    /// ���Ϊ true ��ʾ lhs Ӧ���� rhs֮��
    /// �� std::priority_queue ���������У�����Ƚ������� true����ô�ⱻ����Ϊ��һ������Ӧ���ڶ����е�λ�õ��ڵڶ�������
    /// return true��ʱ�� ��������ǰ��
    static bool count_large( pair<int , int>& lhs , pair<int , int>& rhs){
            return lhs.second < rhs.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        /// decltype (func) vs  decltype (&func)
        priority_queue< pair<int , int> , vector<pair<int , int>> , decltype(&count_large) >  pri_que(count_large);   ///  ���ñȽϱ�׼����[Ĭ�ϴ����]
        unordered_map < int , int > un_map;       /// < value �� count >
        vector<int> res;

        /// ͳ�Ƴ��ָ���
        for(int num : nums) {
            un_map[num] += 1;
        }

        for( auto va : un_map){
            pri_que.emplace(va);
        }

        while( k > 0){
            res.push_back(pri_que.top().first);
            pri_que.pop();
            k--;
        }
        return res;
    }


};

#endif //OFFER_HOT_347_H

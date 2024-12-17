//
// Created by 罗瑞笛 on 2024/3/27.
//

#ifndef OFFER_HOT_347_H
#define OFFER_HOT_347_H

#include <map>
#include <queue>
#include <unordered_map>

class Solution_347 {
public:
    vector<int> topKFrequent_wrong(vector<int>& nums, int k) {
        /// { num , 出现次数 }
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

        /// 小根heap
         bool operator < (const count_num& rhs) {
            this->count < rhs.count;
        }
    };


    /// 如果为 true 表示 lhs 应该在 rhs之后
    /// 在 std::priority_queue 的上下文中，如果比较器返回 true，那么这被解释为第一个参数应该在队列中的位置低于第二个参数
    /// return true的时候 排在容器前面
    static bool count_large( pair<int , int>& lhs , pair<int , int>& rhs){
            return lhs.second < rhs.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        /// decltype (func) vs  decltype (&func)
        priority_queue< pair<int , int> , vector<pair<int , int>> , decltype(&count_large) >  pri_que(count_large);   ///  设置比较标准函数[默认大根、]
        unordered_map < int , int > un_map;       /// < value 、 count >
        vector<int> res;

        /// 统计出现个数
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

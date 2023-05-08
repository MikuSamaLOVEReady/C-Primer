//
// Created by 罗瑞笛 on 2023/5/5.
//

#ifndef OFFER_OFFER_079_H
#define OFFER_OFFER_079_H
#include <vector>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> universal;      //存放结果
    vector<vector<int>> universal_copy; //在组合新元素时候参照的副本
    //从输入选取元素
    for(vector<int>::iterator it = nums.begin() ; it!=nums.end() ; ++it){
        //每次组合新元素前复制一个副本用做参考
        universal_copy = universal;
        //从已经保存的副本开始组合
        for(auto it_uni = universal_copy.begin() ; it_uni != universal_copy.end() ; ++it_uni){
            (*it_uni).emplace_back(*it);// 为之前的结果添加与新元素组合的结果
            universal.emplace_back(*it_uni);
        }
        //添加新元素，注意需要是vector形式
        vector<int> single = {*it};
        universal.emplace_back(single);
    }
    vector<int> empty = {};
    universal.emplace_back(empty);
    return universal;
}


#endif //OFFER_OFFER_079_H

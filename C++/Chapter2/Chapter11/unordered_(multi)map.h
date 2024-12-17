//
// Created by 罗瑞笛 on 2024/8/25.
//

#ifndef CHAPTER7_UNORDERED__MULTI_MAP_H
#define CHAPTER7_UNORDERED__MULTI_MAP_H

#include <map>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
namespace unordered_map_VS_unordered_Multimap{

    void insert_ALL_MAP_test(){
        unordered_map<int, string> u_map; ///key 无法重复？那我插入相同的key会怎么样？
        unordered_multimap<int , string> u_mulMap;
        multimap<int , string> mulMap;
        map<int , string> NnormalMap;

        /// 返回指向insert的bucket的iterator, 以及是否插入成功的bool
        /// 只要是不带nulti的，insert都会返回一个，当前是否插入成功
        auto it_1 = u_map.insert(make_pair(10,"MIKU"));
        auto it_2 =  u_map.insert(make_pair(10,"SAMA"));

        auto it_N1 = NnormalMap.insert(make_pair(10,"MIKU"));
        auto it_N2 = NnormalMap.insert(make_pair(10,"SAMA"));

        /// 返回指向对应目标的迭代器、
        auto it_m1 =  u_mulMap.insert(make_pair(10,"MIKU"));
        auto it_m2 = u_mulMap.insert(make_pair(10,"SAMA"));

        auto it_mmp1 =  mulMap.insert(make_pair(10,"MIKU"));
        auto it_mmmp2 = mulMap.insert(make_pair(10,"SAMA"));

        std::cout << "END" << std::endl;
    }

    void insert_ALL_SET_test(){

        set<int> normal_set;
        unordered_set<int> u_set;
        multiset<int> mulSet;
        unordered_multiset<int> u_multiSet;

        auto it_N1 = normal_set.insert(10);
        auto it_N2 = normal_set.insert(10);

        auto it_US1 = u_set.insert(10);
        auto it_US2 = u_set.insert(10);

        auto it_MS1 = mulSet.insert(10);
        auto it_MS2 = mulSet.insert(10);

        std::cout << *it_MS1 << std::endl;
        std::cout << *it_MS2 << std::endl;

        std::cout << "END" << std::endl;
    }



}



#endif //CHAPTER7_UNORDERED__MULTI_MAP_H

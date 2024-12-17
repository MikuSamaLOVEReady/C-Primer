//
// Created by 罗瑞笛 on 2023/5/26.
//

#ifndef CHAPTER7_UNORDERED_MAP_H
#define CHAPTER7_UNORDERED_MAP_H

#include <unordered_map>
#include <iostream>

namespace un_map{

    void unorder_interface(){
        std::unordered_map<int , int> mp {
                {1,2},
                {2,3},
                {4,5},
                {5,6}
        };

        /// 查
        /// 抛出异常、直接崩溃 --TODO:异常处理
//        if( mp.at(51) ){
//            std::cout << " woc " << std::endl;
//        }

        if( mp.find(51) == mp.end() ){
            std::cout << " not find " << std::endl;
        }

        if( mp.count(51) == 0 ){
            std::cout << " not find 51 " << std::endl;
        }

        if( mp.count(4) == 1 ){
            std::cout << " find 4 " << std::endl;
        }


        /// 增

    }


}


#endif //CHAPTER7_UNORDERED_MAP_H

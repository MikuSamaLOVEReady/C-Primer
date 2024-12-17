//
// Created by 罗瑞笛 on 2023/11/7.
//

#ifndef CHAPTER7_DECLTYPE_TEST_H
#define CHAPTER7_DECLTYPE_TEST_H

/// --- type 1 ---
//template <typename T1 , typename T2>
//decltype(x+y) add(T1 x , T2 y);

#include <set>
#include <iostream>
template <typename T1 , typename T2>
auto add(T1 x , T2 y) -> decltype(x+y);


/// --- type2 ---  metaprogramming?????
template <typename T>
void test18_decltype(T obj){

    typedef typename decltype(obj)::iterator iType; // 这个更好？

    typedef typename T::iterator iType;
}



/// --- type3 --- 传递一个lambda的类型
// cmp 是一个obj？

auto cmp = [] (const int& i1 , const int& i2){

};



/// --- lambada test ---
void lambte(){
    int tobefound = 5;
    auto lambdal = [tobefound] (int val) {return val == tobefound;};
    lambdal(15);        /// 函数对象，类型未知
    std::set<int , decltype(lambdal)> coll(lambdal);

}

void mutable_test(){

    int va_t1 = 15;
    auto labt1 = [=]() mutable ->int{
        //va_t1 = 1566;   /// Cannot assign to a variable captured by copy in a non-mutable lambda
        va_t1 = 77;
    };

    std::cout << va_t1 << std::endl;
}




#endif //CHAPTER7_DECLTYPE_TEST_H

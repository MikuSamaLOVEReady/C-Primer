//
// Created by ����� on 2023/11/7.
//

#ifndef CHAPTER7_DECLTYPE_TEST_H
#define CHAPTER7_DECLTYPE_TEST_H

/// --- type 1 ---
//template <typename T1 , typename T2>
//decltype(x+y) add(T1 x , T2 y);

template <typename T1 , typename T2>
auto add(T1 x , T2 y) -> decltype(x+y);


/// --- type2 ---  metaprogramming?????
template <typename T>
void test18_decltype(T obj){

    typedef typename decltype(obj)::iterator iType; // ������ã�

    typedef typename T::iterator iType;
}



/// --- type3 --- ����һ��lambda������
// cmp ��һ��obj��

auto cmp = [] (const int& i1 , const int& i2){

};



/// --- lambada test ---
void lambte(){
    int tobefound = 5;
    auto lambdal = [tobefound] (int val) {return val == tobefound;};
    lambdal(15);

    std::set<int , decltype(lambdal)> coll(lambdal);

}




#endif //CHAPTER7_DECLTYPE_TEST_H
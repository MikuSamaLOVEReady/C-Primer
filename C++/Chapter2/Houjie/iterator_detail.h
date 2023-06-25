//
// Created by 罗瑞笛 on 2023/6/21.
//

#ifndef CHAPTER7_ITERATOR_DETAIL_H
#define CHAPTER7_ITERATOR_DETAIL_H
#include <iterator>
#include <typeinfo>

using namespace std;
template<typename I>
void display_cate(I itr){
    typename iterator_traits<I>::iterator_category category; //明确指示iterator_category是一个类型名而不是一个变量还是函数。
    std::cout << "typeid(itr).name()" << typeid(itr).name() << std::endl;
}



#endif //CHAPTER7_ITERATOR_DETAIL_H

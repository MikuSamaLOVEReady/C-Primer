//
// Created by ����� on 2023/6/21.
//

#ifndef CHAPTER7_ITERATOR_DETAIL_H
#define CHAPTER7_ITERATOR_DETAIL_H
#include <iterator>
#include <typeinfo>

using namespace std;
template<typename I>
void display_cate(I itr){
    typename iterator_traits<I>::iterator_category category; //��ȷָʾiterator_category��һ��������������һ���������Ǻ�����
    std::cout << "typeid(itr).name()" << typeid(itr).name() << std::endl;
}



#endif //CHAPTER7_ITERATOR_DETAIL_H

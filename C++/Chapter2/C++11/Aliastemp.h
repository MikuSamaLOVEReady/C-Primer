//
// Created by ����� on 2023/11/5.
//

#ifndef CHAPTER7_ALIASTEMP_H
#define CHAPTER7_ALIASTEMP_H


//ģ��-����
template <typename T>
using Vec = std::vector<T, allocator<T>>;


//#define Vec<T> template
//template<typename int> std::vector<>

template<typename Container , typename T>
void test_move(Container cntr , T elem){

    Container value;
    std::cout << value << std::endl;
}

template <typename T>
void printDepp(T value){
    T::print(); //
}

template <typename Container , typename T>
void test_moveable(Container cntr , T elem){
    //Container<T> c; // �����container ��һ����ģ�棬������������ͨ��

    //FIXME ������취��ģ�涨���ʱ�򣬾�Ҫ��֪compiler Container��һ��ģ��
}


template <typename T,
          template<class > class Container> //��������ʱ��͸�֪Container������һ��ģ��
class XCls
{
private:
    Container<T> c;

public:
    XCls(){
        std::cout << "woc" << std::endl;
    }
};








#endif //CHAPTER7_ALIASTEMP_H

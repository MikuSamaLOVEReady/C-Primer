//
// Created by 罗瑞笛 on 2023/11/5.
//

#ifndef CHAPTER7_ALIASTEMP_H
#define CHAPTER7_ALIASTEMP_H


//模版-别名
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
    //Container<T> c; // 这里的container 不一定是模版，编译器不允许通过

    //FIXME 所以想办法在模版定义的时候，就要告知compiler Container是一种模版
}


template <typename T,
          template<class > class Container> //在声明的时候就告知Container自身是一个模版
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

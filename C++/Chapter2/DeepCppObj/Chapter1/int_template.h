//
// Created by 罗瑞笛 on 2024/7/10.
//

#ifndef CHAPTER7_INT_TEMPLATE_H
#define CHAPTER7_INT_TEMPLATE_H

#include <iostream>
template< class type , int dim>
class Point{

public:
    Point();
    Point( type coords[dim] ){

    }

};


/// 静态多态
template<typename T>
T larger(T a, T b){
    return a > b ? a:b;
}


/// 返回值类型不同，不能重载
//int print(double d) {
//    std::cout << "Integer: " << i << std::endl;
//    return 1;
//}
//
//void print(double d) {
//    std::cout << "Double: " << d << std::endl;
//}


#endif //CHAPTER7_INT_TEMPLATE_H

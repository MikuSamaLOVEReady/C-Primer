//
// Created by ����� on 2024/7/10.
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


/// ��̬��̬
template<typename T>
T larger(T a, T b){
    return a > b ? a:b;
}


/// ����ֵ���Ͳ�ͬ����������
//int print(double d) {
//    std::cout << "Integer: " << i << std::endl;
//    return 1;
//}
//
//void print(double d) {
//    std::cout << "Double: " << d << std::endl;
//}


#endif //CHAPTER7_INT_TEMPLATE_H

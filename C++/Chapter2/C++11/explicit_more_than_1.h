//
// Created by 罗瑞笛 on 2023/11/2.
//

#ifndef CHAPTER7_EXPLICIT_MORE_THAN_1_H
#define CHAPTER7_EXPLICIT_MORE_THAN_1_H

struct Complex
{
    int real , imag;

public:

    //单一实参
    Complex(int re , int im = 0) : real(re) , imag(im){}
};



#endif //CHAPTER7_EXPLICIT_MORE_THAN_1_H

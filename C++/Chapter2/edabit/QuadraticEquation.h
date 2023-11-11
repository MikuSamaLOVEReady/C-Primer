//
// Created by 罗瑞笛 on 2023/11/1.
//

#ifndef CHAPTER7_QUADRATICEQUATION_H
#define CHAPTER7_QUADRATICEQUATION_H
#include <cmath>

int quaraticEquation( int a , int b , int c){

    double delta = b*b - 4*a*c;
    int result = (sqrt(delta) - b) / (2*a);
    return result;
    // 模版参数存在，方便自动根据参数选择函数求根类型
}


int countTrue( std::vector<bool> arr ) {

    int result = 0;
    for(auto iter : arr){
        result += iter;
    }

    return result;
}


#endif //CHAPTER7_QUADRATICEQUATION_H

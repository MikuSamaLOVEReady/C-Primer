//
// Created by ����� on 2023/11/1.
//

#ifndef CHAPTER7_QUADRATICEQUATION_H
#define CHAPTER7_QUADRATICEQUATION_H
#include <cmath>

int quaraticEquation( int a , int b , int c){

    double delta = b*b - 4*a*c;
    int result = (sqrt(delta) - b) / (2*a);
    return result;
    // ģ��������ڣ������Զ����ݲ���ѡ�����������
}


int countTrue( std::vector<bool> arr ) {

    int result = 0;
    for(auto iter : arr){
        result += iter;
    }

    return result;
}


#endif //CHAPTER7_QUADRATICEQUATION_H

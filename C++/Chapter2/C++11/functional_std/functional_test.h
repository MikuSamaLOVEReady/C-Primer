//
// Created by ÂÞÈðµÑ on 2024/2/6.
//

#ifndef CHAPTER7_FUNCTIONAL_TEST_H
#define CHAPTER7_FUNCTIONAL_TEST_H

#include <functional>


int g(int n1)
{
    return n1;
}

void bind_f1(int n1 , int n2, int n3, const int& n4, int n5){

    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}


void bind_test()
{
    using namespace std::placeholders;
    auto new_f1 = std::bind(bind_f1 , _2 , 120 , _1 , 250 , 255);
    new_f1(150 , 10);

}





#endif //CHAPTER7_FUNCTIONAL_TEST_H

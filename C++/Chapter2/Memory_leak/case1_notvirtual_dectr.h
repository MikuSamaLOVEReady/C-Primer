//
// Created by 罗瑞笛 on 2024/8/22.
//

#ifndef CHAPTER7_CASE1_NOTVIRTUAL_DECTR_H
#define CHAPTER7_CASE1_NOTVIRTUAL_DECTR_H
#include <iostream>

class Base {
public:
    // 如果没有 virtual，这个析构函数在派生类被删除时不会调用派生类的析构函数
    ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        data = new int[100]; // 动态分配了一些内存
    }
    ~Derived() {
        delete[] data; // 释放动态分配的内存
        std::cout << "Derived destructor called" << std::endl;
    }
private:
    int* data;
};

int main() {
    Base* obj = new Derived();
    delete obj; // 只会调用 derived 的析构函数，而不会调用 base 的析构函数 //无法动态绑定
    return 0;
}


#endif //CHAPTER7_CASE1_NOTVIRTUAL_DECTR_H

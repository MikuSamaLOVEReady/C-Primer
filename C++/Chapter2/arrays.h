//
// Created by 罗瑞笛 on 2023/4/26.
//

#ifndef CHAPTER2_ARRAYS_H
#define CHAPTER2_ARRAYS_H

#include <iostream>
#include <iterator> // 包含 begin() 和 end() 函数


void print_array_bounds(int* arr, size_t size)
{
    //https://stackoverflow.com/questions/51638149/no-matching-function-for-call-to-beginint-n
    //这里数组已经退化成指针了，不再具备数组的功能不能用begin
    //int* begin_ptr = std::begin(arr);  // 获取头指针
    //int* end_ptr = std::end(arr);      // 获取尾指针

    //std::cout << "Begin pointer: " << begin_ptr << std::endl;
    //std::cout << "End pointer: " << end_ptr << std::endl;
}

//void useBig(const std::string s1,const std::string s2,
//            bool (*pf)(const std::string& s1 , const std::string& s2 )){}

//void useBig2(const std::string s1,const std::string s2,
//            bool (pf)(const std::string& s1 , const std::string& s2 )){}

bool lengthCompare(const std::string& , const std::string &);
//声明函数指针 bool (*pf) (const std::string& , const std::string&); 类似


//pass by value 然后设置为const 就没有任何意义么/
//void useBig(const std::string& s1,const std::string& s2, FuncP2 ptr);

using PF = int (*)(int*, int); //什么函数指针的类型，函数返回函数指针的 返回值类型
using F = int (int* ,int); //声明函数类型，并不是指针

PF f1(int); //返回一个函数指针

std::string::size_type sumLength(std::string &s1 , std::string &s2){}
std::string::size_type largerLength(std::string &s1 , std::string &s2){}
decltype(sumLength) *getFunc(const std::string& ss){
    std::string::size_type (*ppt)(std::string &s1, std::string &s2) = sumLength;
    return ppt;
};

int intfunc(int va , int vb){
    return va + vb;
}

int intfunc2(int va , int vb){
    return va - vb;
}

int intfunc3(int va , int vb){
    return va * vb;
}

int intfunc4(int va , int vb){
    return va / vb;
}


#endif //CHAPTER2_ARRAYS_H

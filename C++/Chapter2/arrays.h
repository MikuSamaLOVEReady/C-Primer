//
// Created by ����� on 2023/4/26.
//

#ifndef CHAPTER2_ARRAYS_H
#define CHAPTER2_ARRAYS_H

#include <iostream>
#include <iterator> // ���� begin() �� end() ����


void print_array_bounds(int* arr, size_t size)
{
    //https://stackoverflow.com/questions/51638149/no-matching-function-for-call-to-beginint-n
    //���������Ѿ��˻���ָ���ˣ����پ߱�����Ĺ��ܲ�����begin
    //int* begin_ptr = std::begin(arr);  // ��ȡͷָ��
    //int* end_ptr = std::end(arr);      // ��ȡβָ��

    //std::cout << "Begin pointer: " << begin_ptr << std::endl;
    //std::cout << "End pointer: " << end_ptr << std::endl;
}

//void useBig(const std::string s1,const std::string s2,
//            bool (*pf)(const std::string& s1 , const std::string& s2 )){}

//void useBig2(const std::string s1,const std::string s2,
//            bool (pf)(const std::string& s1 , const std::string& s2 )){}

bool lengthCompare(const std::string& , const std::string &);
//��������ָ�� bool (*pf) (const std::string& , const std::string&); ����


//pass by value Ȼ������Ϊconst ��û���κ�����ô/
//void useBig(const std::string& s1,const std::string& s2, FuncP2 ptr);

using PF = int (*)(int*, int); //ʲô����ָ������ͣ��������غ���ָ��� ����ֵ����
using F = int (int* ,int); //�����������ͣ�������ָ��

PF f1(int); //����һ������ָ��

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

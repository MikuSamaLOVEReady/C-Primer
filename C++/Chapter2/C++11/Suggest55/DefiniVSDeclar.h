//
// Created by ����� on 2023/12/19.
//

#ifndef CHAPTER2_DEFINIVSDECLAR_H
#define CHAPTER2_DEFINIVSDECLAR_H


#include <string>
class DefiniVSDeclar {

private:
    static const int Numt = 5; //����һ�����������Ƕ��� ��ֻҪ��ȡ��ַ
    // �����Ҫ& ��һ��Ҫ�ڶ�Ӧcpp ���壨��const int Numt; ���Բ�����ʼֵ

};

class Shape_v{

public:
    virtual void draw() const  = 0;
    virtual void static_ca(std::string s1 = "RED");

};

class Rectangle_v : public Shape_v{
public:
    void draw() const override;
    virtual void static_ca(std::string s1 = "LLL");

};


template<typename T>
class myNode{

public:
    myNode();
    ~myNode();

};


#endif //CHAPTER2_DEFINIVSDECLAR_H

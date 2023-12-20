//
// Created by 罗瑞笛 on 2023/12/19.
//

#ifndef CHAPTER2_DEFINIVSDECLAR_H
#define CHAPTER2_DEFINIVSDECLAR_H


class DefiniVSDeclar {

private:
    static const int Numt = 5; //这是一个声明而不是定义 ，只要不取地址
    // 如果需要& 则一定要在对应cpp 定义（）const int Numt; 可以不给初始值

};

class Shape_v{

public:
    virtual void draw() const  = 0;

};

class Rectangle_v : public Shape_v{
public:
    void draw() const override;

};


template<typename T>
class myNode{

public:
    myNode();
    ~myNode();

};


#endif //CHAPTER2_DEFINIVSDECLAR_H

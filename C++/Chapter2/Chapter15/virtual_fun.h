//
// Created by 罗瑞笛 on 2023/7/6.
//

#ifndef CHAPTER7_VIRTUAL_FUN_H
#define CHAPTER7_VIRTUAL_FUN_H

using namespace std;
struct Base2{
//virtual 无定义？
virtual void f1(int) const {
        std::cout << " BASE f1" << std::endl;
};

virtual void f2( const string& s1 = "wc") {
    std::cout << " BASE f2" << s1 << std::endl;
};

void f3();

};

// 继承f2 和 f3
// f2如果不重新定义，则D2所用的版本就是B的？
struct D2 :Base2{
    void f1(int) const override {
        std::cout << " D2 f1" << std::endl;
    };
};


struct D3 : D2{
    virtual void f1(int) const override{

        //如果需要调用Base的f1 但不给作用区域运算符，则会死循环
        //f1(5);
        D2::f1(5);
        Base2::f1(5);

        std::cout << " D3 f1" << std::endl;
    };

    void f2( const string& s1 = "didala" ) override{

        std::cout << "D3 " <<  s1 <<std::endl;
    }; // 不用增加override
// void f1(int) const; 不能继续继承
};


//
void default_paraprint( D2* base ){
    //base->f2();     //虽然是D3 但是bsse提供了形参的默认值，故依旧按照base的值打印。
    //base->D2::f1(5);   //如果传入参数是Base指针，它只能看到Base2的部分
    //base->D2::f1(5);     //如果传入的是D2，则它能够看到Base2和 D2自己的部分
    //base->Base2::f1(5);
    base->f1(5);
    
}


/*
void B::f3() {

}

void B::f2() {

}
*/

#endif //CHAPTER7_VIRTUAL_FUN_H

//
// Created by 罗瑞笛 on 2023/5/23.
//

#ifndef CHAPTER7_CHAPTER_0_H
#define CHAPTER7_CHAPTER_0_H

class A{
public:
    A();
};

class B{
public:
    B(int x=0 , bool b = true){};
};

class Widget{
public:
    Widget(){};
    Widget(const Widget& rhs){}; //   拷贝构造 有了它就可以 Widget w1(w2);
    Widget& operator = (const Widget& rhs){}; // 重载= 返回
};

//传递的Widget将调用对应的拷贝构造
//赋值一个一摸一样的给这个参数
bool PassByValue(Widget W){
    return true;
}

void doSomething(B bObject){
    return ;
};

class GamePlayer{
private:
    static const int NumTurns = 5;
    int  scores[NumTurns];
};


//
template<typename T>
inline void callWithMax( const T& a , const T& b){

}



#endif //CHAPTER7_CHAPTER_0_H

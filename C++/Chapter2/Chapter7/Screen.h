//
// Created by 罗瑞笛 on 2023/5/1.
//

#ifndef CHAPTER7_SCREEN_H
#define CHAPTER7_SCREEN_H
#include <string>
#include <vector>

using namespace std;
class Screen;
class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;//
    void clear(ScreenIndex);    //1. 先不定义
    ScreenIndex addScreen(const Screen&);
private:
    //此时Screen 还是 不完整类型
    std::vector<Screen> screens;
};

//定义Screen
int height;
class Screen{
public:
    //friend Sales_data add(const Sales_data& , const Sales_data&);
    //typedef string::size_type pos;
    friend void Window_mgr::clear(ScreenIndex);
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht , pos wd ): height(ht) , width(wd), contents(ht*wd , ' '){ };
    Screen(pos ht , pos wd, char c): height(ht) ,width(wd),contents(ht*wd , c) {};

    void dummy_fcn(pos height){
        cursor = width*height; //调用参数
        cursor = width* ::height; //调用 全局
    }
    char get() const{return contents[cursor];} //隐式内敛
    inline char get(pos ht , pos wd) const; //显式内敛【写两次inline】
    pos size();
    void setHeight(pos);

    Screen& Move(pos r, pos c);
    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0 , width = 0;
    std::string contents;
    mutable size_t access_ctr; // 即使是一个const对象，
private:
    inline double avg_price() const;
};

Screen::pos verify(Screen::pos){
    return 1;
};
//这里可以将定义滞后，效果就是在查找名字的时候，函数内->类内->定义之前[在最后找到目标]
void Screen::setHeight(pos var){
    height = verify(var);
}

Screen::pos Screen::size(){
    return height*width;
}

//最后定义 友元函数
inline
void Window_mgr::clear(ScreenIndex i) {
    Screen& s = screens[i];
    //只有等 window需要用的Screen完整了才能访问他的成员
    s.contents = s.height * s.width;
    return ;
}

//返回值在类名之后，
Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen& s) {
    screens.push_back(s);
    return screens.size()-1;
}

//
class Link_Screen{
    Screen window;
    Link_Screen *next;
    Link_Screen *prev;
};

class Y;
class X{
    Y* ptr_y;
};

class Y{
    X obj_x; //数据成员并不是Ref或者Ptr
};

typedef double money;
string bal;
class Account{
public:
    money balance() {return bal;}   // money没找到 -> 到外层继续找，此时所用的bal类型和money类型都是 double。、
private:
    typedef double money;            //这是错误的做法，即使重复定义相同类型，他也是错误
    money bal;                   // bal在外层，内层都有。但函数体可见后才能处理，从内到外，寻找最近
};







#endif //CHAPTER7_SCREEN_H

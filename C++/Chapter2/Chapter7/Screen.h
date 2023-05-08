//
// Created by 罗瑞笛 on 2023/5/1.
//

#ifndef CHAPTER7_SCREEN_H
#define CHAPTER7_SCREEN_H
#include <string>

class Screen{
public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht , pos wd ): height(ht) , width(wd), contents(ht*wd , ' '){};
    Screen(pos ht , pos wd, char c): height(ht) ,width(wd),contents(ht*wd , c) {};
    //隐式内敛
    char get() const{return contents[cursor];}
    //显式内敛【写两次inline】
    inline char get(pos ht , pos wd) const;
    Screen& Move(pos r, pos c);
    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0 , width = 0;
    std::string contents;
    mutable size_t access_ctr; //
private:
    inline double avg_price() const;
};

inline
Screen& Screen::Move(pos r, pos c){

}

inline
char Screen::get(pos r , pos c) const {
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const {
    ++access_ctr;
}

inline
double Screen::avg_price() const{
    return 12.34;
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


#endif //CHAPTER7_SCREEN_H

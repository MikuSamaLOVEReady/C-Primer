//
// Created by ����� on 2023/5/1.
//

#include "Screen.h"

inline
Screen& Screen::Move(pos r, pos c){

}

inline
char Screen::get(pos r , pos c) const {
    pos row = r * width;
    return contents[row + c];
}

//����һ��const�ĺ���������Ȼ����
inline
void Screen::some_member() const {
    ++access_ctr;
}

inline
double Screen::avg_price() const{
    return 12.34;
}
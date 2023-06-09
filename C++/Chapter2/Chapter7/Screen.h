//
// Created by ����� on 2023/5/1.
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
    void clear(ScreenIndex);    //1. �Ȳ�����
    ScreenIndex addScreen(const Screen&);
private:
    //��ʱScreen ���� ����������
    std::vector<Screen> screens;
};

//����Screen
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
        cursor = width*height; //���ò���
        cursor = width* ::height; //���� ȫ��
    }
    char get() const{return contents[cursor];} //��ʽ����
    inline char get(pos ht , pos wd) const; //��ʽ������д����inline��
    pos size();
    void setHeight(pos);

    Screen& Move(pos r, pos c);
    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0 , width = 0;
    std::string contents;
    mutable size_t access_ctr; // ��ʹ��һ��const����
private:
    inline double avg_price() const;
};

Screen::pos verify(Screen::pos){
    return 1;
};
//������Խ������ͺ�Ч�������ڲ������ֵ�ʱ�򣬺�����->����->����֮ǰ[������ҵ�Ŀ��]
void Screen::setHeight(pos var){
    height = verify(var);
}

Screen::pos Screen::size(){
    return height*width;
}

//����� ��Ԫ����
inline
void Window_mgr::clear(ScreenIndex i) {
    Screen& s = screens[i];
    //ֻ�е� window��Ҫ�õ�Screen�����˲��ܷ������ĳ�Ա
    s.contents = s.height * s.width;
    return ;
}

//����ֵ������֮��
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
    X obj_x; //���ݳ�Ա������Ref����Ptr
};

typedef double money;
string bal;
class Account{
public:
    money balance() {return bal;}   // moneyû�ҵ� -> ���������ң���ʱ���õ�bal���ͺ�money���Ͷ��� double����
private:
    typedef double money;            //���Ǵ������������ʹ�ظ�������ͬ���ͣ���Ҳ�Ǵ���
    money bal;                   // bal����㣬�ڲ㶼�С���������ɼ�����ܴ������ڵ��⣬Ѱ�����
};







#endif //CHAPTER7_SCREEN_H

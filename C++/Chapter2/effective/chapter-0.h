//
// Created by ����� on 2023/5/23.
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
    Widget(const Widget& rhs){}; //   �������� �������Ϳ��� Widget w1(w2);
    Widget& operator = (const Widget& rhs){}; // ����= ����
};

//���ݵ�Widget�����ö�Ӧ�Ŀ�������
//��ֵһ��һ��һ���ĸ��������
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

//
// Created by 罗瑞笛 on 2024/5/2.
//

#ifndef CHAPTER7_FUNCTOR_LEARN_H
#define CHAPTER7_FUNCTOR_LEARN_H

class Less
{
public:
    bool operator() (int a, int b) const {
        return a < b;
    }
};


/// 具体编译的时候、静态多态
template <typename  T , typename  Comparision>
T* find_opt ( const std::vector<T>& v , Comparision compare ) {
    int va1 = 1 , va2 = 2;
    compare( va1, va2 );
}

class inher_te{
public:
        inher_te() = default;
        int va_2 = 10;
        void prt(){
            std::cout << "woc" << std::endl;
        }
};

struct te1_derive :  private inher_te {
    void der_print(){
        std::cout << va_2 << std::endl;
    }
};

class cl_derive : protected  inher_te{

};

class Test {
public:
    /// static void staticFunc() const;  // 错误：静态成员函数不能被声明为const
};


struct te1{

    int va;
};


#endif //CHAPTER7_FUNCTOR_LEARN_H

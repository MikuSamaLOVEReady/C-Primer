//
// Created by 罗瑞笛 on 2024/1/15.
//

#ifndef CHAPTER7_SWAP_OPERA13_3_H
#define CHAPTER7_SWAP_OPERA13_3_H
#include <string>

/// like a pointer 【具有引用计数功能】
class HasPtr_2{
public:
    friend void swap(HasPtr_2& , HasPtr_2&);

    HasPtr_2(const std::string& s = std::string()):
    ps(new std::string(s)) , i (0) , use(new std::size_t(1))
    {}

    HasPtr_2(const HasPtr_2 &p)
    :ps(p.ps),i(p.i), use(p.use)
    {
        ++(*use);
    }

    HasPtr_2& operator = (const HasPtr_2& rhs )
    {
        ++*rhs.use;             //递增右侧引用
        if( --*use == 0){
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }

    ~HasPtr_2();

private:
    std::string* ps;
    int i;
    std::size_t *use;
};

class Foo_op13{
    friend void swap(Foo_op13& lhs , Foo_op13& rhs);
public:
    Foo_op13() = default;

private:
    HasPtr_2 h;
};

inline
void swap(Foo_op13& lhs , Foo_op13& rhs)
{
    using std::swap;                //  虽然有std版本 ， 但存在类型更匹配的 HashPtr版本
    swap(lhs.h , rhs.h);
}

inline
void swap(HasPtr_2& lhs , HasPtr_2& rhs)
{
    using std::swap;
    swap(lhs.ps , rhs.ps);          // 调用std版本 swap
    swap(lhs.i , rhs.i);            //
}


#endif //CHAPTER7_SWAP_OPERA13_3_H

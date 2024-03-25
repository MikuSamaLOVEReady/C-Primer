//
// Created by ����� on 2024/1/15.
//

#ifndef CHAPTER7_SWAP_OPERA13_3_H
#define CHAPTER7_SWAP_OPERA13_3_H
#include <string>

/// like a pointer ���������ü������ܡ�
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
        ++*rhs.use;             //�����Ҳ�����
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
    using std::swap;                //  ��Ȼ��std�汾 �� ���������͸�ƥ��� HashPtr�汾
    swap(lhs.h , rhs.h);
}

inline
void swap(HasPtr_2& lhs , HasPtr_2& rhs)
{
    using std::swap;
    swap(lhs.ps , rhs.ps);          // ����std�汾 swap
    swap(lhs.i , rhs.i);            //
}


#endif //CHAPTER7_SWAP_OPERA13_3_H

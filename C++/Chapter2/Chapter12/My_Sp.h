//
// Created by ����� on 2024/4/29.
//

#ifndef CHAPTER7_MY_SP_H
#define CHAPTER7_MY_SP_H


#include <cstddef>

template <typename T>
class My_SharedPtr{

private:
    size_t* count;          /// ����������ʹ��ָ��ʵ�ֵ�
    T*  raw_ptr;

    void release(){
        /// --������÷���ÿ���ж��Զ�-1
        if( count && --(*count) == 0){
            delete count;
            delete raw_ptr;
        }
    }

public:
    explicit My_SharedPtr(T* raw = nullptr ) : raw_ptr(raw) , count( raw ? new size_t(1) : nullptr) {};

    My_SharedPtr& operator= ( const My_SharedPtr& rhs ){
        if( rhs == this ){
            return *this;
        }
        ///  �����ߡ��ٲ����ұߡ�һ��ָ����Բ��ܡ��������sp��������������
        release();
        /// copy ָ�� ��Ҫȡֵ��ֵ
        count = rhs.count;
        raw_ptr = rhs.raw_ptr;
        if(count){
            ++(*count);
        }
        return *this;
    }

    My_SharedPtr( const My_SharedPtr& rhs ) : count(rhs.count) , raw_ptr(rhs.raw_ptr){
        if(count){
            (*count)++;
        }
    }

    ~My_SharedPtr(){
        release();  ///����������ü������򲻻�ɾ��ָ��ָ������
    }

    T& operator*() const { return *raw_ptr; }
    T* operator->() const { return raw_ptr; }
    T* get() const { return raw_ptr; }
    size_t  use_count() const { return count ? *count : 0;}
};


//// testing
class EMPTY{};

struct Foo
{
    Foo(int n = 0) noexcept : bar(n)
    {
        std::cout << "Foo::Foo(), bar = " << bar << " @ " << this << '\n';
    }
    ~Foo()
    {
        std::cout << "Foo::~Foo(), bar = " << bar << " @ " << this << '\n';
    }

    /// copy Assign
    /// ����� const && ����������
    Foo& operator= (const Foo& rhs){
        std::cout <<  "(const Foo& rhs ) called " << std::endl;
        return *this;
    }

    /// copy Ctr [��Ҫһ����ֵ����]
    Foo(const Foo& rhs){
        std::cout <<  "copy Ctr called " << std::endl;
    }


    /// �ƶ�ϵ��
//    Foo& operator= ( Foo&& rhs ){
//        std::cout <<  "( Foo&& rhs ) called " << std::endl;
//    }


//    Foo( Foo&& rhs ) : bar(0){ }

    int getBar() const noexcept { return bar; }
private:
    int bar;
};


#endif //CHAPTER7_MY_SP_H

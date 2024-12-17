//
// Created by 罗瑞笛 on 2024/4/29.
//

#ifndef CHAPTER7_MY_SP_H
#define CHAPTER7_MY_SP_H


#include <cstddef>

template <typename T>
class My_SharedPtr{

private:
    size_t* count;          /// 计数本身是使用指针实现的
    T*  raw_ptr;

    void release(){
        /// --的最佳用法、每次判断自动-1
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
        ///  清空左边、再操作右边【一般指针可以不管、但是左侧sp可能引发析构】
        release();
        /// copy 指针 不要取值后赋值
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
        release();  ///如果还有引用计数、则不会删除指针指向内容
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
    /// 如果是 const && 则会调用这里
    Foo& operator= (const Foo& rhs){
        std::cout <<  "(const Foo& rhs ) called " << std::endl;
        return *this;
    }

    /// copy Ctr [需要一个左值引用]
    Foo(const Foo& rhs){
        std::cout <<  "copy Ctr called " << std::endl;
    }


    /// 移动系列
//    Foo& operator= ( Foo&& rhs ){
//        std::cout <<  "( Foo&& rhs ) called " << std::endl;
//    }


//    Foo( Foo&& rhs ) : bar(0){ }

    int getBar() const noexcept { return bar; }
private:
    int bar;
};


#endif //CHAPTER7_MY_SP_H

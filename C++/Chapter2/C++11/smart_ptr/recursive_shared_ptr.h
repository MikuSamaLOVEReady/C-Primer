//
// Created by 罗瑞笛 on 2024/4/12.
//

#ifndef CHAPTER7_RECURSIVE_SHARED_PTR_H
#define CHAPTER7_RECURSIVE_SHARED_PTR_H
#include <memory>

namespace smart_learn{

    class A;
    class B;


    class A{
        public:
            std::shared_ptr<B> ptr_B;
            ~A(){
                std::cout << " DesDDD A " << endl;
            }
    };

    class B{
        public:
            std::weak_ptr<A> ptr_A;
            ~B(){
                std::cout << " DesDDD B " << endl;
            }
    };

}

struct SomeData{
public:
    static void print(){
        std::cout << "class prtt" << std::endl;
    }

    void CallSomeAPI(){

    }

    virtual void display(){
        std::cout << "Base print" << std::endl;
    }

};

struct SomeDataB : SomeData{
protected:
    void display() override{
        std::cout << "Print children " << std::endl;
    }

};

/// const Ref
struct SomeData2;
struct SomeData3;
void SomeAPI( const std::shared_ptr<SomeData2>& d )
{
    std::cout << "REF count: "<< d.use_count()  << std::endl;
}

void SomeAPI3( const std::shared_ptr<SomeData3>& d )
{
    std::cout << "REF count: "<< d.use_count()  << std::endl;
}

/// 继承 std::enable_shared_from_this
struct SomeData2 : std::enable_shared_from_this<SomeData2> {

    void NeedCallSome(){
        /// 函数推出后、sp降为=0 this被释放、寄
        /// SomeAPI( std::shared_ptr<SomeData2>{this} ); 传的是裸指针
         SomeAPI(shared_from_this());
    }

    static std::shared_ptr<SomeData2> Create(){
        return std::shared_ptr<SomeData2>( new SomeData2);
    }

private:
    SomeData2(){};

};


/// 继承 std::enable_shared_from_this
struct SomeData3 : std::enable_shared_from_this<SomeData3> {

public:
    SomeData3(){};

    void NeedCallSome(){
        ///为什么这里还是会
        SomeAPI3(shared_from_this());
    }

};

#endif //CHAPTER7_RECURSIVE_SHARED_PTR_H

//
// Created by 罗瑞笛 on 2024/9/1.
//

#ifndef OFFER_CHAPTER4_1_H
#define OFFER_CHAPTER4_1_H

namespace chap4_1{

    class A{
    public:
        A* mFunc(){
            return this;
        }

        long func(long thisPointer) {
            std::cout<< "CLASS A" << std::endl;
            return thisPointer;
        }

        virtual void func_b() {
            std::cout<< "CLASS A" << std::endl;
        }
    };

    ///global
    void func_b() {
        std::cout<< "CLASS A" << std::endl;
    }


    class B : public A{
    public:

        ///由于public继承， base的同名函数 遮挡了derived的实现
        long func(long thisPointer) {
            std::cout<< "CLASS B" << std::endl;
            return thisPointer;
        }

        void func_b() override {
            std::cout<< "CLASS B" << std::endl;
        }

    };


}



#endif //OFFER_CHAPTER4_1_H

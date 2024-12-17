//
// Created by ����� on 2024/9/10.
//

#ifndef CHAPTER7_M1_H
#define CHAPTER7_M1_H

#include <memory>
//#include ""

namespace m1{
    class A{
        int a;
        char b;
    };

    class B{
        char c;
        int a;
        char b;
    };

    class C{
        char c;                     /// 1 ��3
        int a;                      /// 4       /// ���ò�
        char b;                     /// 1 .... ����������vptrһ��17 ������24����
        virtual void  fun1(){}      /// ֻҪ�� ���ı������� vptr 8
    };

    class D{
        char c;
        int a;
        char b;
        virtual void  fun1(){}
        virtual void  fun2(){}
        virtual void  fun3(){}
        virtual void  fun4(){}
    };

    unique_ptr<int> getUnique(){
        unique_ptr<int> ret( new int(18));
        return ret;
    }

    unique_ptr<int> getUnique2(){
        unique_ptr<int> ret( new int(18));
        return std::move(ret);
    }

    /// ��Ҫ������
//    unique_ptr<int>& getUnique_ref(){
//        unique_ptr<int> ret( new int(18));
//        return ret;
//    }



    void creatUnique(){
        std::unique_ptr<int> pdata { std::make_unique<int>( 15 )};
    }

    void smartPtr_get_test(){
        int* va = new int(16);
        unique_ptr<int> ret_(va);

        auto ptr_raw = ret_.get();
        std::cout << ptr_raw  << std::endl;
        std::cout << va  << std::endl;

    }

}


#endif //CHAPTER7_M1_H

//
// Created by ����� on 2024/3/28.
//

#ifndef CHAPTER7_STD_FUNCTIONLEARN_H
#define CHAPTER7_STD_FUNCTIONLEARN_H

#include  <map>
#include <string>

int add_FUNC( int i , int j ) { return i+j; }
auto mod = [] (int i , int j) { return i % j; };
struct divide {
    int operator () (int a , int b) {
        return a/b;
    }
};
/// �������� int(int , int)

void functio_learn(){

    map< std::string , int(*)(int , int) > f_ptr;

    ///f_ptr["+"] = &add;
    f_ptr.insert({"%", mod});       /// �޲���lambda������ʽת�� -> ����ָ��
    /// f_ptr.insert("/" , divide());         /// ʵ���޷�ƥ��
    int v1 = f_ptr["+"](1,2);
    int v2 = f_ptr["%"](1,2);

    /// map <std::string , function<int(int, int)>> stdFun;
    /// stdFun.insert({"+" , add});
    std::function<int(int , int)> f1 = &add_FUNC;       /// ����ָ��
    std::function<int(int , int)> f2 = divide();        /// ��������functor��
    std::function<int(int , int)> f3 = [] (int i , int j) { return i+j; };

    map <std::string , function<int(int, int)>> stdFun = {
            {"+", f1},
            {"%", f2},
            {"/", f3}
    };


    return ;
}





#endif //CHAPTER7_STD_FUNCTIONLEARN_H

//
// Created by ����� on 2023/11/1.
//

#ifndef CHAPTER7_VARIADIC_TEST_H
#define CHAPTER7_VARIADIC_TEST_H


void printX(){
}

/// ... ==> ��ʾһ��pack
/// ��һ����Ҫ�����ٽ�״̬ �ݹ鵽��� ��Ҫ��������һ�����
template <typename T , typename... Types>
void printX(const T& firstArg , const Types&... args){
    std::cout << firstArg << std::endl;
    std::cout << "SIZE is" << sizeof...(args) << std::endl; //
    printX(args...); // ������Ҫ�ݹ����
}

/// Ϊɶû�����壿 �� ���������
template <typename... Types>
void printX(const Types&... args)
{
    std::cout << "PRTX!!!!"  << std::endl;
}


// fuc1
template <typename T>
inline void hash_combine(::size_t& seed , const T& val){

}


// fuc2
template <typename T , typename... Types>
void hash_val( ::size_t seed , const T& val , const Types&... args){
    hash_combine(seed,val); // �ݹ�����һ��ֵ
    hash_val( seed , args...); //  ->�ݹ��Լ� �� ���args = 1 ʱ ��fund3
}

//fuc3
template <typename T>
void hash_val( ::size_t &seed , const T& val){
    hash_combine(seed , val);
}

// fuc4 ��û��ǿ��Ҫ���һ������������ size_t
template <typename... Types>
::size_t hash_val(const Types&... args ){
    ::size_t seed = 0;
    hash_val(seed,args...);
    return seed;
}


//practice
void func_p(){} ;

template < typename T , typename... Types>
void func_p(const T& firstArg , const Types&... args){
    func_p(args...);
}






#endif //CHAPTER7_VARIADIC_TEST_H

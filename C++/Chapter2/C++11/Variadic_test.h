//
// Created by 罗瑞笛 on 2023/11/1.
//

#ifndef CHAPTER7_VARIADIC_TEST_H
#define CHAPTER7_VARIADIC_TEST_H


void printX(){
}

/// ... ==> 表示一个pack
/// ！一定需要处理临界状态 递归到最后 需要单独处理一种情况
template <typename T , typename... Types>
void printX(const T& firstArg , const Types&... args){
    std::cout << firstArg << std::endl;
    std::cout << "SIZE is" << sizeof...(args) << std::endl; //
    printX(args...); // 往往需要递归调用
}

/// 为啥没有歧义？ ， 这个更泛化
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
    hash_combine(seed,val); // 递归消耗一个值
    hash_val( seed , args...); //  ->递归自己 ， 最后args = 1 时 调fund3
}

//fuc3
template <typename T>
void hash_val( ::size_t &seed , const T& val){
    hash_combine(seed , val);
}

// fuc4 ，没有强制要求第一个参数必须是 size_t
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

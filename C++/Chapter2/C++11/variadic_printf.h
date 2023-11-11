//
// Created by 罗瑞笛 on 2023/11/8.
//

#ifndef CHAPTER7_VARIADIC_PRINTF_H
#define CHAPTER7_VARIADIC_PRINTF_H

void my_printf(const char *s){
    while(*s)
    {
        if( *s == '%' && *(++s)!='%' ){
                std::cout << "not enough" <<std::endl;
        }
        std::cout << *(s++);
    }
}

template<typename T,  typename... Args>
void my_printf(const char* s , T value , Args... args){
    while(*s){
        if( *s == '%'&& *(++s)!='%'){ // 这里++s会自增s，并起作用
            std::cout << "VAL " << value << std::endl;
            my_printf(++s , args...); // 这里也会
            return;
        }
        std::cout << *(s++); //先加 ++ 指针 再访问 ，会影响s的值！
    }

}


void plustest(int val){

    while(val != 10){
        plustest(++val);
    }
    return;
}

namespace MIKU_temp{
    int maximum(int n){
        return n;
    }

    template<typename... Args>
    int maximum(int n , Args... args){
        std::cout << sizeof...(args);
        return std::max(n , maximum(args...));
    }
}


#endif //CHAPTER7_VARIADIC_PRINTF_H

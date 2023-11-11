//
// Created by 罗瑞笛 on 2023/11/6.
//

#ifndef CHAPTER7_TYPE_ALIAS_H
#define CHAPTER7_TYPE_ALIAS_H

typedef void (*func2)(int , int);
using func = void (*) (int , int);

// 在 noexcept(condition) 条件下不弹出异常
void foonon_excep() noexcept(true);




#endif //CHAPTER7_TYPE_ALIAS_H
 
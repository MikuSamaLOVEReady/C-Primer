//
// Created by ����� on 2023/11/6.
//

#ifndef CHAPTER7_TYPE_ALIAS_H
#define CHAPTER7_TYPE_ALIAS_H

typedef void (*func2)(int , int);
using func = void (*) (int , int);

// �� noexcept(condition) �����²������쳣
void foonon_excep() noexcept(true);




#endif //CHAPTER7_TYPE_ALIAS_H
 
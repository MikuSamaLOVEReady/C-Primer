//
// Created by ÂÞÈðµÑ on 2023/11/2.
//

#ifndef CHAPTER7_INITIALIZELIST_H
#define CHAPTER7_INITIALIZELIST_H


void print(std::initializer_list<int> vals)
{
    for( const int* p = vals.begin() ; p!= vals.end() ; ++p){
        std::cout << *p << std::endl;
    }

}




#endif //CHAPTER7_INITIALIZELIST_H

//
// Created by ÂÞÈðµÑ on 2024/8/4.
//

#ifndef CHAPTER7_CHAPTER_0_H
#define CHAPTER7_CHAPTER_0_H

#include <iostream>

class X
{
    friend std::istream&
        operator >> (std::istream& , X& );


};


#endif //CHAPTER7_CHAPTER_0_H

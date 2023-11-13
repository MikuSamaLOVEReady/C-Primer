//
// Created by ÂÞÈðµÑ on 2023/11/13.
//

#ifndef CHAPTER7_STLHASH_H
#define CHAPTER7_STLHASH_H

#include <functional>

///
void print_hash(){

    std::cout <<  "HASH VALUE : " << std::hash<std::string>()("MIKU") << std::endl;
    std::cout <<  "HASH VALUE : " << std::hash<std::string>()("SAMA") << std::endl;

}


#endif //CHAPTER7_STLHASH_H

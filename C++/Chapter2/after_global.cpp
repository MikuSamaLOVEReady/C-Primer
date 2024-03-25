//
// Created by ÂÞÈðµÑ on 2024/3/20.
//

#include <iostream>
#include "after_global.h"

extern int global_va;

void after_gl::print() {

    std::cout << global_va << std::endl;

}

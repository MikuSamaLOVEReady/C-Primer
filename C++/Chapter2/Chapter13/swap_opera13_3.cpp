//
// Created by ÂÞÈðµÑ on 2024/1/15.
//

#include "swap_opera13_3.h"


HasPtr_2::~HasPtr_2() {
    if( --(*use) == 0)
    {
        delete ps;
        delete use;
    }
}

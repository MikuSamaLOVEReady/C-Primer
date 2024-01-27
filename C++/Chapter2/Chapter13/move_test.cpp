//
// Created by YX on 2024/1/24.
//

#include "move_test.h"

move_test& move_test::operator=(move_test &&rhs) {

    if(this != &rhs)
    {
        free();
        this->elem = rhs.elem;
        this->str  = rhs.str;
    }
    return *this;
}

void move_test::free() {


}

move_test::move_test(move_test &rhs) {
    this->elem = rhs.elem;
    this->str  = rhs.str;
}

move_test& move_test::operator=(const move_test &rhs) {
    this->str =rhs.str;
    this->elem = rhs.elem;
    return *this;
}


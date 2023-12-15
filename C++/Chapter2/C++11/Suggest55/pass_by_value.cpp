//
// Created by YX on 2023/12/8.
//

#include "pass_by_value.h"

WindowWithScrool& WindowWithScrool::operator=(int rhs) {


    return  *this;
}

WindowWithScrool &WindowWithScrool::operator+=(int rhs) {

    return *this;
}

WindowWithScrool &WindowWithScrool::operator+=(const int &rhs) {

    return *this;
}

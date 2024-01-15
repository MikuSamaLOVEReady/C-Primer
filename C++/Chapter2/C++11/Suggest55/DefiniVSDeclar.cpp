//
// Created by ยÞศ๐ตั on 2023/12/19.
//

#include "DefiniVSDeclar.h"

#include <iostream>

void Shape_v::draw() const {

    std::cout << "Shape_v" << std::endl;
}

void Shape_v::static_ca(std::string s1) {
    std::cout << s1 << std::endl;
}


void Rectangle_v::draw() const {
        std::cout << "Rectangle" << std::endl;
}

void Rectangle_v::static_ca(std::string s1) {
    std::cout << s1 << std::endl;
}

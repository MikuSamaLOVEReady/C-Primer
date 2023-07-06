//
// Created by di on 2023/3/29.
//
#include "Chapter15/inherit.h"

//¾²Ì¬º¯Êý¼Ì³Ð
void inhert_01::f(const inhert_01 &derived_obj) {
    base_01::statemem();
    inhert_01::statemem();
    derived_obj.statemem();
    statemem();
}

void base_01::statemem() {
    std::cout << "statemem" << std::endl;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}

double Limit_quote::net_price(std::size_t n) const {
    if(n > max_qt){
        return 0.25f;
    }
    return  0.001f;
}

//
// Created by ÂŞÈğµÑ on 2023/4/27.
//

#include "Sales_data.h"
#include "Data.h"

//const double Example::va_2 = 16.3f; ///ÖØ¸´¶¨Òå
Sales_data add(const Sales_data& , const Sales_data&){
    std::cout<< "this is add function" << std::endl;
    std::cout << Example::va_2 << std::endl;
}

std::ostream& print(std::ostream& str, const Sales_data& data){
    std::cout<< "this is print function" << std::endl;
    return str;
}

//ifstream >>
std::istream& read(std::istream& str, Sales_data& data){
    std::cout<< "this is print function" << std::endl;
    return str;
}

bool compareIsbn(const Sales_data &lhs , const Sales_data &rhs){
return lhs.isbn() < rhs.isbn();
}

//
ConstRef::ConstRef(int ii) : i(ii),ci(ii),ri(ii) {

}

Exercise::Type Exercise::setVal(Type parm) {
    return val;
}
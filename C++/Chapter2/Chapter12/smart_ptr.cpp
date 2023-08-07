//
// Created by ÂÞÈðµÑ on 2023/8/2.
//

#include "smart_ptr.h"

//size_type unsigned
void StrBlob::check(size_type i, const std::string &msg) const {
    if(i>= data->size())
        throw std::out_of_range(msg);
}

std::string& StrBlob::front() {
    check(0,"front is empty");
    return data->front();
}

std::string& StrBlob::front() const {
    check(0,"front is empty");
    return data->front();
}

void StrBlob::pop_back() {
    data->pop_back();
}

std::string& StrBlob::back(){
    check(0,"front is empty");
    return data->back();
}

std::string& StrBlob::back() const{
    check(0,"front is empty");
    return data->back();
}




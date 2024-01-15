//
// Created by ÂÞÈðµÑ on 2024/1/5.
//

#ifndef CHAPTER7_COPYCTR_SP_H
#define CHAPTER7_COPYCTR_SP_H

#include <memory>
#include <string>

class CopyCtr_Sp {

public:
    std::shared_ptr<int> va;

    CopyCtr_Sp() = default;
    CopyCtr_Sp(const CopyCtr_Sp& copy);
    CopyCtr_Sp& operator = (const CopyCtr_Sp& ref);



private:
    std::string *ps;
    int i;

};

class HasPtr{
public:
    HasPtr(const std::string& s = std::string())
    :ps(new std::string(s) ) , i(10) {};

    ~HasPtr(){
        delete ps;
    }

private:
    std::string *ps;
    int i;

};

class number_{

public:
    number_() = default;
    number_(const number_& other);
    number_& operator = (const number_& ref);
    int mysn;
    static int copy_count;

private:
    std::string *ps;
};


#endif //CHAPTER7_COPYCTR_SP_H

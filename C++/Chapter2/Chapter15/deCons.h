//
// Created by ÂÞÈðµÑ on 2023/8/2.
//

#ifndef CHAPTER7_DECONS_H
#define CHAPTER7_DECONS_H

class Base_cal {
public:
    virtual ~Base_cal() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived_cal : public Base_cal {
public:
    ~Derived_cal() {
        std::cout << "Derived destructor" << std::endl;
    }
};





#endif //CHAPTER7_DECONS_H

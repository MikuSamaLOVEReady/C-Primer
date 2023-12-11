//
// Created by YX on 2023/12/8.
//

#ifndef CHAPTER7_PASS_BY_VALUE_H
#define CHAPTER7_PASS_BY_VALUE_H

#include <iostream>

class Window {
public:
    virtual
    inline void display() const{
        std::cout << "Window" << std::endl;
    };

};

class WindowWithScrool : public Window{
public:
    virtual
    inline void display() const override{
        std::cout << "WindowWithScrool" << std::endl;
    }

};


#endif //CHAPTER7_PASS_BY_VALUE_H

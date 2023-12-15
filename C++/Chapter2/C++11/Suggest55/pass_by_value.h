//
// Created by YX on 2023/12/8.
//

#ifndef CHAPTER7_PASS_BY_VALUE_H
#define CHAPTER7_PASS_BY_VALUE_H

#include <iostream>

typedef std::string AddrressLines[4];

class Window {
public:
    virtual
    inline void display() const{
        std::cout << "Window" << std::endl;
    };

};

class WindowWithScrool : public Window{
public:
    WindowWithScrool () : Window()
    {}


    virtual
    inline void display() const override{
        std::cout << "WindowWithScrool" << std::endl;
    }

    void swap(WindowWithScrool& rhs);

    //自我赋值 (处理异常 + 自我赋值问题）
    WindowWithScrool& operator = (int rhs);

    WindowWithScrool& operator += (const int& rhs);

    WindowWithScrool& operator += (int rhs);


};


#endif //CHAPTER7_PASS_BY_VALUE_H

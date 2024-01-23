//
// Created by ÂÞÈðµÑ on 2024/1/4.
//

#ifndef CHAPTER7_PURE_VIRDEF_H
#define CHAPTER7_PURE_VIRDEF_H


#include <iostream>

class Pure_virDefin {

public:
    Pure_virDefin() = default;
    virtual void pure_test() = 0;
    int healthValue() const{
        doHealthValue();
        return 1;
    }
private:
    virtual int doHealthValue() const{
        std::cout << "Base class implementation" << std::endl;
        return 1;
    }
};

class deri: public  Pure_virDefin{
public:
    deri() = default;
    void pure_test() override;

private:
    int doHealthValue() const override {
        std::cout << "Derived class implementation" << std::endl;
        return 2;
    }

};


#endif //CHAPTER7_PURE_VIRDEF_H

//
// Created by 罗瑞笛 on 2024/1/4.
//

#ifndef CHAPTER7_SUGGTEMLATEMETH_H
#define CHAPTER7_SUGGTEMLATEMETH_H

#include <iostream>

class GameCharacter;
int defaultHeathCal(const GameCharacter& gc);

class GameCharacter {
public:

    ///
    typedef int (*HeathFuncPtr) (const GameCharacter&);
    explicit GameCharacter(HeathFuncPtr hcf = defaultHeathCal)
    :heaFuc(hcf){};

    int headValue() const{
        std::cout << "befor"  << std::endl; // 可以把一些上锁(统一的操作)
        dealValue();
        std::cout << "after"  << std::endl; // 关锁的操作放在这
        return -1;
    }

    int getHeathValue() const {
        return heaFuc(*this);
    }

private:
    virtual int dealValue() const{
        std::cout << "Game" << std::endl;
        return 1;
    }

    HeathFuncPtr heaFuc;

};

class Enemy : public GameCharacter{
public:

private:
    int dealValue() const override{
        std::cout << "Ennemy" << std::endl;
        return 1;
    }

};




#endif //CHAPTER7_SUGGTEMLATEMETH_H

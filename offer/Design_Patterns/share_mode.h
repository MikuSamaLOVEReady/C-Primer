//
// Created by 罗瑞笛 on 2024/4/15.
//

#ifndef OFFER_SHARE_MODE_H
#define OFFER_SHARE_MODE_H

#include <unordered_map>
#include <iostream>
#include <string>
#include <utility>


/// 享元抽象
class AbstractShape {
public:
    virtual void operation(int a , int b) = 0;

};

class ConcretShape : public AbstractShape{

public:
    ConcretShape( std::string  str) : shape_name(std::move(str)) , first(true) {};

    void operation(int a, int b) override {
        if( first ){
            std::cout << shape_name << " drawn at (" <<  a << ", " << b << ")" <<std::endl;
            first = false;
        }
        else
            std::cout << shape_name << " shared at (" <<  a << ", " << b << ")" <<std::endl;
    }

private:
    std::string shape_name;
    bool first = true;

};

/// concret ! WRONG
//class TRIANGLE : public AbstractShape{
//
//public:
//    void operation(int a , int b) override{
//        std::cout << "TRIANGLE drawn at (" << a << ", " << b << ")" << std::endl;
//    }
//
//};
//
//class CIRCLE : public AbstractShape{
//
//public:
//    void operation(int a, int b) override{
//        std::cout << "CIRCLE drawn at (" << a << ", " << b << ")" << std::endl;
//    }
//
//};
//
//class Rectangle : public AbstractShape{
//
//public:
//    void operation(int a, int b) override{
//        std::cout << "Rectangle drawn at (" << a << ", " << b << ")" << std::endl;
//    }
//};

/// 享元工厂
class Flyweight_factory{

public:
    std::shared_ptr<AbstractShape> getFlyweight( const std::string str ){
        if( all_flyweights.find(str) == all_flyweights.end() ){
            all_flyweights.insert(   {str , std::make_shared<ConcretShape>(str) }  );
            return all_flyweights[str];
        }else{
            std::cout << all_flyweights.size() << std::endl;
            return all_flyweights[str];
        }
    }

private:
    std::unordered_map<std::string , std::shared_ptr<AbstractShape> > all_flyweights;

};

#endif //OFFER_SHARE_MODE_H

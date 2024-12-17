//
// Created by ÂÞÈðµÑ on 2024/3/27.
//

#ifndef OFFER_FACTORY_LEARN_H
#define OFFER_FACTORY_LEARN_H

#include <iostream>


namespace Design_video{

/// product
    class IShape{
        public:
            virtual void draw() = 0;
            virtual ~IShape() = default;
    };

    class Circle : public IShape{
    public:
        virtual void draw() override{
            std::cout << "Circle Block" << std::endl;
        }

    };

    class Square : public IShape{
    public:
        virtual void draw() override{
                std::cout << "Square Block" << std::endl;
        }
    };

/// ¹¤³§
    class AbstractFactory{
        public:
        virtual IShape* CreateShape() = 0;
        virtual ~AbstractFactory() = default;

    };

    class CircleFactory : public AbstractFactory {
    public:
        IShape * CreateShape() override
        {
            return new Circle();
        }
    };

    class SquareFactory : public  AbstractFactory{
    public:
        IShape * CreateShape() override
        {
            return new Square();
        }

    };

}




#endif //OFFER_FACTORY_LEARN_H

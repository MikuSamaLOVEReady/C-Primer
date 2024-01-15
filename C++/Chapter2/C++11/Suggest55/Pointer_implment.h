//
// Created by YX on 2023/12/15.
//

#ifndef CHAPTER7_POINTER_IMPLMENT_H
#define CHAPTER7_POINTER_IMPLMENT_H

#include <vector>
#include <type_traits>

class Widtett;
class Pointer_implment {

public:
    Pointer_implment() = default;

private:
    int a,b,c;
    std::vector<double> v;
};



namespace std {
    template<>
    void swap<Pointer_implment>(
            Pointer_implment &a, Pointer_implment &b
    ) noexcept(is_nothrow_move_constructible<Pointer_implment>::value && is_nothrow_move_assignable<Pointer_implment>::value)
    {
        return;
    }
}


/// interface class
class Person{
public:
    static std::shared_ptr<Person>
            create();

    virtual ~Person();
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
};


/// 所有它对应的Derived class 应该怎么被构造？




#endif //CHAPTER7_POINTER_IMPLMENT_H

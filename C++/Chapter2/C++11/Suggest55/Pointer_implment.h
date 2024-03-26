//
// Created by YX on 2023/12/15.
//

#ifndef CHAPTER7_POINTER_IMPLMENT_H
#define CHAPTER7_POINTER_IMPLMENT_H

#include <vector>
#include <type_traits>
#include <memory>

class Widtett;
class Pointer_implment {

public:
    Pointer_implment() = default;

private:
    int a,b,c;
    std::vector<double> v;
};




/*
namespace std {
    template<>
    void swap<Pointer_implment>(Pointer_implment &a, Pointer_implment &b)
            noexcept(__and_<is_nothrow_move_constructible<Pointer_implment>,
            is_nothrow_move_assignable<Pointer_implment>>::value)
    {
        return;
    }
}
*/

/// interface class
class Person{
public:
    static std::shared_ptr<Person>
            create();

    virtual ~Person();
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
};


/// ËùÓÐËü¶ÔÓ¦µÄDerived class Ó¦¸ÃÔõÃ´±»¹¹Ôì£¿




#endif //CHAPTER7_POINTER_IMPLMENT_H

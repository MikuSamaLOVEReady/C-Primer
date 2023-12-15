//
// Created by YX on 2023/12/15.
//

#ifndef CHAPTER7_POINTER_IMPLMENT_H
#define CHAPTER7_POINTER_IMPLMENT_H

#include <vector>

class Widtett;
class Pointer_implment {

public:
    Pointer_implment();

private:
    int a,b,c;
    std::vector<double> v;
};



namespace std {
    template<>
    void swap<Pointer_implment>(
            Pointer_implment &a, Pointer_implment &b
    ) noexcept(__and_<is_nothrow_move_constructible<Pointer_implment>, is_nothrow_move_assignable<Pointer_implment>>::value)
    {
        return;
    }
}


#endif //CHAPTER7_POINTER_IMPLMENT_H

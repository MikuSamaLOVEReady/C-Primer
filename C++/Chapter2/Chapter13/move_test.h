//
// Created by YX on 2024/1/24.
//

#ifndef CHAPTER7_MOVE_TEST_H
#define CHAPTER7_MOVE_TEST_H

#include <string>

class move_test {

public:
    move_test() = default;
    move_test(move_test& rhs);
    move_test& operator= (const move_test& rhs);

    move_test& operator= (move_test&& rhs);

    void free();

private:
    int* elem;
    std::string* str;
};


#endif //CHAPTER7_MOVE_TEST_H

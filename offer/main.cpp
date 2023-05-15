#include <iostream>
#include "offer2-41.h"

int main() {

    MovingAverage* movingAverage = new MovingAverage(3);

    std::cout << movingAverage->next(1) << std::endl;
    std::cout << movingAverage->next(10)<< std::endl;
    std::cout << movingAverage->next(3) << std::endl;
    return 0;
}

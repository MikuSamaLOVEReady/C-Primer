#include <iostream>
#include "offer2-41.h"
#include "offer-25.h"
#include "offer-26.h"
#include "offer-21.h"

int main() {

    int t=0;
    while(true){
        if(t++>5)
            break;
        std::cout << t << std::endl;
    }
    MovingAverage* movingAverage = new MovingAverage(3);

    vector<int> nums = {};
    exchange(nums);
    std::cout << "wic" << std::endl;
    //std::cout << movingAverage->next(10)<< std::endl;
    //std::cout << movingAverage->next(3) << std::endl;
    return 0;
}

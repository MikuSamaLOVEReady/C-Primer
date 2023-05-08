//
// Created by ÂÞÈðµÑ on 2023/5/6.
//

#ifndef OFFER_OFFER_11_H
#define OFFER_OFFER_11_H
#include <vector>
using namespace std;

int minArray(vector<int>& numbers) {
    if(numbers.size() == 0){
        return -1;
    }
    int min = numbers[0]; //
    for (vector<int>::iterator it = numbers.begin() ; it!=numbers.end() ; ++it){
        if(*it < min ) return *it;
    }
    return min;
}




#endif //OFFER_OFFER_11_H


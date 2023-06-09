//
// Created by ÂÞÈðµÑ on 2023/5/22.
//

#ifndef OFFER_217_H
#define OFFER_217_H
#include <vector>


using namespace std;
bool containsDuplicate(vector<int>& nums) {

    for(int i = 0 ; i<nums.size() ;i++){
        for(int j = i + 1 ; j< nums.size() ; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
        }
    }
    return false;

}

#endif //OFFER_217_H

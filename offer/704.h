//
// Created by ÂÞÈðµÑ on 2023/5/23.
//

#ifndef OFFER_704_H
#define OFFER_704_H
#include <vector>

using namespace std;
int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    int mid = 0;

    while(low <= high){
        mid = (low+high)/2;
        if(target > nums[mid]){
            low = mid+1;
        } else if( target < nums[mid]){
            high = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}



#endif //OFFER_704_H

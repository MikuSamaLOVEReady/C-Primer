//
// Created by ÂÞÈðµÑ on 2024/3/2.
//

#ifndef OFFER_BINARYSEARCH_H
#define OFFER_BINARYSEARCH_H

int binary_search_classic( vector<int>& nums , int target , bool find_lowest = true ){
    int left = 0 , right = nums.size()-1;
    int res  = -1;
    while ( left <= right )
    {
        int mid = (left + right) >> 1;
        if( nums[mid] == target )
        {
            if(find_lowest){
                right = mid - 1;
            }
            else left = mid + 1;
            res = mid;
        }
        else if ( nums[mid] > target){
            right = mid -1;
        }
        else  {
            left = mid + 1;
        }
    }
    return res;
}

#endif //OFFER_BINARYSEARCH_H

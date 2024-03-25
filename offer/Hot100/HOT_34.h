//
// Created by ÂÞÈðµÑ on 2024/3/2.
//

#ifndef OFFER_HOT_34_H
#define OFFER_HOT_34_H

class Solution_34 {
public:

    int binary_search( vector<int>& nums , int target , bool find_lowest = true ){
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

    vector<int> searchRange(vector<int>& nums, int target) {
        int low_index = binary_search(nums , target , true);
        int high_index = binary_search(nums , target , false);
        return {low_index , high_index};
    }

};

#endif //OFFER_HOT_34_H

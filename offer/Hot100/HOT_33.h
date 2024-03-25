//
// Created by ÂÞÈðµÑ on 2024/3/1.
//

#ifndef OFFER_HOT_33_H
#define OFFER_HOT_33_H

class Solution_33 {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1)
        {
            /// (nums[0] == target) ? return 0 : return -1;
        }

        int left = 0 , right = nums.size()-1;
            while( left <= right)
            {
                int mid = (left + right) >> 1;
                if(target == nums[mid]) return mid;
                if( nums[left] < nums[mid] )        /// ×ó²àÓÐÐò
                {
                    if( target >= nums[left] && target <= nums[mid-1]){
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }
                }
                else                                /// ÓÒ²àÓÐÐò
                {
                    if( target >= nums[mid+1] && target <= nums[right]){
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }
                }
            }

            return -1;

    }
};

#endif //OFFER_HOT_33_H

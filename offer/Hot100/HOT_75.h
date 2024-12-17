
//
// Created by 罗瑞笛 on 2024/4/2.
//

#ifndef OFFER_HOT_75_H
#define OFFER_HOT_75_H

class Solution_75 {
public:

    /// return 元素 va的最终index
    int partition( vector<int>& nums  , int left, int right) {

        int pivot = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= pivot ) right--;
            nums[left] = nums[right];
            while(left < right && nums[left] <= pivot ) left++;
            nums[right] = nums[left];
        }
        nums[right] = pivot;
        return right;
    }

    void quickSort(vector<int>& nums , int begin , int end)
    {
        if(nums.empty()) return ;
        if( begin >= end) return;

        int index = partition(nums   , begin , end );
        quickSort( nums , begin , index -1);
        quickSort(nums , index+1 , end);
    }

    void sortColors_quick(vector<int>& nums) {
        quickSort(nums, 0 , nums.size()-1);
        return ;
    }

    void sortColors(vector<int>& nums){

        int ptr = 0;    ///  ptr指向当前待确定的位置（非目标Pos【当放置0时，1为非目标】）
                        ///  ptr指向当前待确定的位置（非目标Pos【当放置1时，2为非目标】）
        for(int i = 0 ; i<nums.size() ; i++)        /// i 指针用于寻找下一个0在哪
        {
            if(nums[i] == 0) {
                std::swap( nums[ptr] , nums[i]);
                ptr++;
            }
        }

        /// ptr 此时指向剩余待排序 1，2的第一个位置
        /// 过程中 ptr 指向2
        for( int i = ptr ; i<nums.size() ;++i)
        {
            if(nums[i] == 1){
                std::swap( nums[i] , nums[ptr]);
                ptr++;
            }
        }

    }

};

#endif //OFFER_HOT_75_H

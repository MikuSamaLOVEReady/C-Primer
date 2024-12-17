
//
// Created by ����� on 2024/4/2.
//

#ifndef OFFER_HOT_75_H
#define OFFER_HOT_75_H

class Solution_75 {
public:

    /// return Ԫ�� va������index
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

        int ptr = 0;    ///  ptrָ��ǰ��ȷ����λ�ã���Ŀ��Pos��������0ʱ��1Ϊ��Ŀ�꡿��
                        ///  ptrָ��ǰ��ȷ����λ�ã���Ŀ��Pos��������1ʱ��2Ϊ��Ŀ�꡿��
        for(int i = 0 ; i<nums.size() ; i++)        /// i ָ������Ѱ����һ��0����
        {
            if(nums[i] == 0) {
                std::swap( nums[ptr] , nums[i]);
                ptr++;
            }
        }

        /// ptr ��ʱָ��ʣ������� 1��2�ĵ�һ��λ��
        /// ������ ptr ָ��2
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

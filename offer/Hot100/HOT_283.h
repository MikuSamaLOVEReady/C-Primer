//
// Created by ����� on 2024/3/25.
//

#ifndef OFFER_HOT_283_H
#define OFFER_HOT_283_H

class Solution_283 {
public:

    void swap(vector<int>& nums , int index_a , int index_b , bool& end){

        if( nums[index_a] != nums[index_b] )
        {
            int temp = nums[index_a];
            nums[index_a] = nums[index_b];
            nums[index_b] = temp;
            end  = false;
        }

    }

    void moveZeroes(vector<int>& nums) {

        for(int i = 0 ; i<nums.size() ; ++i) {

            while( nums[i]  == 0 ) {
                int start_index = i;
                int next_index  = i+1;
                bool end = true;       /// �������ÿ�ν�������ͬ��Ԫ�ء�������ȫΪ0 ��ֱ�ӽ���
                while( next_index < nums.size() ){
                    swap(nums , start_index , next_index, end);
                    start_index++;
                    next_index++;
                }
                if(end) return;
            }
        }

    }
};


#endif //OFFER_HOT_283_H

//
// Created by ����� on 2023/6/5.
//

#ifndef OFFER_2460_H
#define OFFER_2460_H
#include <vector>

using namespace std;

//return by value
vector<int> applyOperations(vector<int>& nums) {
    for(int i = 0 ; i< nums.size() - 1; ++i){
            if( nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
    }

    int i = 0; //Ѱ��0Ԫ�ص�index
    int j = 0; //Ѱ�ҷ�0Ԫ��,��Զָ��i����һ��
    while(j< nums.size() ){
        while(nums[i] != 0){
            i++;
        }
        j = i+1;
        while( j < nums.size() && nums[j] == 0 ){ //����j���ܳ��磬��ɵ���β�������ʾ����
            j++;
        }

        if( i>= j || j >= nums.size()) break;
        //��ʱ����i��j
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    return nums;
}

#endif //OFFER_2460_H

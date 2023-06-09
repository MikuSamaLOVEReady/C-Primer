//
// Created by 罗瑞笛 on 2023/6/5.
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

    int i = 0; //寻找0元素的index
    int j = 0; //寻找非0元素,永远指向i的下一个
    while(j< nums.size() ){
        while(nums[i] != 0){
            i++;
        }
        j = i+1;
        while( j < nums.size() && nums[j] == 0 ){ //限制j不能超界，入股到达尾部，则表示结束
            j++;
        }

        if( i>= j || j >= nums.size()) break;
        //此时交换i，j
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    return nums;
}

#endif //OFFER_2460_H

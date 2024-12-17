//
// Created by 罗瑞笛 on 2024/2/28.
//

#ifndef OFFER_HOT_31_H
#define OFFER_HOT_31_H

#include <vector>

class Solution_31 {
public:

    void invers_array( vector<int>& nums , int begin  , int end ){
        while( begin <= end ){
            int tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }

    /// 靠后的大数 想办法调换到 靠前的小数 位置
    void nextPermutation(vector<int>& nums) {

        /// 从后向前 寻找一个相邻的升序
        int j = nums.size()-1;
        int i = nums.size()-2;    /// 小数

        while( i >= 0 ){
            if(nums[i] < nums[j]){
                break; ///此时i、j为相邻升序排列
            }
            i--;
            j--;
        }

        /// 如果 j==0 则表示 升序排列、此时直接逆置所有
//        if(j == 0){
//            // 逆置
//            invers_array(nums, j  , nums.size()-1);
//        }else{
//            int k = nums.size()-1;
//            /// 从后向前找到第一个 > A[i] 的index 【大数】
//            while( nums[k] <= nums[i] ){
//                k--;
//            }
//            swap(nums[k] , nums[i]);
//            /// 逆置 [j,end]
//            invers_array(nums, j  , nums.size()-1);
//        }

        if(j != 0){
            int k = nums.size()-1;
            /// 从后向前找到第一个 > A[i] 的index 【大数】
            while( nums[k] <= nums[i] ){
                k--;
            }
            swap(nums[k] , nums[i]);
        }
        invers_array(nums, j  , nums.size()-1);

    }

};

#endif //OFFER_HOT_31_H

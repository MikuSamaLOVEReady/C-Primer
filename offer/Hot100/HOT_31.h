//
// Created by ����� on 2024/2/28.
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

    /// ����Ĵ��� ��취������ ��ǰ��С�� λ��
    void nextPermutation(vector<int>& nums) {

        /// �Ӻ���ǰ Ѱ��һ�����ڵ�����
        int j = nums.size()-1;
        int i = nums.size()-2;    /// С��

        while( i >= 0 ){
            if(nums[i] < nums[j]){
                break; ///��ʱi��jΪ������������
            }
            i--;
            j--;
        }

        /// ��� j==0 ���ʾ �������С���ʱֱ����������
//        if(j == 0){
//            // ����
//            invers_array(nums, j  , nums.size()-1);
//        }else{
//            int k = nums.size()-1;
//            /// �Ӻ���ǰ�ҵ���һ�� > A[i] ��index ��������
//            while( nums[k] <= nums[i] ){
//                k--;
//            }
//            swap(nums[k] , nums[i]);
//            /// ���� [j,end]
//            invers_array(nums, j  , nums.size()-1);
//        }

        if(j != 0){
            int k = nums.size()-1;
            /// �Ӻ���ǰ�ҵ���һ�� > A[i] ��index ��������
            while( nums[k] <= nums[i] ){
                k--;
            }
            swap(nums[k] , nums[i]);
        }
        invers_array(nums, j  , nums.size()-1);

    }

};

#endif //OFFER_HOT_31_H

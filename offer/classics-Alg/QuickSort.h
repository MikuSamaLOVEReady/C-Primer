//
// Created by ����� on 2023/5/22.
//

#ifndef OFFER_QUICKSORT_H
#define OFFER_QUICKSORT_H

#include <vector>

using namespace std;
//˫ָ�����
int partition(vector<int>& nums , int left , int right){
    int pivot = nums[left];
    /// ����left�ܺ�right���ж��������---------========*****=======------------
    // right ����ȡ��-1 �� left = 0 ��������ڣ���ʱҲ��Ӧ�ý��������������ж�����ȣ������룬���·���Խ��
    // ������������� nums = {1,2,3,4,5,6} ����˳��洢�� ���
    while(left < right){
       //��������while��˳���ǲ��ܵ�����
       //��С��������
        while(left < right && nums[right]> pivot ) right--;
        nums[left] = nums[right];
        //�ҵ�һ����pivotС����
        while(left < right && nums[left] < pivot) left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

void QuickSort( vector<int>& nums , int start , int end){
    if(start >= end) return;
    // end = size - 1
    // start = 0
    int pivot_pos = partition(nums , start , end);      /// ÿ���ܹ�ȷ��һ��λ��
    QuickSort(nums,start , pivot_pos-1);
    QuickSort(nums, pivot_pos+1 , end);
}


#endif //OFFER_QUICKSORT_H

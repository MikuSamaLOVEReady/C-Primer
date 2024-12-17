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
        while(left < right && nums[right]> pivot ) right--;     /// ע�� left < right!!
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



/// ����ÿ�ζ��ܹ�λһ��Ԫ��
/// \param k Ŀ��index quick sort ��С�������С� ��k�� index = K - 1 ��size-k ��ʾ�ƶ����ٴο���ָ����k�� n-1-[n-k] ��ʾ�ƶ��˶��ٴΡ�
int QuickSelect(vector<int>& nums , int l , int r , int k) {

    if(l == r) return nums[l];
    int partition = nums[l];
    /// ����ԭʼ���䡢�ڵݹ鴦ʹ��
    int j = r;
    int i = l;

    while( l < r) {
        while( l < r && nums[r] >= partition ) r--;  /// ���Ҳ࿪ʼ *** ע�� l<r ��������
        nums[l] = nums[r];
        while( l < r && nums[l] < partition) l++;
        nums[r] = nums[l];
    }
    nums[l] = partition;

    /// ֹͣʱ index=l=r  ���< N-K ���������Ҳ� ���������Ѿ����ڷ�Χ��
    if( l < k ){
        return QuickSelect(nums, l+1 , j , k);
    }else{
        return QuickSelect(nums, i , l , k);
    }
}


#endif //OFFER_QUICKSORT_H

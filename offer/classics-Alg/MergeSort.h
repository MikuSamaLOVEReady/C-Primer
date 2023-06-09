//
// Created by ����� on 2023/5/22.
//

#ifndef OFFER_MERGESORT_H
#define OFFER_MERGESORT_H
#include <vector>
using namespace  std;

//����left -> right ֮������Ԫ��ȫ��������
void MergeArray(vector<int>& nums , int left , int right , int mid){

    //�ȱ���һ������, ����nums����Ԫ��
    vector<int> temp = nums;

    //���ս������nums��
    int k = left; //ע�������kֵӦ����Զ��ֵΪleft ���ܸ�0
    int i = left;
    int j = mid+1;
    while( i < mid+1 && j <= right){
        if( temp[i] <= temp[j] ) {
            nums[k] = temp[i];
            k++;
            i++;
        }
        else {
            nums[k] = temp[j];
            k++;
            j++;
        }
    }

    //��������������ˣ���ʼ��ʣ�µĺϲ�
    //����������if���Ƕ����
    if( i == mid+1){
        while(j <= right){
            nums[k] = temp[j];
            j++;
            k++;
        }
    }
    //���ֱ�Ӹĳ�elseô��
    if(j >right){
        while( i < mid+1){
            nums[k] = temp[i];
            i++;
            k++;
        }
    }

}

void MergeSort(vector<int>& nums , int left , int right){
    //�ݹ����
    if(left == right) return;
    int mid = (left+right) / 2;
    MergeSort(nums,left, mid );
    MergeSort(nums,mid+1, right);
    MergeArray(nums, left, right , mid);
}

// ������������ֵ��ͬ����һ�������˴�
bool containsDuplicate(vector<int>& nums) {

    MergeSort(nums,0 , nums.size() - 1);
    for(int i = 0 ; i<nums.size() ;i++){
        if( i+1 !=  nums.size() ) {
            if( nums[i+1] == nums[i] ) return true;
        }
    }
    return false;
}


#endif //OFFER_MERGESORT_H

//
// Created by 罗瑞笛 on 2023/5/22.
//

#ifndef OFFER_MERGESORT_H
#define OFFER_MERGESORT_H
#include <vector>
using namespace  std;

//现在left -> right 之间所有元素全部排完序
void MergeArray(vector<int>& nums , int left , int right , int mid){

    //先备份一个数组, 拷贝nums所有元素
    vector<int> temp = nums;

    //最终结果存入nums中
    int k = left; //注意这里的k值应当永远赋值为left 不能给0
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

    //如果有数组用完了，则开始把剩下的合并
    //这下面两个if都是多余的
    if( i == mid+1){
        while(j <= right){
            nums[k] = temp[j];
            j++;
            k++;
        }
    }
    //这可直接改成else么？
    if(j >right){
        while( i < mid+1){
            nums[k] = temp[i];
            i++;
            k++;
        }
    }

}

void MergeSort(vector<int>& nums , int left , int right){
    //递归出口
    if(left == right) return;
    int mid = (left+right) / 2;
    MergeSort(nums,left, mid );
    MergeSort(nums,mid+1, right);
    MergeArray(nums, left, right , mid);
}

// 排序后，如果两个值相同，则一定仅靠彼此
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

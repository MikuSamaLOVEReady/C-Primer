//
// Created by 罗瑞笛 on 2023/5/22.
//

#ifndef OFFER_QUICKSORT_H
#define OFFER_QUICKSORT_H

#include <vector>

using namespace std;
//双指针遍历
int partition(vector<int>& nums , int left , int right){
    int pivot = nums[left];
    /// 这里left能和right仅判定不相等吗？---------========*****=======------------
    // right 可能取得-1 但 left = 0 的情况存在，此时也不应该进入迭代，如果仅判定不想等，则会进入，导致访问越界
    // 上述情况发生在 nums = {1,2,3,4,5,6} 这种顺序存储的 情况
    while(left < right){
       //下面两个while的顺序是不能掉换的
       //从小到大排列
        while(left < right && nums[right]> pivot ) right--;     /// 注意 left < right!!
        nums[left] = nums[right];
        //找到一个比pivot小的数
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
    int pivot_pos = partition(nums , start , end);      /// 每次能够确定一个位置
    QuickSort(nums,start , pivot_pos-1);
    QuickSort(nums, pivot_pos+1 , end);
}



/// 由于每次都能归位一个元素
/// \param k 目标index quick sort 从小到大排列。 第k大即 index = K - 1 【size-k 表示移动多少次可以指到第k大、 n-1-[n-k] 表示移动了多少次】
int QuickSelect(vector<int>& nums , int l , int r , int k) {

    if(l == r) return nums[l];
    int partition = nums[l];
    /// 保存原始区间、在递归处使用
    int j = r;
    int i = l;

    while( l < r) {
        while( l < r && nums[r] >= partition ) r--;  /// 从右侧开始 *** 注意 l<r 限制条件
        nums[l] = nums[r];
        while( l < r && nums[l] < partition) l++;
        nums[r] = nums[l];
    }
    nums[l] = partition;

    /// 停止时 index=l=r  如果< N-K 则结果会在右侧 并且自身已经不在范围内
    if( l < k ){
        return QuickSelect(nums, l+1 , j , k);
    }else{
        return QuickSelect(nums, i , l , k);
    }
}


#endif //OFFER_QUICKSORT_H

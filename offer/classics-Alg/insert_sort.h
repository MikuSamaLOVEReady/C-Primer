//
// Created by 罗瑞笛 on 2024/5/5.
//

#ifndef OFFER_INSERT_SORT_H
#define OFFER_INSERT_SORT_H

#include <vector>
/// 有稳定性 O(n^2)  /// 原定拆入排序 原地插入排序
/// 从小到大排序
void inser_sort( std::vector<int>& nums ){

    for(int i = 1 ; i< nums.size() ; ++i){
        int cur_va = nums[i];   /// i指向当前待插入元素 类似pivot 先暂存起来
        int cur_index = i-1;    /// cur_index表示第一个小于待插入元素的index
        while( cur_index>=0 && nums[cur_index] > cur_va ) {
            nums[ cur_index+1 ] =  nums[ cur_index ];   /// 把已经排好序的元素中，大于pivot的元素，后移一个位置
            cur_index--;
        }
        nums[cur_index+1] = cur_va ;
    }

}


#endif //OFFER_INSERT_SORT_H

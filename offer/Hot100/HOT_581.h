//
// Created by 罗瑞笛 on 2024/7/14.
//

#ifndef OFFER_HOT_581_H
#define OFFER_HOT_581_H

/// 思路完全错了！！
class Solution_581 {
public:

    /// sort 之后, 与原串对比，第一个不同的元素记为start ，最后一个不同的元素记为end
    /// end -start + 1
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int> sorted;
        for(int i = 0 ; i<nums.size() ; ++i ){
            if (sorted.empty()){
                sorted.insert(sorted.begin(), nums[i]);
            }
            else{
                /// 插入排序
                auto it = sorted.begin();
               for( ; ; ){
                    /// 如果 数值最大，找到末尾
                   if( it == sorted.end()){
                        sorted.push_back(nums[i]);
                       break;
                   }
                   /// 待插入元素 找到合适的插入位置
                   if( *it > nums[i] ){
                        sorted.insert(it ,nums[i]);
                        break;
                   }
                    /// 待插入元素 如果
                    else ++it;
                }
            }
        }

        int start_index  = 0;
        int lase_same_index = 0;
        bool first_dif = true;
        bool update_last = true;
        for( int i = 0 ; i<nums.size() ; ++i ) {
            ///找到第一个不同的节点
            if( sorted[i] != nums[i]  ){
                if( first_dif ){
                    start_index = i;
                    first_dif = false;
                }
                update_last = true;
            }

            /// 继续向后查看 ，如果有新的不同， update_last = ture;
            else if( sorted[i] == nums[i] && update_last  ){
                lase_same_index = i;
                update_last = false;
            }
        }

        return lase_same_index - start_index ;
    }

};


///
class Solution_581_right {
public:
    ///     
    int findUnsortedSubarray(vector<int>& nums) {
        ///
        int begin = 0;
        int end_index = -1;
        int max = -INT_MAX;
        int min = INT_MAX;

        int back_index = nums.size()-1;
        for( int i = 0 ; i<nums.size() ; ++i ){
            /// 从右往左 找begin
            if( min >= nums[back_index] ){
                min = nums[back_index];
            } else {
                begin = back_index;
            }
            back_index--;

            /// 从左往右
            if( max <= nums[i] ){
                max = nums[i];
            }else{
                end_index = i;
            }
        }

        return end_index - begin + 1;
    }

};

#endif //OFFER_HOT_581_H

//
// Created by 罗瑞笛 on 2024/3/25.
//

#ifndef OFFER_HOT_287_H
#define OFFER_HOT_287_H

class Solution_287 {
public:

    int findDuplicate_mysel(vector<int>& nums) {

        int len = nums.size();

        int left  = 1;
        int right = len-1;                  /// 从数字 [ 1....n ] 可能重复的数字就在这其中，想办法从中选一个中间值做判断

        while( left < right ){
            int mid = (left + right) / 2;
            int count = 0;
            for( int va : nums ) {
                if( va <= mid){
                    count++;
                }
            }

            if ( count > mid ){
                right = mid;
            }
            ///  count <= mid 的值全放左侧、一定会重复、 最糟糕全放右侧、
            else {
                left = mid+1;
            }
        }
        return left;
    }



    public:
        int findDuplicate(vector<int>& nums) {
            int len = nums.size(); // n + 1 = len, n = len - 1

            // 在 [1..n] 查找 nums 中重复的元素
            int left = 1;
            int right = len - 1;
            while (left < right) {
                int mid = (left + right) / 2;       /// mid更像是target，

                // nums 中小于等于 mid 的元素的个数
                int count = 0;
                for (int num : nums) {
                    if (num <= mid) {
                        count++;
                    }
                }

                /// 鸽洞原理：  <=目标值 数量过多、
                if (count > mid) {
                    // 下一轮搜索的区间 [left..mid]
                    right = mid;
                } else {
                    // 下一轮搜索的区间 [mid + 1..right]
                    left = mid + 1;
                }

            }
            return left;
        }


};

#endif //OFFER_HOT_287_H

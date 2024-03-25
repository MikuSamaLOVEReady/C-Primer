//
// Created by 罗瑞笛 on 2024/3/25.
//

#ifndef OFFER_HOT_287_H
#define OFFER_HOT_287_H

class Solution_287 {
public:

    int findDuplicate(vector<int>& nums) {

        int len = nums.size();

        int left  = 1;
        int right = len-1;                  /// 从数字 [ 1....n ] 可能重复的数字就在这其中，想办法从中选一个中间值做判断
        int mid = (left + right) / 2;       ///  2

        while( left < right ){

            int count = 0;
            for( int va : nums ) {
                if( va <= mid){
                    count++;
                }
            }

            /// count > mid  就算比mid小的值全放右侧、也一定不够count个、左侧一定有比mid小的值
            if ( count > mid ){


            }
            ///  count <= mid 的值全放左侧、一定会重复、 最糟糕全放右侧、
            else {

            }

        }




    }

};

#endif //OFFER_HOT_287_H

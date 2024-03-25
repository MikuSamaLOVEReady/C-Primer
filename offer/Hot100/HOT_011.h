//
// Created by 罗瑞笛 on 2024/2/24.
//

#ifndef OFFER_HOT_011_H
#define OFFER_HOT_011_H

#include <vector>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0 , end = height.size()-1 ; ///初始双指针、最初结果size
        int cur_max = (end - front) * ( height[front] >= height[end] ? height[end] : height[front]);

        /// 不停用长度换高度
        while(front != end)
        {
            /// 前移end、将原本低一点的高度换大一点
            if( height[end] <= height[front] )
            {
                int cur_end = end;
                while ( cur_end > front && height[cur_end] <= height[end] )
                {
                    cur_end--;
                }
                end = cur_end;
                /// 高度增加、
                int cur_size =  (end - front) * ( height[front] >= height[end] ? height[end] : height[front]);
                cur_max = cur_max > cur_size ? cur_max : cur_size;
            }
            /// 否则后移front、用宽度换高度
            else {
                int cur_front = front;
                while (cur_front < end && height[cur_front] <= height[front])
                {
                    cur_front++;
                }
                front = cur_front;
                int cur_size =  (end - front) * ( height[front] >= height[end] ? height[end] : height[front]);
                cur_max = cur_max > cur_size ? cur_max : cur_size;
            }
        }
        return cur_max;
    }


};

#endif //OFFER_HOT_011_H

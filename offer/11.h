//
// Created by 罗瑞笛 on 2023/7/6.
//

#ifndef OFFER_11_H
#define OFFER_11_H

//暴力枚举 -- O(n^2)
int maxArea(vector<int>& height) {
    int cur_max = INT16_MIN;
    int n = height.size();

    for(int i = 0 ; i < n ; ++i){
        for(int j = i+1 ; j<n ; ++j){
            int heigh = (height[i] <= height[j] ? height[i]:height[j]);
            int val = (j-i) * heigh;
            if(val > cur_max) {cur_max = val;}
        }
    }

    return cur_max;
}


//双指针
/// 总体思路：
/// 定好底边宽度，头尾指针向内缩， 只有比当前两端中低的一方高的时候才可能总的面积更大
/// 当出现高低反转的时候，需要切换搜索方向
/// \param height
/// \return
int maxArea2(vector<int>& height) {
    //确定初始状态
    int front = 0 , end = height.size() - 1;
    int lower_index = (height[front] < height[end] ? front:end);
    int cur_max = INT16_MIN;

    //遍历的过程中 不断更新front 与 end
    while(front != end){
        cur_max = (cur_max > (end - front) * height[lower_index] ? cur_max : (end - front) * height[lower_index]);
        //此时lower_index 是 end指针  前 <- 后 搜索
        if(lower_index == end){
            //找到front - end之间比end稍微高一点的值(不能相等)
            while( lower_index > front && height[lower_index] <= height[end]){
                --lower_index;
            }
            //更新范围
            end = lower_index;
            // 只有当大小反转时，才需要反向查找
            if(height[lower_index] > height[front]){
                lower_index = front;
            }
        }
        //lower_index此时是front  前 -> 后 搜索
        else{
            while( lower_index < end && height[lower_index] <= height[front]){
                ++lower_index;
            }
            //更新范围
            front = lower_index;
            //此时较低的变成了end
            if(height[lower_index] > height[end]){
                lower_index = end;
            }
        }
    }

    return cur_max;
}



#endif //OFFER_11_H

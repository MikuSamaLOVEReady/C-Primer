//
// Created by di on 2023/6/15.
//

#ifndef OFFER_15_H
#define OFFER_15_H

#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    //选择
    for(int i=0 ;  i<nums.size() && nums[i]<=0  ; ++i)
    {
        int front = i+1;
        int end   = nums.size()-1;
        //某一轮结束了
        while(front<end){
            //不等于的时候去重
            while(  front< end && nums[front] + nums[end] + nums[i] > 0 ){
                --end;
                while(front <= end && nums[end] == nums[end+1]) --end;
            }
            while(  front< end && nums[front]+ nums[end] + nums[i] < 0 ){
                ++front;
                while(front <= end && nums[front] == nums[front-1]) ++front;
            }

            //如果后判断 ， 如何去除重复？
            if( nums[front]+ nums[end] + nums[i] == 0  && front< end ){
                vector<int> one = { nums[front], nums[end], nums[i] };
                result.push_back(one);
                ++front; --end;
                //移动 前后指针，继续穷尽所有组合
                while (front< end && nums[end] == nums[end+1]) --end;
                while (front< end && nums[front] == nums[front-1]) ++front;
            }
        }
        //判断前后 是否 已经是已经找过的元素 //pre_int
        while( i+1<nums.size() && nums[i+1] == nums[i] ){
            ++i;
        }
    }

    return result;
}

#endif //OFFER_15_H

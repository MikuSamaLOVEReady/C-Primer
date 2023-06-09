//
// Created by 罗瑞笛 on 2023/5/30.
//

#ifndef OFFER_04_H
#define OFFER_04_H


#include <vector>
using namespace std;

//4. 寻找两个正序数组的中位数
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int LOOK = -3939393;

    int sum_size = nums1.size() + nums2.size();
    bool doub = false;
    int pre  = -1 , cur = -1;
    //开始比较两个数组从小到大
    int a_index = 0 , b_index = 0; //初始都不指向元素，

    //范围控制，如果在双方都没越界的情况下结算，
    for(int i =0 ; i<= sum_size/2 ; i++){
        pre = cur;
        // A数组没有用完，并且B已经用完或B的值更小.
        if( a_index < nums1.size() && (b_index >= nums2.size() || nums1[a_index] < nums2[b_index] ) )
        {
            cur = nums1[a_index++];
        }
        else{
            cur = nums2[b_index++];
        }
    }

    //偶数个元素 eg: 6/2 = 3 （对比次数）
    if(sum_size %2 == 0){
        return (cur+pre)/2.0;
    }else{
        return cur;
    }
}

#endif //OFFER_04_H

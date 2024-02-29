//
// Created by YX on 2024/2/23.
//

#ifndef OFFER_HOT_03_H
#define OFFER_HOT_03_H

#include <vector>

using namespace std;
class Solution {
public:

    ///  *** 递归 ***
    ///  退出条件： 如果 k == 1 直接比较当前 index 哪边更小
    ///           如果 有一侧被用完了 则直接返回另一边中 剩余个数+起始位置-1
    ///  参数：    两数组的 开始index、结束index 、待寻找的index
    int getKth_small( vector<int>& nums_short , int start1 , int end1 , vector<int>& nums , int start2 , int end2 , int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        /// 保证 nums_short 一直是短的那边、如果有空的数组出现也一定是他
        if( len1 > len2) return getKth_small( nums , start2 , end2 , nums_short , start1 , end1, k);

        ///递归出口
        if( k == 1) {
            return  nums_short[start1] < nums[start2] ? nums_short[start1] : nums[start2];
        }

        if( len1 == 0){
            return nums[start2 + k -1];
        }

        ///递归
        int cur_index1 = start1 + min(len1 , k/2) - 1;   /// 当前需要对比大小的 index 、 最大设置为vector末尾 *** -1 不能漏了 ***
        int cur_index2 = start2 + min(len2 , k/2) - 1;

        if( nums_short[cur_index1] < nums[cur_index2])
        {
            /// 舍弃 nums_short 中的数据
            /// 对比完后还需要将 cur_index1 后移
            return getKth_small(nums_short, cur_index1 +1 , end1 , nums , start2 , end2 , k-(cur_index1 - start1 + 1));
        }
        else
        {
            return getKth_small(nums_short, start1 , end1 , nums , cur_index2+1 , end2 , k-(cur_index2 - start2 + 1));
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        bool flag = (m + n) % 2 == 0;           /// 是否为偶数个值
        if(flag)
        {
            int k1 =  (m+n) / 2 ;
            int k2 = (m+n) / 2 + 1;
            int va1 = getKth_small(nums1,0 , nums1.size() -1 , nums2, 0, nums2.size()-1 , k1);
            int va2 = getKth_small(nums1,0 , nums1.size() -1 , nums2, 0, nums2.size()-1 , k2);
            return double(va1 + va2) / 2;
        }
        else
        {
            int k = (m+n) / 2 + 1;
            return getKth_small(nums1,0 , nums1.size() -1 , nums2, 0, nums2.size()-1 , k);
        }
    }


};


#endif //OFFER_HOT_03_H

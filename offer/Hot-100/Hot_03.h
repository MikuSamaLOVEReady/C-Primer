//
// Created by YX on 2024/2/23.
//

#ifndef OFFER_HOT_03_H
#define OFFER_HOT_03_H

#include <vector>

using namespace std;
class Solution {
public:

    ///  *** �ݹ� ***
    ///  �˳������� ��� k == 1 ֱ�ӱȽϵ�ǰ index �ı߸�С
    ///           ��� ��һ�౻������ ��ֱ�ӷ�����һ���� ʣ�����+��ʼλ��-1
    ///  ������    ������� ��ʼindex������index ����Ѱ�ҵ�index
    int getKth_small( vector<int>& nums_short , int start1 , int end1 , vector<int>& nums , int start2 , int end2 , int k)
    {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        /// ��֤ nums_short һֱ�Ƕ̵��Ǳߡ�����пյ��������Ҳһ������
        if( len1 > len2) return getKth_small( nums , start2 , end2 , nums_short , start1 , end1, k);

        ///�ݹ����
        if( k == 1) {
            return  nums_short[start1] < nums[start2] ? nums_short[start1] : nums[start2];
        }

        if( len1 == 0){
            return nums[start2 + k -1];
        }

        ///�ݹ�
        int cur_index1 = start1 + min(len1 , k/2) - 1;   /// ��ǰ��Ҫ�Աȴ�С�� index �� �������Ϊvectorĩβ *** -1 ����©�� ***
        int cur_index2 = start2 + min(len2 , k/2) - 1;

        if( nums_short[cur_index1] < nums[cur_index2])
        {
            /// ���� nums_short �е�����
            /// �Ա������Ҫ�� cur_index1 ����
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
        bool flag = (m + n) % 2 == 0;           /// �Ƿ�Ϊż����ֵ
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

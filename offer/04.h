//
// Created by ����� on 2023/5/30.
//

#ifndef OFFER_04_H
#define OFFER_04_H


#include <vector>
using namespace std;

//4. Ѱ�����������������λ��
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int LOOK = -3939393;

    int sum_size = nums1.size() + nums2.size();
    bool doub = false;
    int pre  = -1 , cur = -1;
    //��ʼ�Ƚ����������С����
    int a_index = 0 , b_index = 0; //��ʼ����ָ��Ԫ�أ�

    //��Χ���ƣ������˫����ûԽ�������½��㣬
    for(int i =0 ; i<= sum_size/2 ; i++){
        pre = cur;
        // A����û�����꣬����B�Ѿ������B��ֵ��С.
        if( a_index < nums1.size() && (b_index >= nums2.size() || nums1[a_index] < nums2[b_index] ) )
        {
            cur = nums1[a_index++];
        }
        else{
            cur = nums2[b_index++];
        }
    }

    //ż����Ԫ�� eg: 6/2 = 3 ���Աȴ�����
    if(sum_size %2 == 0){
        return (cur+pre)/2.0;
    }else{
        return cur;
    }
}

#endif //OFFER_04_H

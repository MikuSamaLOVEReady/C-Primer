//
// Created by ����� on 2024/3/29.
//

#ifndef OFFER_HOT_215_H
#define OFFER_HOT_215_H

#include <map>

class Solution_215 {
public:
    int findKthLargest_slow(vector<int>& nums, int k) {
        map<int , int , std::greater<int> > mp;      ///  value �� count
        for(auto va : nums){
            mp[va] += 1;
        }

        auto mp_begin = mp.begin();
        int move_times = k-1;
        while( move_times > 0 )
        {
            int count = (*mp_begin).second; /// �����ƶ���������
            while(move_times >0 && count > 0 )  /// �ܴ�����ʣ�ࡢ���ҵ�ǰ
            {
                count--;
                move_times--;
            }

            if( count != 0 ) /// ������δ�ƶ��� �� ���ƶ��������Ĵ�����ͣ���ظ�Ԫ�ش�
            {
                return (*mp_begin).first;   /// mp_begin ����ƶ�
            }
            mp_begin++;
        }
        return (*mp_begin).first;

    }


    /// find
    void quickSelect( vector<int>& nums , int left , int right ) {

        int pivot = nums[left]; //


    }

    int findKthLargest(vector<int>& nums, int k) {




    }


};


#endif //OFFER_HOT_215_H

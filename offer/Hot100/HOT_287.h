//
// Created by ����� on 2024/3/25.
//

#ifndef OFFER_HOT_287_H
#define OFFER_HOT_287_H

class Solution_287 {
public:

    int findDuplicate(vector<int>& nums) {

        int len = nums.size();

        int left  = 1;
        int right = len-1;                  /// ������ [ 1....n ] �����ظ������־��������У���취����ѡһ���м�ֵ���ж�
        int mid = (left + right) / 2;       ///  2

        while( left < right ){

            int count = 0;
            for( int va : nums ) {
                if( va <= mid){
                    count++;
                }
            }

            /// count > mid  �����midС��ֵȫ���ҲࡢҲһ������count�������һ���б�midС��ֵ
            if ( count > mid ){


            }
            ///  count <= mid ��ֵȫ����ࡢһ�����ظ��� �����ȫ���Ҳࡢ
            else {

            }

        }




    }

};

#endif //OFFER_HOT_287_H

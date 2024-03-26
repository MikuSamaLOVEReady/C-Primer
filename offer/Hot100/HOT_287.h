//
// Created by ����� on 2024/3/25.
//

#ifndef OFFER_HOT_287_H
#define OFFER_HOT_287_H

class Solution_287 {
public:

    int findDuplicate_mysel(vector<int>& nums) {

        int len = nums.size();

        int left  = 1;
        int right = len-1;                  /// ������ [ 1....n ] �����ظ������־��������У���취����ѡһ���м�ֵ���ж�

        while( left < right ){
            int mid = (left + right) / 2;
            int count = 0;
            for( int va : nums ) {
                if( va <= mid){
                    count++;
                }
            }

            if ( count > mid ){
                right = mid;
            }
            ///  count <= mid ��ֵȫ����ࡢһ�����ظ��� �����ȫ���Ҳࡢ
            else {
                left = mid+1;
            }
        }
        return left;
    }



    public:
        int findDuplicate(vector<int>& nums) {
            int len = nums.size(); // n + 1 = len, n = len - 1

            // �� [1..n] ���� nums ���ظ���Ԫ��
            int left = 1;
            int right = len - 1;
            while (left < right) {
                int mid = (left + right) / 2;       /// mid������target��

                // nums ��С�ڵ��� mid ��Ԫ�صĸ���
                int count = 0;
                for (int num : nums) {
                    if (num <= mid) {
                        count++;
                    }
                }

                /// �붴ԭ��  <=Ŀ��ֵ �������ࡢ
                if (count > mid) {
                    // ��һ������������ [left..mid]
                    right = mid;
                } else {
                    // ��һ������������ [mid + 1..right]
                    left = mid + 1;
                }

            }
            return left;
        }


};

#endif //OFFER_HOT_287_H

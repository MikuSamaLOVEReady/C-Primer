//
// Created by ����� on 2024/7/14.
//

#ifndef OFFER_HOT_581_H
#define OFFER_HOT_581_H

/// ˼·��ȫ���ˣ���
class Solution_581 {
public:

    /// sort ֮��, ��ԭ���Աȣ���һ����ͬ��Ԫ�ؼ�Ϊstart �����һ����ͬ��Ԫ�ؼ�Ϊend
    /// end -start + 1
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int> sorted;
        for(int i = 0 ; i<nums.size() ; ++i ){
            if (sorted.empty()){
                sorted.insert(sorted.begin(), nums[i]);
            }
            else{
                /// ��������
                auto it = sorted.begin();
               for( ; ; ){
                    /// ��� ��ֵ����ҵ�ĩβ
                   if( it == sorted.end()){
                        sorted.push_back(nums[i]);
                       break;
                   }
                   /// ������Ԫ�� �ҵ����ʵĲ���λ��
                   if( *it > nums[i] ){
                        sorted.insert(it ,nums[i]);
                        break;
                   }
                    /// ������Ԫ�� ���
                    else ++it;
                }
            }
        }

        int start_index  = 0;
        int lase_same_index = 0;
        bool first_dif = true;
        bool update_last = true;
        for( int i = 0 ; i<nums.size() ; ++i ) {
            ///�ҵ���һ����ͬ�Ľڵ�
            if( sorted[i] != nums[i]  ){
                if( first_dif ){
                    start_index = i;
                    first_dif = false;
                }
                update_last = true;
            }

            /// �������鿴 ��������µĲ�ͬ�� update_last = ture;
            else if( sorted[i] == nums[i] && update_last  ){
                lase_same_index = i;
                update_last = false;
            }
        }

        return lase_same_index - start_index ;
    }

};


///
class Solution_581_right {
public:
    ///     
    int findUnsortedSubarray(vector<int>& nums) {
        ///
        int begin = 0;
        int end_index = -1;
        int max = -INT_MAX;
        int min = INT_MAX;

        int back_index = nums.size()-1;
        for( int i = 0 ; i<nums.size() ; ++i ){
            /// �������� ��begin
            if( min >= nums[back_index] ){
                min = nums[back_index];
            } else {
                begin = back_index;
            }
            back_index--;

            /// ��������
            if( max <= nums[i] ){
                max = nums[i];
            }else{
                end_index = i;
            }
        }

        return end_index - begin + 1;
    }

};

#endif //OFFER_HOT_581_H

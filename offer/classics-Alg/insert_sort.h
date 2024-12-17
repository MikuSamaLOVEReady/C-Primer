//
// Created by ����� on 2024/5/5.
//

#ifndef OFFER_INSERT_SORT_H
#define OFFER_INSERT_SORT_H

#include <vector>
/// ���ȶ��� O(n^2)  /// ԭ���������� ԭ�ز�������
/// ��С��������
void inser_sort( std::vector<int>& nums ){

    for(int i = 1 ; i< nums.size() ; ++i){
        int cur_va = nums[i];   /// iָ��ǰ������Ԫ�� ����pivot ���ݴ�����
        int cur_index = i-1;    /// cur_index��ʾ��һ��С�ڴ�����Ԫ�ص�index
        while( cur_index>=0 && nums[cur_index] > cur_va ) {
            nums[ cur_index+1 ] =  nums[ cur_index ];   /// ���Ѿ��ź����Ԫ���У�����pivot��Ԫ�أ�����һ��λ��
            cur_index--;
        }
        nums[cur_index+1] = cur_va ;
    }

}


#endif //OFFER_INSERT_SORT_H

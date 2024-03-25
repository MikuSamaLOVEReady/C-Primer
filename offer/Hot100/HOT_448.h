//
// Created by ����� on 2024/3/22.
//

#ifndef OFFER_HOT_448_H
#define OFFER_HOT_448_H

class Solution_448 {
public:
    vector<int> findDisappearedNumbers_extraMemo(vector<int>& nums) {

        vector<bool> in_nums(nums.size() + 1 , false );
        vector<int>  res;
        for( int va : nums ) {
            in_nums[va] = true;
        }
       for(int i = 1 ; i<in_nums.size() ; ++i){
            if(!in_nums[i]) res.push_back(i);
       }
       return res;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>  res;
        int n = nums.size();

        for(int i = 0 ; i<nums.size() ;++i){
            // int index = nums[i]%n - 1;  ///  ȡģ ���������Ѿ����ӹ�n����ֵ��ͨ��ȡģ��ԭ ������8��������ܳ��
            int index = (nums[i] - 1 )%n ; ///  nums[i] ->  1.... size()   -- {-1} -->  0 .... size()-1 ��ֱ��ȡģ�����index��
            nums[index] += n;
        }

        for( int i = 0 ; i<nums.size() ; ++i){
            if( nums[i] <= n )          /// ����� <= n�� ���ʾû�б��ӹ�n ��Ҳ�ͱ�ʾindex��ԭnums�в�����
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
};


#endif //OFFER_HOT_448_H

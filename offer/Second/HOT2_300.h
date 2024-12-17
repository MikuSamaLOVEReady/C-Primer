//
// Created by ����� on 2024/8/3.
//

#ifndef OFFER_HOT2_300_H
#define OFFER_HOT2_300_H

#include <vector>
using namespace std;

/// ÿ�����ֶ�����������Ҫ�Ŀ�ͷԪ�� XX ����
class Solution_300_2 {
public:
    int lengthOfLIS_wrong(vector<int>& nums) {
        int result = 0;
        //1.��������Ԫ�أ�������Ϊ��ͷO(n^2)
        for( int i = 0 ; i<nums.size() ;++i){
            int cur_va = nums[i];
            int cur_size = 1;
            // TODO�� �Ӻ���ǰ�����
            for(int j=i ; j<nums.size() ; ++j){
                if(nums[j] >  cur_va){
                    cur_va = nums[j];
                    cur_size++;
                }
            }
            result = result > cur_size ? result : cur_size;
        }
        return result;
    }

    /// ���ڱ�ʾ ��index��β��ʱ_��������󳤶�
    /// �Ӻ���ǰ�ݹ�
    int dfs(vector<int>& nums , int index , vector<int>& memo){
        /// memo[i]��¼��nums��i��Ϊ��βʱ����������г���
        if( memo[index] > 0 ) {
            return memo[index];
        }
        int result = 0;
        for( int i = index-1 ; i>=0 ; i-- ){
            /// ö��indx֮ǰ����i��βʱ����󳤶�
            if(nums[i] < nums[index]) {
               result = max(dfs(nums , i, memo), result);
            }
        }
        result += 1;
        memo[index] = result;
        return result;
    }

    int lengthOfLIS(vector<int>& nums) {

        vector<int> memo(nums.size() , 0);
        /// ����ÿһ��������Ϊ��β��index
        int ans = 0;
        for( int i = 0; i<nums.size() ; ++i){
            int cur_ans = dfs(nums, i,memo);
            ans = max ( ans ,  cur_ans);
        }
        return ans;
    }

};

#endif //OFFER_HOT2_300_H

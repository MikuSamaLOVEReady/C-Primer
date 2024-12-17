//
// Created by 罗瑞笛 on 2024/8/3.
//

#ifndef OFFER_HOT2_300_H
#define OFFER_HOT2_300_H

#include <vector>
using namespace std;

/// 每个数字都可能是我想要的开头元素 XX 错误！
class Solution_300_2 {
public:
    int lengthOfLIS_wrong(vector<int>& nums) {
        int result = 0;
        //1.遍历所有元素，以他们为开头O(n^2)
        for( int i = 0 ; i<nums.size() ;++i){
            int cur_va = nums[i];
            int cur_size = 1;
            // TODO： 从后向前会更快
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

    /// 用于表示 以index结尾的时_子序列最大长度
    /// 从后往前递归
    int dfs(vector<int>& nums , int index , vector<int>& memo){
        /// memo[i]记录以nums【i】为结尾时的最大子序列长度
        if( memo[index] > 0 ) {
            return memo[index];
        }
        int result = 0;
        for( int i = index-1 ; i>=0 ; i-- ){
            /// 枚举indx之前的以i结尾时的最大长度
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
        /// 遍历每一个可能作为结尾的index
        int ans = 0;
        for( int i = 0; i<nums.size() ; ++i){
            int cur_ans = dfs(nums, i,memo);
            ans = max ( ans ,  cur_ans);
        }
        return ans;
    }

};

#endif //OFFER_HOT2_300_H

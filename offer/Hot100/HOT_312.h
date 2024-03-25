//
// Created by 罗瑞笛 on 2024/3/20.
//

#ifndef OFFER_HOT_3_1_H
#define OFFER_HOT_3_1_H

class Solution_312 {
public:

    int cur_max = 0;

    ///
    /// \param nums
    /// \param in_select 从i向左  向右查找
    /// \param i 一定是入选
    /// \return
    int three_sum(const vector<int>& nums , const vector<bool>& in_select  ,int mid_index)
    {
        int left_va = 1;
        for(int i = mid_index-1 ; i>=0 ; i-- ){
            if( !in_select[i] )
            {
                left_va = nums[i];
                break;
            }
        }   /// 如果没找到、left_va 仍然是 1

        int right_va = 1;
        for(int j = mid_index+1 ; j < in_select.size() ; j++ ){
            if( !in_select[j] )
            {
                right_va = nums[j];
                break;
            }
        }

        return  right_va * nums[mid_index] * left_va;
    }

    void dfs(vector<int>& nums , vector<bool>& in_select , int cur_sum ) {

        for(int i = 0 ; i < in_select.size() ; ++i){
            if(in_select[i] ) continue;
            /// 找到第一个没有被选入的 数字
            in_select[i] = true;
            int cur_va  = three_sum(nums , in_select , i);
            cur_sum += cur_va;
            dfs(nums , in_select , cur_sum);
            cur_sum -= cur_va;      ///回溯
            in_select[i] = false;
        }

        /// 如果都被选完了
        if( cur_sum > cur_max ) {
            cur_max = cur_sum;
            return;
        }
    }

    int maxCoins_timeout(vector<int>& nums) {
        int sum = 0;
        vector<bool> in_select (nums.size() , false );

        dfs(nums , in_select , sum);
        return cur_max;
    }

    int maxCoins(vector<int>& nums) {

        /// [i][j] == 表示开区间内获得的最大金币 Q：为什么要开区间？ A：最后剩余 = [i]*[k]*[j]
        nums.insert(nums.begin(),1);
        nums.insert(nums.end() , 1);
        vector<vector<int>> dp( nums.size() , vector<int>(nums.size()));


        /// dp[i][j] 、j-i = 2时、内部含有3个元素，  dp[0][3] 含有4个元素，需要所有dp含有3个元素的全部算出。
        /// 即长度需要从小到大
        for(int len = 3  ; len <= nums.size() ; ++len)
        {
            for(int i = 0 ; i <= nums.size() - len ; ++i)    /// i+len（本次的长度）-1 => 结尾处的index = 总长（ nums.size() ）- 1
            {
                /// 从   [i] --> [i+len-1] 选一个k ，使得 dp[i][i+len-1]最大
                /// dp[i][i+len-1] = dp[i][k] + dp[k][j = i+len-1 ]
                int cur_max = 0;
                for(int k = i+1 ; k < i+len-1 ;++k)
                {
                    int va =  dp[i][k] + dp[k][i+len-1] + nums[i]*nums[i+len-1]*nums[k];
                    cur_max = va > cur_max ? va : cur_max;
                }
                dp[i][i+len-1] = cur_max;
            }
        }

        /// 需要增加一个额外的 head & tail
        return  dp[0][nums.size()-1];
    }



};

#endif //OFFER_HOT_3_1_H

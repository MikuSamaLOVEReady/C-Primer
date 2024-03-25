//
// Created by ����� on 2024/3/20.
//

#ifndef OFFER_HOT_3_1_H
#define OFFER_HOT_3_1_H

class Solution_312 {
public:

    int cur_max = 0;

    ///
    /// \param nums
    /// \param in_select ��i����  ���Ҳ���
    /// \param i һ������ѡ
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
        }   /// ���û�ҵ���left_va ��Ȼ�� 1

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
            /// �ҵ���һ��û�б�ѡ��� ����
            in_select[i] = true;
            int cur_va  = three_sum(nums , in_select , i);
            cur_sum += cur_va;
            dfs(nums , in_select , cur_sum);
            cur_sum -= cur_va;      ///����
            in_select[i] = false;
        }

        /// �������ѡ����
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

        /// [i][j] == ��ʾ�������ڻ�õ������ Q��ΪʲôҪ�����䣿 A�����ʣ�� = [i]*[k]*[j]
        nums.insert(nums.begin(),1);
        nums.insert(nums.end() , 1);
        vector<vector<int>> dp( nums.size() , vector<int>(nums.size()));


        /// dp[i][j] ��j-i = 2ʱ���ڲ�����3��Ԫ�أ�  dp[0][3] ����4��Ԫ�أ���Ҫ����dp����3��Ԫ�ص�ȫ�������
        /// ��������Ҫ��С����
        for(int len = 3  ; len <= nums.size() ; ++len)
        {
            for(int i = 0 ; i <= nums.size() - len ; ++i)    /// i+len�����εĳ��ȣ�-1 => ��β����index = �ܳ��� nums.size() ��- 1
            {
                /// ��   [i] --> [i+len-1] ѡһ��k ��ʹ�� dp[i][i+len-1]���
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

        /// ��Ҫ����һ������� head & tail
        return  dp[0][nums.size()-1];
    }



};

#endif //OFFER_HOT_3_1_H

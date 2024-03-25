//
// Created by ����� on 2024/3/2.
//

#ifndef OFFER_PERMUTE_H
#define OFFER_PERMUTE_H

class Solution_LCR_083 {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        /// ����ѡ��
        vector<bool> on_Path( nums.size() , false );
        /// vector<int> cur(nums.size());
        vector<int> cur{};
        //dfs(0 , on_Path , cur ,nums);
        dfs_next(0 , on_Path , cur ,nums);
        return res;
    }

    /// \param n ��ʾ��ǰ��n������Ӧ���Ƕ���
    void dfs(int n , vector<bool>& on_Path , vector<int>& cur , vector<int>& nums)
    {
       if( n == on_Path.size())     /// index-n �Ѿ������� ���һ��Ԫ�ص���һ����
       {
           res.push_back(cur);
           return;
       }

        for(int i = 0 ; i<on_Path.size() ;++i)
        {
            /// �����ǰ ���ֲ��ڽ���С����������
            if(!on_Path[i])
            {
                on_Path[i] = true;
                cur[n] = nums[i];
                dfs( n+1 , on_Path , cur , nums);
                /// �ָ��ֳ�
                on_Path[i] = false;
            }
        }
    }

    void dfs_next (int n , vector<bool>& on_Path , vector<int>& cur , vector<int>& nums )
    {
        if( n == nums.size() )
        {
            res.push_back(cur);
            return;
        }

        for(int i = 0 ; i<nums.size() ; ++i)
        {
            if( !on_Path[i] )
            {
                cur.push_back(nums[i]);
                on_Path[i] = true;
                dfs_next(n+1 , on_Path , cur , nums);
                on_Path[i] = false;
                cur.pop_back();
            }
        }
        return;
    }














    /// ������ݸ������
    //void DFS(int p, int n, vector<int> nums, bool st[21], vector<int> temp, vector<vector<int>>& re) {
        //     if(p>n) {
        //         re.push_back(temp);
        //     }
        //     else {
        //         for(int i=0;i<n;i++) {
        //             if(!st[i]) {
        //                 temp.push_back(nums[i]);
        //                 st[i] = true;
        //                 DFS(p+1, n, nums, st, temp, re);
        //                 st[i] = false;
        //                 temp.pop_back();
        //             }
        //         }
        //     }
        // }

};

#endif //OFFER_PERMUTE_H

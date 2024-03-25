//
// Created by ����� on 2024/3/16.
//

#ifndef OFFER_HOT_78_H
#define OFFER_HOT_78_H

class Solution_78 {
public:
    vector<vector<int>> subsets_wrong(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for( int i = 1 ; i<= n ; ++i){  /// �Ӽ� size

            /// ��ʼ��size = i ���ִ�
            auto it_sub_begin  = nums.begin();
            auto it_sub_end    = nums.begin() + i;
            while ( it_sub_end <= nums.end() ) {
                vector<int> sub_set(it_sub_begin , it_sub_end);
                res.push_back(sub_set);
                it_sub_begin++;
                it_sub_end = it_sub_begin + i;
            }
        }
        return res;
    }

    /// �޷������
    vector<vector<int>> subsets_wrong_2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        /// sub-set�� Ԥ��size [ 0 ] ��������
        for( int va : nums)
        {
            vector<int> cur_0{va};
            res.push_back(cur_0);
        }
        vector<int> cur_1{};
        res.push_back(cur_1);           /// ��set ����

        for( int i = 1  ; i<n ; ++i){           /// i ��ʾ�� sub-set�� Ԥ��size [ 1 ---> n-1 ]   : ���sub ��ʼλ��֮������һ��
            for( int j = 0 ; j< n ; ++j){       /// j ��ʾsub set ����ʼindex
                auto begin = nums.begin()+j;
                auto end = begin + i;
                if( end > nums.end()) break;  ///  ����������ַ������ޡ���ֱ��continue
                vector<int> pre_subset(begin , end);    /// ���������顢
                if( pre_subset.size() >= i )

                /// �� end ��ʼ����һ���µ�Ԫ��(��c��ʼ)    eg: n == 3 :��a,b��, c , d , e , f
                for(auto it_new = end ; it_new != nums.end() ; ++it_new){
                    vector<int> cur_res =  pre_subset;
                    cur_res.push_back(*it_new);
                    res.push_back(cur_res);
                }
            }
        }

        return res;
    }


    /// DFS-����
    vector<vector<int>> ans;
    /// \param start ��һ�ֿ�ѡ��index��ʼλ��
    void dfs(vector<int>& nums , vector<int>& cur , int start)
    {
        ans.push_back(cur);
        for( int i = start ; i<nums.size() ; ++i)
        {
            cur.push_back(nums[i]);
            dfs(nums , cur , i+1);      /// i+1 ÿ�ζ�ѡ��ǰ����Ԫ��֮�������Ԫ�ء��Ӷ���֤���ظ�
            cur.pop_back();         ///���ݡ���ԭ
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> cur{};
        dfs(nums , cur , 0);
        return ans;
    }

};

#endif //OFFER_HOT_78_H

//
// Created by 罗瑞笛 on 2024/3/16.
//

#ifndef OFFER_HOT_78_H
#define OFFER_HOT_78_H

class Solution_78 {
public:
    vector<vector<int>> subsets_wrong(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for( int i = 1 ; i<= n ; ++i){  /// 子集 size

            /// 初始化size = i 的字串
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

    /// 无法穷尽可能
    vector<vector<int>> subsets_wrong_2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        /// sub-set的 预设size [ 0 ] 单独处理
        for( int va : nums)
        {
            vector<int> cur_0{va};
            res.push_back(cur_0);
        }
        vector<int> cur_1{};
        res.push_back(cur_1);           /// 空set 补充

        for( int i = 1  ; i<n ; ++i){           /// i 表示了 sub-set的 预设size [ 1 ---> n-1 ]   : 需从sub 起始位子之后再找一个
            for( int j = 0 ; j< n ; ++j){       /// j 表示sub set 的起始index
                auto begin = nums.begin()+j;
                auto end = begin + i;
                if( end > nums.end()) break;  ///  如果超过了字符串上限、则直接continue
                vector<int> pre_subset(begin , end);    /// 待纳入数组、
                if( pre_subset.size() >= i )

                /// 从 end 开始加入一个新的元素(从c开始)    eg: n == 3 :【a,b】, c , d , e , f
                for(auto it_new = end ; it_new != nums.end() ; ++it_new){
                    vector<int> cur_res =  pre_subset;
                    cur_res.push_back(*it_new);
                    res.push_back(cur_res);
                }
            }
        }

        return res;
    }


    /// DFS-回溯
    vector<vector<int>> ans;
    /// \param start 下一轮可选的index起始位置
    void dfs(vector<int>& nums , vector<int>& cur , int start)
    {
        ans.push_back(cur);
        for( int i = start ; i<nums.size() ; ++i)
        {
            cur.push_back(nums[i]);
            dfs(nums , cur , i+1);      /// i+1 每次都选当前纳入元素之后的其他元素、从而保证无重复
            cur.pop_back();         ///回溯、还原
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

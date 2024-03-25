//
// Created by 罗瑞笛 on 2024/3/11.
//

#ifndef OFFER_HOT_56_H
#define OFFER_HOT_56_H

class Solution_56 {
public:


    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<string>> ans;
        /// 遍历所有
        std::sort( intervals.begin() , intervals.end() , [](const std::vector<int>& a, const std::vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        res.push_back( *(intervals.begin()) );

        /// 区间已有序、分类讨论
        /// case1：  vec[0] 左边界不在 res[size-1] 的右侧边界内、则表示是新的分段、直接 res.push
        /// case2:  vec[0] 左边界在  res[size-1] 的右侧边界内 (vec[0] <= res[size-1][0] )、 则将两者右边界比较
        for( auto& vec : intervals){
            /// res[res.size()-1] 一直访问结果末尾、
                if( vec[0] > res[res.size()-1][1] ){
                    res.push_back( vec );
                }
                else{
                    res[res.size()-1][1] = vec[1] > res[res.size()-1][1]  ?  vec[1] : res[res.size()-1][1];
                }
        }
        return res;
    }

};


#endif //OFFER_HOT_56_H

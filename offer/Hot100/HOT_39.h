//
// Created by 罗瑞笛 on 2024/3/2.
//

#ifndef OFFER_HOT_39_H
#define OFFER_HOT_39_H

class Solution_39 {
public:

    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur{} ;
        dfs(candidates , target, cur , 0);
        return res;
    }

private:
    void dfs( vector<int>& candidates , int target ,  vector<int>& cur_vec , int index)
    {
        /// if( target == candidates[index]) /// X 错误、在进入DFS之前、就计算过了纳入[i]后的结果、现在只需要判定是否成功
        if(target == 0){
            res.push_back(cur_vec);
            return;
        }
        /// 如果当前 剩余值 - 被选元素  < 0 则直接返回即可
        else if ( target < 0 ){
            return;
        }
        else
        {
            ///  由于元素可重复、故下一轮dfs依然可以从当前元素继续、只不过、在下一轮中无法再选 本层已经选过的
            for( int i = index ; i< candidates.size() ; ++i)
            {
                cur_vec.push_back(candidates[i]);
                dfs(candidates, target-candidates[i] , cur_vec , i);
                cur_vec.pop_back();
            }
        }
        return ;
    }


};

#endif //OFFER_HOT_39_H

//
// Created by ����� on 2024/3/2.
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
        /// if( target == candidates[index]) /// X �����ڽ���DFS֮ǰ���ͼ����������[i]��Ľ��������ֻ��Ҫ�ж��Ƿ�ɹ�
        if(target == 0){
            res.push_back(cur_vec);
            return;
        }
        /// �����ǰ ʣ��ֵ - ��ѡԪ��  < 0 ��ֱ�ӷ��ؼ���
        else if ( target < 0 ){
            return;
        }
        else
        {
            ///  ����Ԫ�ؿ��ظ�������һ��dfs��Ȼ���Դӵ�ǰԪ�ؼ�����ֻ����������һ�����޷���ѡ �����Ѿ�ѡ����
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

//
// Created by ÂÞÈðµÑ on 2024/3/6.
//

#ifndef OFFER_HOT_46_H
#define OFFER_HOT_46_H

class Solution_46 {
public:

    vector<vector<int>> res;
    void dfs_46( int index , vector<int>& nums , vector<bool>& On_Path , vector<int>& cur)
    {
        if(index == nums.size())
        {
            res.push_back(cur);
            return ;
        }

        for(int i = 0  ; i<nums.size() ;++i)
        {
            if(On_Path[i] == false)
            {
                cur.push_back(nums[i]);
                On_Path[i] = true;
                dfs_46(index+1 , nums, On_Path , cur);
                On_Path[i] = false;
                cur.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums ) {
        vector<bool> On_Path(nums.size() , false);
        vector<int> cur;
        dfs_46( 0, nums , On_Path , cur);
        return res;
    }

};

#endif //OFFER_HOT_46_H

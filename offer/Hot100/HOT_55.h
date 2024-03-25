//
// Created by 罗瑞笛 on 2024/3/11.
//

#ifndef OFFER_HOT_55_H
#define OFFER_HOT_55_H




class Solution_55 {
public:
    /// 每次找寻 nums[cur] -> nums[cur+nums[cur]] 之间下一步最大值、一直到 cur+nums[cur] >= nums.size()
    bool canJump(vector<int>& nums) {

        int dp = 0;         /// 记录当前所能到达的最远index
        for(int i = 0 ; i<nums.size() ; i++) {
            if(i > dp ) return false;
            else {
                dp = max(dp , i+nums[i]);
            }
        }
        return true;

    }
};

#endif //OFFER_HOT_55_H

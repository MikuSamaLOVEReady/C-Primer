//
// Created by ����� on 2024/3/11.
//

#ifndef OFFER_HOT_55_H
#define OFFER_HOT_55_H




class Solution_55 {
public:
    /// ÿ����Ѱ nums[cur] -> nums[cur+nums[cur]] ֮����һ�����ֵ��һֱ�� cur+nums[cur] >= nums.size()
    bool canJump(vector<int>& nums) {

        int dp = 0;         /// ��¼��ǰ���ܵ������Զindex
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

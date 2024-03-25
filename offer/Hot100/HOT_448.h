//
// Created by 罗瑞笛 on 2024/3/22.
//

#ifndef OFFER_HOT_448_H
#define OFFER_HOT_448_H

class Solution_448 {
public:
    vector<int> findDisappearedNumbers_extraMemo(vector<int>& nums) {

        vector<bool> in_nums(nums.size() + 1 , false );
        vector<int>  res;
        for( int va : nums ) {
            in_nums[va] = true;
        }
       for(int i = 1 ; i<in_nums.size() ; ++i){
            if(!in_nums[i]) res.push_back(i);
       }
       return res;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>  res;
        int n = nums.size();

        for(int i = 0 ; i<nums.size() ;++i){
            // int index = nums[i]%n - 1;  ///  取模 可能遇到已经被加过n的数值、通过取模还原 【遇到8会有问题艹】
            int index = (nums[i] - 1 )%n ; ///  nums[i] ->  1.... size()   -- {-1} -->  0 .... size()-1 【直接取模获得真index】
            nums[index] += n;
        }

        for( int i = 0 ; i<nums.size() ; ++i){
            if( nums[i] <= n )          /// 如果有 <= n的 则表示没有被加过n ，也就表示index在原nums中不存在
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
};


#endif //OFFER_HOT_448_H

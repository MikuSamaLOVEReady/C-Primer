//
// Created by 罗瑞笛 on 2024/2/26.
//

#ifndef OFFER_HOT_15_H
#define OFFER_HOT_15_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution_015 {
public:
    /// BUG:有误无法排除重复组
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            int target = -nums[i];
            /// <value 、 index>
            unordered_multimap<int , int> hasvisted;
            for( int j = i+1 ; j<nums.size() ; j++ )
            {
                int va = target - nums[j] ;  /// 待寻找的第二个数字
                auto it = hasvisted.find(va);
                if( it != hasvisted.end() )
                {
                    res.push_back( { nums[i] , nums[j] , it->first } );
                }
                hasvisted.insert(make_pair(nums[j] , j));
            }
        }
        return res;
    }



};

///
vector<vector<int>> threeSum_real(vector<int>& nums) {

    vector<vector<int>> res;
    std::sort(nums.begin(), nums.end());    /// 仍然需要先排好序
    if( nums.size() == 0 || nums[0] > 0 ) return {};  /// 特殊情况

    for(int i = 0 ; i<nums.size() ; ++i)
    {
        while( nums[i] == nums[i+1]) ++i; ///跳过所有重复的起始位置
        //if(i>0 && nums[i] == nums[i-1]) continue;

        int left = i+1;
        int right = nums.size()-1;

        while (left < right)
        {
            if( nums[left] + nums[i] + nums[right] == 0)
            {
                res.push_back( {nums[left] , nums[i] , nums[right]} );
                /// *** 注意这里只是 向前向后试探了一个位置、本质上还没移动到不同的元素
                while( left < right && nums[left] == nums[left+1])
                    left++;
                while( left < right && nums[right] == nums[right-1])
                    right--;
                left++;
                right--;
            }
            else if ( nums[left] + nums[i] + nums[right] < 0 )  /// 小的不够大、
            {
                left++;
            }
            else{
                right--;    /// 大的太大了
            }
        }
    }
    return res;
}



#endif //OFFER_HOT_15_H

//
// Created by 罗瑞笛 on 2024/2/26.
//

#ifndef OFFER_HOT_01_H
#define OFFER_HOT_01_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        /// <value 、 index>
        unordered_map<int , int> visited_num;
        for (int i = 0; i < nums.size(); ++i)
        {
            //book_co.find()
            int va = target - nums[i]; /// 待寻找的第二个数字
            if( visited_num.find(va) != visited_num.end() )
            {
               return { visited_num.find(va)->second , i };
            }
            visited_num[nums[i]] = i;   ///与 at的区别
        }
        return {};
    }


};


#endif //OFFER_HOT_01_H

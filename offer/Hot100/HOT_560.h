//
// Created by 罗瑞笛 on 2024/7/14.
//

#ifndef OFFER_HOT_560_H
#define OFFER_HOT_560_H

#include <unordered_map>

class Solution_560 {
public:
    int count = 0;
    /// 每一个元素都可以为开始元素 , 一直便利到结尾，一旦

    void ite_to_end( vector<int>& nums , int begin_index , int k ) {
        for( int i = begin_index;  i<nums.size()  ; ++i ){
             k -= nums[i];
             if(k == 0) count++;
        }
    }

    int subarraySum(vector<int>& nums, int k) {
        for( int i = 0 ; i<nums.size() ; ++i ){
            ite_to_end(nums , i , k);
        }

        return count;
    }
};


/// s[i] 表示 num[0] + nums[1] + nums[2] + nums[3] + ..... + nums[i-1] 不包括当前nums[i]的前i个数字
///
/// j-1 <= nums.size()-1 , j-1 必须遍历到 nums的最后
/// j <= nums.size()
///  i <= 0
/// Q: nums[i] -> nums[j-1] 的和怎么求？ A: s[j]-s[i]  = target
///  i = j-1

class Solution_560_2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> s(nums.size()+1);
        s[0] = 0;
        for( int i = 1  ; i< nums.size()+1 ; ++i){
            s[i] = s[i-1] + nums[i-1];            /// 初始化s数组
        }

        int ans = 0;    /// 总个数
       unordered_map<int , int> mp; /// key = 连续数组元素之和  ， value = 能达到key值的个数
       for( int sj : s ){       /// 从 s[0] 开始
           /// s[j]-s[i]  = k ===> sj-k = s[i]
           //// map.contains C++ 20标准新增
           if( mp.find(sj-k ) != mp.end()) {
               ans += mp[sj-k];
           }
           mp[sj]++; ///如果没找到s[i]= sj-k的值时，仅把
       }
        return ans;
    }
};

class Solution_560_3{
public:
    class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int result = 0;
            /// O(n^3)
            for( int size = 1 ; size <= nums.size() ; ++size ){
                /// 选择起始遍历点
                for(int i = 0 ; i<nums.size() ; ++i) {
                    /// i+size-1 = 当前窗口最后一个元素的index
                    if( i+size > nums.size() ) break;
                    int cur_sum = 0;
                    for(int j = i ; j< i+size && j<nums.size() ; ++j){
                        cur_sum += nums[j];
                    }
                    if(cur_sum == k){
                        result++;
                    }
                }
            }
            return result;
        }
    };

};



#endif //OFFER_HOT_560_H

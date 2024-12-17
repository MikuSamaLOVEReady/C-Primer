//
// Created by ����� on 2024/7/14.
//

#ifndef OFFER_HOT_560_H
#define OFFER_HOT_560_H

#include <unordered_map>

class Solution_560 {
public:
    int count = 0;
    /// ÿһ��Ԫ�ض�����Ϊ��ʼԪ�� , һֱ��������β��һ��

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


/// s[i] ��ʾ num[0] + nums[1] + nums[2] + nums[3] + ..... + nums[i-1] ��������ǰnums[i]��ǰi������
///
/// j-1 <= nums.size()-1 , j-1 ��������� nums�����
/// j <= nums.size()
///  i <= 0
/// Q: nums[i] -> nums[j-1] �ĺ���ô�� A: s[j]-s[i]  = target
///  i = j-1

class Solution_560_2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> s(nums.size()+1);
        s[0] = 0;
        for( int i = 1  ; i< nums.size()+1 ; ++i){
            s[i] = s[i-1] + nums[i-1];            /// ��ʼ��s����
        }

        int ans = 0;    /// �ܸ���
       unordered_map<int , int> mp; /// key = ��������Ԫ��֮��  �� value = �ܴﵽkeyֵ�ĸ���
       for( int sj : s ){       /// �� s[0] ��ʼ
           /// s[j]-s[i]  = k ===> sj-k = s[i]
           //// map.contains C++ 20��׼����
           if( mp.find(sj-k ) != mp.end()) {
               ans += mp[sj-k];
           }
           mp[sj]++; ///���û�ҵ�s[i]= sj-k��ֵʱ������
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
                /// ѡ����ʼ������
                for(int i = 0 ; i<nums.size() ; ++i) {
                    /// i+size-1 = ��ǰ�������һ��Ԫ�ص�index
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

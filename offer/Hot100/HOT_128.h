//
// Created by ����� on 2024/4/23.
//

#ifndef OFFER_HOT_128_H
#define OFFER_HOT_128_H

// #include <unordered_map>
#include <set>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::set<int> my_set;
        for(int i = 0 ; i<nums.size() ;++i){
            my_set.insert( nums[i] );
        }

        int result = 0;
        int count = 0;
        int pre_num = *my_set.begin();
        for(auto it = my_set.begin()++ ; it != my_set.end() ; it++){
            if(  *it - pre_num > 1 ){
                result = result > count ? result : count;
                count = 0;
            }else{
                count++;
            }
            pre_num = *it;
        }
        result = result > count ? result : count;

        return result;
    }

    int methods2(std::vector<int>& nums ) {
        std::unordered_set<int> mp; /// ���򷴶���
        for(int va : nums){
            mp.insert(va);      ///Ŀ���ǿ��ٲ��ҡ�O(1)
        }

        int result;
        int cur_count = 0;
        for( auto it = mp.begin() ; it != mp.end() ; ++it){

            int va = *it;
            if( !mp.count( va-1 ) ){ /// û��it��ǰһ�������������ĳ�����еĿ�ͷ
                cur_count = 1;
                while ( mp.count(va+1)){
                    va = va+1;
                    cur_count++;
                }
                result = std::max(cur_count , result);
            } else {        /// ��ǰit��ĳ�������е�һ��
                cur_count = 0;
            }
        }
        return result;
    }


};

#endif //OFFER_HOT_128_H

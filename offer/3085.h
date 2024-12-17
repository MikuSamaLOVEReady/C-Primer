//
// Created by 罗瑞笛 on 2024/7/20.
//

#ifndef OFFER_3085_H
#define OFFER_3085_H

#include <unordered_map>
#include <string>
using namespace std;
class Solution_3085 {
public:
    // 任意两个字符个数之差都要 < k
    // if  最大个数 - 最小个数 <=  k => ok 、 最大 <= k + 最小个数
    // 关键是找最小的值
    int result = 0;
    int minimumDeletions(string word, int k) {

        unordered_map<char , int>  mp;
        for( const char& ch : word ){
            mp[ch] += 1;
        }

        int min = INT_MAX;
        for( auto it = mp.begin() ; it != mp.end() ; ++it) {
            int va = (*it).second;
            if( min > va ) min = va;
        }

        for( auto pair : mp){
            if( pair.second - min > k ){
                /// pair.second -x   = k + min
                /// pair.second-k-min = x
                result += pair.second-k-min;
            }
        }
        return result;
    }
};


#endif //OFFER_3085_H

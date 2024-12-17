//
// Created by ����� on 2024/7/20.
//

#ifndef OFFER_3085_H
#define OFFER_3085_H

#include <unordered_map>
#include <string>
using namespace std;
class Solution_3085 {
public:
    // ���������ַ�����֮�Ҫ < k
    // if  ������ - ��С���� <=  k => ok �� ��� <= k + ��С����
    // �ؼ�������С��ֵ
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

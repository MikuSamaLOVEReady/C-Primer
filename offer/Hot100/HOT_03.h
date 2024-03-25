//
// Created by ����� on 2024/2/22.
//

#ifndef OFFER_HOT_03_H
#define OFFER_HOT_03_H

#include <string>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_set<char> lookup;
        int left = 0;
        int max_len = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            /// Slide Window
            /// ������������ǰ������Ԫ�� �� ��Ԫ���ظ�
            while( lookup.find(s[i]) != lookup.end())
            {
                lookup.erase( s[left] );            /// ** ����ֱ�Ӵ�set���޳�Ԫ�� **
                left++;
            }

            max_len = max( max_len , i - left + 1);
            lookup.insert( s[i] );
        }
        return max_len;
    }
};

#endif //OFFER_HOT_03_H

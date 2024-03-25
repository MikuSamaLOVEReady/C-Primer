//
// Created by 罗瑞笛 on 2024/2/22.
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
            /// 进入条件：当前窗口内元素 与 新元素重复
            while( lookup.find(s[i]) != lookup.end())
            {
                lookup.erase( s[left] );            /// ** 可以直接从set中剔除元素 **
                left++;
            }

            max_len = max( max_len , i - left + 1);
            lookup.insert( s[i] );
        }
        return max_len;
    }
};

#endif //OFFER_HOT_03_H

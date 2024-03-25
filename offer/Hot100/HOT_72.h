//
// Created by 罗瑞笛 on 2024/3/12.
//

#ifndef OFFER_HOT_72_H
#define OFFER_HOT_72_H

class Solution_72 {
public:
    int minDistance(string word1, string word2) {
            // map<char , int> target;
            unordered_map<char , int> target;
            /// 统计目标字符串的字符组成
            for(char& ch : word2){
                target[ch] += 1;
            }

            /// 优先 删（map中不同的）、 再换、最后插入？ ？？？？？？？
    }
};

#endif //OFFER_HOT_72_H

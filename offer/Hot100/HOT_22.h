//
// Created by 罗瑞笛 on 2024/2/28.
//

#ifndef OFFER_HOT_22_H
#define OFFER_HOT_22_H

#include <string>
#include <vector>

class Solution_22 {
public:
    vector<string> res;
    vector<char>   braket{'(' , ')'};
    int max_left = 0;
    int max_right = 0;

    void recursive_build(string& cur , int n){

        ///递归出口 n==0 表示已经没有可选的 ( or )
        if(n == 0)
        {
            res.push_back(cur);
            return ;
        }

        /// 加入新的括号')'
        /// **** 关键、左括号个数   > 右括号个数 时候 continue不再继续 ***
        for(int i = 0 ; i < 2  ; ++i)
        {

            if( i==0 && max_left<=0  ) continue;
            if( i==1 && max_right<=0  ) continue;

            string  temp = cur + braket[i];
            if (i==0) max_left--;
            else {
                ///  使用完右括号后，检查可用括号还有哪些
                max_right--;
                if(max_left > max_right){
                    max_right++;    ///由于失败补充回来一个
                    continue;
                }
            }
            recursive_build( temp , n-1);

            /// 还原用过的括号
            if (i==0) max_left++;
            else max_right++;
        }

    }

    vector<string> generateParenthesis(int n) {
        max_left = n;
        max_right = n;
        string start;
        recursive_build(start , 2*n);       ///
        return res;
    }
};

#endif //OFFER_HOT_22_H

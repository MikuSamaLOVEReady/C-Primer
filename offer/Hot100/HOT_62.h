//
// Created by 罗瑞笛 on 2024/3/12.
//

#ifndef OFFER_HOT_62_H
#define OFFER_HOT_62_H

class Solution_62 {
public:

    /// \return 到达m、n 处能有多少条路
    int uniquePaths_TimeOut(int m, int n) {
        if (n == 1 || m == 1) return 1;
        /// 到达当前块的路径 = 到左边一个 + 到右边一个只和。
        return uniquePaths_TimeOut(m - 1, n) + uniquePaths_TimeOut(m, n - 1);
    }

    unsigned long long factorial(unsigned int n) {
        unsigned long long result = 1;
        for (unsigned int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    int uniquePaths_Cmn(int m, int n) {
        long long ans = 1;
        for(int x = 1 , y = n ; x < m ;++x , y++)
        {
            ans = ans * y/x;        ///如果ans 是int 会在运行时超出范围
        }
        return ans;
    }


    int uniquePaths(int m, int n) {
       return int(factorial(m+n-2) / factorial(n-1) / factorial(m-1));
    }

};
#endif //OFFER_HOT_62_H


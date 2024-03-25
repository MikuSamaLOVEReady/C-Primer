//
// Created by ����� on 2024/3/12.
//

#ifndef OFFER_HOT_62_H
#define OFFER_HOT_62_H

class Solution_62 {
public:

    /// \return ����m��n �����ж�����·
    int uniquePaths_TimeOut(int m, int n) {
        if (n == 1 || m == 1) return 1;
        /// ���ﵱǰ���·�� = �����һ�� + ���ұ�һ��ֻ�͡�
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
            ans = ans * y/x;        ///���ans ��int ��������ʱ������Χ
        }
        return ans;
    }


    int uniquePaths(int m, int n) {
       return int(factorial(m+n-2) / factorial(n-1) / factorial(m-1));
    }

};
#endif //OFFER_HOT_62_H


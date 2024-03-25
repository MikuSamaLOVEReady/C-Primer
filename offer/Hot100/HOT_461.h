//
// Created by ÂÞÈðµÑ on 2024/2/29.
//

#ifndef OFFER_HOT_461_H
#define OFFER_HOT_461_H

class Solution_461 {
public:

    int hammingDistance_Too_cost(int x, int y) {
        vector<int> vec_x;
        vector<int> vec_y;

        while( x!= 1)
        {
            int left_value = x % 2;
            x = x / 2;
            vec_x.push_back(left_value);

        }

        while ( y!= 1)
        {
            int left_value = y % 2;
            y = y / 2;
            vec_y.push_back(left_value);
        }

        int i = 1;
        int result = 0;
        while( i <=vec_x.size() || i <= vec_y.size() )
        {
            int cmp_x = -1;
            int cmp_y = -1;

            cmp_x = i > vec_x.size() ? 0 : vec_x[i-1];
            cmp_y = i > vec_y.size() ? 0 : vec_y[i-1];
            if( cmp_x != cmp_y) result++;
        }
        return result;
    }

    int  hammingDistance(int x, int y) {
        int s = x ^ y , res = 0;    /// ^ xor
        while (s) {
            res += (s & 1) == 1 ? 1 : 0;
            s = s >> 1;
        }
        return res;
    }

};

#endif //OFFER_HOT_461_H

//
// Created by ����� on 2024/3/17.
//

#ifndef OFFER_HOT_338_H
#define OFFER_HOT_338_H

class Solution_338 {
public:

    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0 ; i<= n ; ++i){
            int cur_va = i;
            int one_sum = 0;
            while( cur_va > 0){
                int and_result = cur_va & 1;        /// ÿ��ȡ 1 bit �Ĳ���
                if( and_result ) one_sum++;
                cur_va = cur_va >> 1;
            }
            res.push_back(one_sum);
        }
        return res;
    }

};


#endif //OFFER_HOT_338_H

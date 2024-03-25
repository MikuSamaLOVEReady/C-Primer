//
// Created by ����� on 2024/2/28.
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

        ///�ݹ���� n==0 ��ʾ�Ѿ�û�п�ѡ�� ( or )
        if(n == 0)
        {
            res.push_back(cur);
            return ;
        }

        /// �����µ�����')'
        /// **** �ؼ��������Ÿ���   > �����Ÿ��� ʱ�� continue���ټ��� ***
        for(int i = 0 ; i < 2  ; ++i)
        {

            if( i==0 && max_left<=0  ) continue;
            if( i==1 && max_right<=0  ) continue;

            string  temp = cur + braket[i];
            if (i==0) max_left--;
            else {
                ///  ʹ���������ź󣬼��������Ż�����Щ
                max_right--;
                if(max_left > max_right){
                    max_right++;    ///����ʧ�ܲ������һ��
                    continue;
                }
            }
            recursive_build( temp , n-1);

            /// ��ԭ�ù�������
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

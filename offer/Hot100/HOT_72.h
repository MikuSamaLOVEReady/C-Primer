//
// Created by ����� on 2024/3/12.
//

#ifndef OFFER_HOT_72_H
#define OFFER_HOT_72_H

class Solution_72 {
public:
    int minDistance(string word1, string word2) {
            // map<char , int> target;
            unordered_map<char , int> target;
            /// ͳ��Ŀ���ַ������ַ����
            for(char& ch : word2){
                target[ch] += 1;
            }

            /// ���� ɾ��map�в�ͬ�ģ��� �ٻ��������룿 ��������������
    }
};

#endif //OFFER_HOT_72_H

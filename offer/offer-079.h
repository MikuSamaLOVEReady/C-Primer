//
// Created by ����� on 2023/5/5.
//

#ifndef OFFER_OFFER_079_H
#define OFFER_OFFER_079_H
#include <vector>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> universal;      //��Ž��
    vector<vector<int>> universal_copy; //�������Ԫ��ʱ����յĸ���
    //������ѡȡԪ��
    for(vector<int>::iterator it = nums.begin() ; it!=nums.end() ; ++it){
        //ÿ�������Ԫ��ǰ����һ�����������ο�
        universal_copy = universal;
        //���Ѿ�����ĸ�����ʼ���
        for(auto it_uni = universal_copy.begin() ; it_uni != universal_copy.end() ; ++it_uni){
            (*it_uni).emplace_back(*it);// Ϊ֮ǰ�Ľ���������Ԫ����ϵĽ��
            universal.emplace_back(*it_uni);
        }
        //�����Ԫ�أ�ע����Ҫ��vector��ʽ
        vector<int> single = {*it};
        universal.emplace_back(single);
    }
    vector<int> empty = {};
    universal.emplace_back(empty);
    return universal;
}


#endif //OFFER_OFFER_079_H

//
// Created by ����� on 2023/5/2.
#ifndef OFFER_OFFER_87_H
#define OFFER_OFFER_87_H
#include <vector>

using namespace std;

///
/// \param first  ��ǰ��Ҫ��д���ݵ�λ��
/// \param output
/// \param len
/// \param res
void backtrack(int first , vector<int>& output , int len, vector<vector<int>>& res){
    if(first == len){
        res.emplace_back(output);
        return;
    }
    //iָ��ѡ������
    for(int i = first ; i<len ; ++i){
        //ѡ��first�Ժ������ֵ
        swap(output[first] , output[i]);
        backtrack(first+1,output,len,res);
        //���ݷ���ʱ����ʾ�ҵ���һ���⣬��ʱ��ԭ��һ������һ��ѡi++��λ���ϵ�ֵ
        swap(output[first],output[i]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(0,nums,nums.size(),result);
    return result;
}

#endif //OFFER_OFFER_87_H

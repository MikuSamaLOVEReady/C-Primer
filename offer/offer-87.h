//
// Created by 罗瑞笛 on 2023/5/2.
#ifndef OFFER_OFFER_87_H
#define OFFER_OFFER_87_H
#include <vector>

using namespace std;

///
/// \param first  当前将要填写数据的位置
/// \param output
/// \param len
/// \param res
void backtrack(int first , vector<int>& output , int len, vector<vector<int>>& res){
    if(first == len){
        res.emplace_back(output);
        return;
    }
    //i指向备选的数字
    for(int i = first ; i<len ; ++i){
        //选入first以后的所有值
        swap(output[first] , output[i]);
        backtrack(first+1,output,len,res);
        //回溯返回时，表示找到了一个解，此时还原上一步，这一次选i++的位置上的值
        swap(output[first],output[i]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(0,nums,nums.size(),result);
    return result;
}

#endif //OFFER_OFFER_87_H

//
// Created by di on 2023/3/15.
//

#ifndef CHAPTER2_FILE_1_H
#define CHAPTER2_FILE_1_H
#include <iostream>
#include <vector>
extern const int val;

using namespace std;

int row_max , col_max = 0;
bool result = false;
/// DFS 思想本质上是要，
/// \param board
/// \param flags
/// \param cur_row 当前需要判断的位置
/// \param cur_col
/// \param word
/// \param word_index
/// \return
bool searchNext(vector<vector<char>>& board , vector<vector<bool>>& flags,
                int cur_row , int cur_col , string word , int word_index)
{

}


bool exist(vector<vector<char>>& board, string word) {
    if(!board.empty())
    {
        row_max = board.size();
        col_max = board[0].size();
    }
    else { return false;}
    vector<vector<bool>> flags(row_max, vector<bool>(col_max));
    return  result;
}



#endif //CHAPTER2_FILE_1_H

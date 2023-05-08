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
///
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
    if(word_index == word.size())
    {
        result = true;
        return true;
    }

    int left  = cur_col - 1;
    int right = cur_col + 1;
    int up    = cur_row - 1;
    int down  = cur_row + 1;

    //检查四个方位，范围之内，并且还没被访问
    if( left >= 0 && flags[cur_row][left] == false)
    {
        //检查是否符合要求，符合就沿着方向继续
        if(board[cur_row][left] == word[word_index])
        {
            flags[cur_row][cur_col] = true;
            searchNext(board , flags , cur_row ,left , word , ++word_index );
        }
    }
    if(right<col_max && flags[cur_row][right] == false )
    {
        if(board[cur_row][right] == word[word_index])
        {
            flags[cur_row][cur_col] = true;
            searchNext(board , flags , cur_row ,right , word , ++word_index );
        }
    }
    if( up>=0 && flags[up][cur_col] == false )
    {
        if(board[up][cur_col] == word[word_index])
        {
            flags[cur_row][cur_col] = true;
            searchNext(board , flags , up ,cur_col , word , ++word_index );
        }
    }
    if( down < row_max && flags[down][cur_col] == false )
    {
        if(board[down][cur_col] == word[word_index])
        {
            flags[cur_row][cur_col] = true;
            searchNext(board , flags , down ,cur_col , word , ++word_index );
        }
    }
    //如果当前全部方向都无效了，需要本grid设置为true
    flags[cur_row][cur_col] = false;
    return false;
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

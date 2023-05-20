//
// Created by 罗瑞笛 on 2023/5/6.
//

#ifndef OFFER_OFFER_012_H
#define OFFER_OFFER_012_H
#include <vector>
#include <string>
#include <tuple>

using namespace std;
int word_index  = 0;
int m,n = 0;

//递归搜索
/// DFS
/// \param board
/// \param visited
/// \param row
/// \param col
/// \param word
/// \param index
/// \return 返回最终结果
bool search_word(vector<vector<char>>& board, vector<vector<bool>>& visited
                 ,int row , int col , string& word, int index){
    //递归出口
    if(board[row][col] != word[index])
        return false;
    else if( index == word.size()-1)
        return true; //最终结果
     //如果当前letter匹配成功
    visited[row][col]  = true;
    vector<pair<int,int>> directions {{0,1}, {0,-1},{1,0},{-1,0}};
    bool result = false;
    //遍历四个方向
    for( const auto& dir: directions){
            int new_row = dir.first + row;
            int new_col = dir.second + col;
            if(new_row >= 0 && new_row < board.size() && new_col>=0 && new_col < board[0].size()
            && !visited[new_row][new_col]  )
            {
                bool flag = search_word(board,visited,new_row,new_col,word,++index);
                if(flag){
                    result = true;
                    break;
                }
            }
    }
    // 如果所有方向判定完成，暂时没有找到，此时退后访问，当前grid仍然可以成为其他可能组合的候选
    // 如果成功则这里设置一下也没影响
    visited[row][col] = false;
    return result;

}

bool exist(vector<vector<char>>& board, string word) {
    bool result = false;
    vector<vector<bool>> visited(board.size() , vector<bool>(board[0].size()));

    for(int i = 0 ; i<board.size() ; ++i){
        for(int j = 0 ; j<board[0].size() ; ++j){
            result = search_word(board,visited,i,j,word,0);
            //一找到就可以直接返回
            if(result) return true;
        }
    }
    return false;

}


#endif //OFFER_OFFER_012_H

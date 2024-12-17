//
// Created by 罗瑞笛 on 2024/7/31.
//

#ifndef OFFER_LCR_105_H
#define OFFER_LCR_105_H
#include <vector>
using namespace std;
class Solution_LCR_105 {
public:

    bool in_area(vector<vector<int>>& grid , int s_row , int s_col) {
        return s_row>=0 && s_row<grid.size() && s_col>=0 && s_col<grid[0].size();
    }

    ///  sum做成class 成员变量会更好
    void dfs(vector<vector<int>>& grid , int s_row , int s_col , int& sum){

        if( !in_area(grid , s_row , s_col) ) {
             return;
        }

        if( grid[s_row][s_col] == -1 ) return; ///防止走回头路
        grid[s_row][s_col] = -1;
        sum++;

        dfs(grid , s_row+1 , s_col, sum);
        dfs(grid , s_row-1 , s_col , sum);
        dfs(grid , s_row , s_col+1, sum);
        dfs(grid , s_row , s_col-1, sum);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        if(grid.empty()) return 0;
        int result = 0;
        for(int i = 0 ; i<grid.size() ; ++i){
            for(int j = 0 ; j<grid[0].size() ;++j){
                if( grid[i][j] == 1 ){
                    int cur_va = 0;
                    dfs(grid,i,j,cur_va);
                    result = result > cur_va ? result : cur_va;
                }
            }
        }
        return result;
    }
};

#endif //OFFER_LCR_105_H

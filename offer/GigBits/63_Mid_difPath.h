//
// Created by 罗瑞笛 on 2024/4/4.
//

#ifndef OFFER_63_MID_DIFPATH_H
#define OFFER_63_MID_DIFPATH_H

class Solution_difPath {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid.empty()) return -1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1 ) return 0;        /// 终点被遮挡｜｜起点被遮挡
        ///存储到 dp[i][j] 位置上时所有可能的路径
        vector<vector<int>> dp(obstacleGrid.size() , vector<int>(obstacleGrid[0].size() , 0));

        /// 初始化 第一行、第一列（但是存在障碍物）
        dp[0][0] = 1;
        for(int i = 0 ; i<n ;++i){
            /// vector 默认 = 0
            if(obstacleGrid[0][i] != 1){
                dp[0][i] = 1;
            }
            else{
                break;
            }
        }

        for(int i = 0 ; i<m ;++i){
            if(obstacleGrid[i][0] != 1){
                dp[i][0] = 1;
            } else{
                break;
            }
        }

        for( int row = 1 ; row < m ; ++row){
            for(int col = 1 ; col < n ; ++col){
                ///  从上、左来的路线有哪些
                int up = 0;
                int left = 0;
                if( obstacleGrid[row-1][col] != 1 ){
                    up = dp[row-1][col];
                }
                if( obstacleGrid[row][col-1] != 1 ){
                    left = dp[row][col-1];
                }
                dp[row][col] = up+left;
            }
        }

        return dp[m-1][n-1];
    }
};


#endif //OFFER_63_MID_DIFPATH_H

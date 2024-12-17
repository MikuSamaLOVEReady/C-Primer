//
// Created by ����� on 2024/4/4.
//

#ifndef OFFER_63_MID_DIFPATH_H
#define OFFER_63_MID_DIFPATH_H

class Solution_difPath {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid.empty()) return -1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1 ) return 0;        /// �յ㱻�ڵ�������㱻�ڵ�
        ///�洢�� dp[i][j] λ����ʱ���п��ܵ�·��
        vector<vector<int>> dp(obstacleGrid.size() , vector<int>(obstacleGrid[0].size() , 0));

        /// ��ʼ�� ��һ�С���һ�У����Ǵ����ϰ��
        dp[0][0] = 1;
        for(int i = 0 ; i<n ;++i){
            /// vector Ĭ�� = 0
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
                ///  ���ϡ�������·������Щ
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

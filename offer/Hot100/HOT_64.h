//
// Created by 罗瑞笛 on 2024/3/12.
//

#ifndef OFFER_HOT_64_H
#define OFFER_HOT_64_H

class Solution_64 {
public:
    /// \param grid
    /// \param m    均是index
    /// \param n    均是index
    /// \return  从 【 m、n 】 位置离开后 当前的最小cose是多少。
    int cur_min_path(vector<vector<int>>& grid , int m , int n)
    {
        int res = 0;
        /// 退出条件
        if(n == 0){
            for(int i = 0 ; i<= m ;++i) {
                res += grid[i][0];
            }
            return res;
        }
        else if( m == 0){
            for(int i = 0 ; i <= n ;++i) {
                res += grid[0][i];
            }
            return res;
        }

        int up    = cur_min_path(grid, m-1 , n) ;
        int right = cur_min_path(grid , m ,n-1) ;

        if ( up > right )
            res = right + grid[m][n];
        else
            res = up + grid[m][n];

        return res;
    }


    ///
    /// \param grid
    /// \param m
    /// \param n
    /// \return void
    void cur_min_dp_timeOut(vector<vector<int>>& grid , int m , int n , vector<vector<int>>& dp)
    {
        int res;
        if(n == 0){ ///  time cost
            for(int i = 0 ; i<= m ;++i) {
                res += grid[i][0];
            }
            dp[m][0] = res;
        }
        else if( m == 0){       /// time cost
            for(int i = 0 ; i <= n ;++i) {
                res += grid[0][i];
            }
            dp[0][n] = res;
        }

        else { /// m!=0 n!=0 已经在递归中
            cur_min_dp_timeOut(grid , m-1 , n , dp);
            cur_min_dp_timeOut(grid , m , n-1 , dp);
            int pre_min = dp[m-1][n] > dp[m][n-1] ? dp[m][n-1] : dp[m-1][n];
            dp[m][n] = pre_min + grid[m][n];
        }
    }


    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size() , n = grid[0].size();

        /// return cur_min_path(grid , m-1 , n-1);
        vector<vector<int>> dp( grid.size() , vector<int>(grid[0].size()) );
        dp[0][0] = grid[0][0]; ///初始条件
        //cur_min_dp(grid , m-1 , n-1 , dp);
        /// for rows
        for(int i= 1 ; i<m ; ++i){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j= 1 ; j<n ; ++j){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i = 1 ; i<m ;++i){
            for( int j = 1 ; j<n ;++j){
                dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }



};

#endif //OFFER_HOT_64_H

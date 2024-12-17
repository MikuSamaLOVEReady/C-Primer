//
// Created by 罗瑞笛 on 2024/5/11.
//

#ifndef OFFER_HOT_494_H
#define OFFER_HOT_494_H

#include <vector>
#include <numeric>


//// DFS搜索不行、得试试DP
class Solution_494 {
public:

    std::vector<char> symbles; /// 用Stack 可能会好一点
    int final_target;
    int result = 0;

    void Dfs( std::vector<int>& nums , int index ) {

        ///递归出口
        if(index == nums.size()) {
            int cur_res = 0;
            for(int i = 0 ; i<nums.size() ; ++i ) {
                   if(symbles[i] == '+')
                       cur_res += nums[i];
                   else
                       cur_res -= nums[i];
            }
            if(final_target == cur_res) result++;
            return ;
        }

        ///剪支---> 如果已经 > target了 则后续只能选 -
        symbles[index] = '+';
        Dfs( nums , index+1 );
        symbles[index] = '-';
        Dfs( nums , index+1 );

        return;
    }

    int findTargetSumWays(std::vector<int>& nums, int target) {

        final_target = target;
        symbles.resize(nums.size());

        Dfs(nums,0);
        return result;
    }
};

class Solution_494_2 {
public:

    std::vector<char> symbles; /// 用Stack 可能会好一点
    int final_target;
    int result = 0;


    /// dfs( i , c ) 容量 = c 时候、 前i个物品中的最大价值

    /// 从nums的末尾开始找？遍历
    /// trget = c  , index = i
    /// return 容量为target 时有多少种组合方法
    int Dfs( std::vector<int>& nums , int target , int index ) {

       /// 【从后向前、递归 ---> 转化成递推】
        if( index < 0)
        {
            if( target == 0)
                return 1;
            else
                return 0;
        }

        /// 【从后向前、递归 ---> 转化成递推】
        if ( target < nums[index] )
            return Dfs(nums , target , index-1);

        return Dfs(nums, target-nums[index] , index-1) + Dfs(nums , target , index-1);
    }

    int findTargetSumWays(std::vector<int>& nums, int target) {

        int s = std::accumulate(nums.begin() , nums.end() , 0);
        target += s;
        if( target< 0 || target % 2 == 1) return 0;

        int p = target/2;
        return Dfs(nums , p , 0);
    }
};

class Solution_494_3 {
public:
    std::vector<char> symbles;
    int final_target;
    int result = 0;

    /// 从nums的末尾开始找？遍历 【从后向前、递归 ---> 转化成递推 从前往后】
    int cal_cu( std::vector<int>& nums , int target ) {

        /// std::vector<int> dp ( nums.size() , target );
        /// dp[i][c]  = dp[i-1][c] + dp[i-1][c-nums[i]] --> /// dp[i+1][c]  = dp[i][c] + dp[i][c-nums[i]]
        /// 需要手动初始 dp[0][capacity];
        std::vector<std::vector<int>> dp ( nums.size()+1 , std::vector<int>(target+1 ) );
        /// dp[i][c] 表示选到第i个数 ，能构成c的结果有几个。
        dp[0][0] = 1;
        /// dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0; .....

        for( int i = 0 ; i<nums.size() ; ++i ){
            for(int c = 0 ; c <= target  ; ++c ){
                if( c < nums[i] ) dp[i+1][c] = dp[i][c];
                else dp[i+1][c]  = dp[i][c] + dp[i][c-nums[i]] ;    ///当前【i】不可重复
            }
        }

        return dp[nums.size()][target];
    }


    int findTargetSumWays(std::vector<int>& nums, int target) {
        int s = std::accumulate(nums.begin() , nums.end() , 0);
        target += s;
        if( target< 0 || target % 2 == 1) return 0;

        int p = target/2;
       return  cal_cu(nums, p);
    }

};

class Solution_494_4 {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int s = std::accumulate(nums.begin() , nums.end() , 0);
        target += s;
        if( target< 0 || target % 2 == 1) return 0;

        int p = target/2;
        std::vector<int> dp(p + 1 , 0);  /// dp[i] 填满容量为i的背包一共有多少种方法、
        /// dp[i] = dp[i] + dp[i-num] ....
        dp[0] = 1;


    }



};

#endif //OFFER_HOT_494_H

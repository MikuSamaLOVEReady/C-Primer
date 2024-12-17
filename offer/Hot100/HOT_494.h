//
// Created by ����� on 2024/5/11.
//

#ifndef OFFER_HOT_494_H
#define OFFER_HOT_494_H

#include <vector>
#include <numeric>


//// DFS�������С�������DP
class Solution_494 {
public:

    std::vector<char> symbles; /// ��Stack ���ܻ��һ��
    int final_target;
    int result = 0;

    void Dfs( std::vector<int>& nums , int index ) {

        ///�ݹ����
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

        ///��֧---> ����Ѿ� > target�� �����ֻ��ѡ -
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

    std::vector<char> symbles; /// ��Stack ���ܻ��һ��
    int final_target;
    int result = 0;


    /// dfs( i , c ) ���� = c ʱ�� ǰi����Ʒ�е�����ֵ

    /// ��nums��ĩβ��ʼ�ң�����
    /// trget = c  , index = i
    /// return ����Ϊtarget ʱ�ж�������Ϸ���
    int Dfs( std::vector<int>& nums , int target , int index ) {

       /// ���Ӻ���ǰ���ݹ� ---> ת���ɵ��ơ�
        if( index < 0)
        {
            if( target == 0)
                return 1;
            else
                return 0;
        }

        /// ���Ӻ���ǰ���ݹ� ---> ת���ɵ��ơ�
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

    /// ��nums��ĩβ��ʼ�ң����� ���Ӻ���ǰ���ݹ� ---> ת���ɵ��� ��ǰ����
    int cal_cu( std::vector<int>& nums , int target ) {

        /// std::vector<int> dp ( nums.size() , target );
        /// dp[i][c]  = dp[i-1][c] + dp[i-1][c-nums[i]] --> /// dp[i+1][c]  = dp[i][c] + dp[i][c-nums[i]]
        /// ��Ҫ�ֶ���ʼ dp[0][capacity];
        std::vector<std::vector<int>> dp ( nums.size()+1 , std::vector<int>(target+1 ) );
        /// dp[i][c] ��ʾѡ����i���� ���ܹ���c�Ľ���м�����
        dp[0][0] = 1;
        /// dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0; .....

        for( int i = 0 ; i<nums.size() ; ++i ){
            for(int c = 0 ; c <= target  ; ++c ){
                if( c < nums[i] ) dp[i+1][c] = dp[i][c];
                else dp[i+1][c]  = dp[i][c] + dp[i][c-nums[i]] ;    ///��ǰ��i�������ظ�
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
        std::vector<int> dp(p + 1 , 0);  /// dp[i] ��������Ϊi�ı���һ���ж����ַ�����
        /// dp[i] = dp[i] + dp[i-num] ....
        dp[0] = 1;


    }



};

#endif //OFFER_HOT_494_H

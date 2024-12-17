//
// Created by ����� on 2024/5/17.
//

#ifndef OFFER_HOT_377_H
#define OFFER_HOT_377_H

class Solution_377 {
public:
    int combinationSum4_wrong(vector<int>& nums, int target) {
        ///     dp[i][j] ǰi����ѡ�����ܹ��� j������м����� ����ͬ˳�����ô�棿��
        ///
        vector<vector<int>> dp( nums.size()+1 , vector<int>(target+1) );
        dp[0][0] = 1;

        for( int i = 0 ; i <= nums.size() ; ++i ) {

            for(int c = 0 ; c<=target ; ++c) {
                if( c < nums[i] ) dp[i+1][c] = dp[i][c];
                else dp[i+1][c] = dp[i][c] + dp[i+1][c-nums[i]]; ///��ǰi+1�ǿ����ظ�ѡ�ģ���˳����μ��룿
            }
        }
    }

    int combinationSum4(vector<int>& nums, int target) {

        vector<unsigned long long> f(target+1);   /// f[x] ��ʾ
        f[0] = 1;   ///
        for(int c = 1 ; c<=target ; ++c) {
            for(int i = 0 ; i<nums.size() ; ++i) {
                if( nums[i] <= c )
                {
                    f[c] += f[c-nums[i]];
                }
            }
        }

        return f[target];
    }


};

/// ���ˣ�woc
class Solution_377_2{
public:

    int combinationSum4(vector<int>& nums, int target) {

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int j = 0; j <= target; j++) { // ��������j����
            for (int i = 0; i < nums.size(); i++) { // ������Ʒ
                if (j - nums[i] >= 0 &&  dp[j] < INT_MAX - dp[j - nums[i]]) dp[j] += dp[j - nums[i]];
            }
        }



        // cout << endl;
        // for (int c: dp) cout << c << " ";

        return dp[target];

    }

};


#endif //OFFER_HOT_377_H

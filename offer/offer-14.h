//
// Created by 罗瑞笛 on 2023/5/10.
//

#ifndef OFFER_OFFER_14_H
#define OFFER_OFFER_14_H

#include <cmath>

int cuttingRope(int n) {
    int max_m = n-1;
    int* k  = new int[max_m];
    int result_max = 0;

    //分成几段
    for(int i =  2 ; i<=n ; i++){
        //平均长度
        int avg  = n/i;
        //余数，表示(i+1)总数中，有多少是需要+1的
        int left_count = n - avg*i;
        //
        int cur = -1;
        if(left_count == 0 ){
            cur = pow(avg, i-left_count);
        }
        else{
            cur = pow(avg, i-left_count) * pow((avg+1),left_count);
        }
        if(cur > result_max)
            result_max = cur;
    }
    return result_max;
}


int cuttingRope_DP(int n) {

    //dp[i]记录长度为i的绳子能得到的最大长度
    int* dp = new int[n+1];
    if ( n>=2 ){
        dp[2] = 1;
        dp[0] = dp[1] = 1;
    }

    //i表示长度为i的绳子,从小到大循环求解
    for(int i = 3 ; i<=n ; ++i){
        for(int j = 2 ; j <= i ; ++j ){
            dp[i] = max(dp[i], max(j*dp[i-j] , j*(i-j)));
        }
    }
    return dp[n];


}


#endif //OFFER_OFFER_14_H

//
// Created by ����� on 2023/5/10.
//

#ifndef OFFER_OFFER_14_H
#define OFFER_OFFER_14_H

#include <cmath>

int cuttingRope(int n) {
    int max_m = n-1;
    int* k  = new int[max_m];
    int result_max = 0;

    //�ֳɼ���
    for(int i =  2 ; i<=n ; i++){
        //ƽ������
        int avg  = n/i;
        //��������ʾ(i+1)�����У��ж�������Ҫ+1��
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

    //dp[i]��¼����Ϊi�������ܵõ�����󳤶�
    int* dp = new int[n+1];
    if ( n>=2 ){
        dp[2] = 1;
        dp[0] = dp[1] = 1;
    }

    //i��ʾ����Ϊi������,��С����ѭ�����
    for(int i = 3 ; i<=n ; ++i){
        for(int j = 2 ; j <= i ; ++j ){
            dp[i] = max(dp[i], max(j*dp[i-j] , j*(i-j)));
        }
    }
    return dp[n];


}


#endif //OFFER_OFFER_14_H

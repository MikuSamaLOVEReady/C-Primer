//
// Created by 罗瑞笛 on 2023/6/9.
//

#ifndef OFFER_70_H
#define OFFER_70_H


//可以动态规划-> 解决超时
//滑动数组
int climbStairs(int n) {

    if(n==1)return 1;
    else if(n==2) return 2;
    int p = 1 , q = 1 , r = 2; //需要是解3之前的状态
    // p->f(x-1) q->f(x-2) r = f(x)
    for(int i = 1 ; i<= n-2 ; ++i){
        p = q;
        q = r;
        r = p+q;
    }
    return r;

}


#endif //OFFER_70_H

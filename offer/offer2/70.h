//
// Created by ����� on 2023/6/9.
//

#ifndef OFFER_70_H
#define OFFER_70_H


//���Զ�̬�滮-> �����ʱ
//��������
int climbStairs(int n) {

    if(n==1)return 1;
    else if(n==2) return 2;
    int p = 1 , q = 1 , r = 2; //��Ҫ�ǽ�3֮ǰ��״̬
    // p->f(x-1) q->f(x-2) r = f(x)
    for(int i = 1 ; i<= n-2 ; ++i){
        p = q;
        q = r;
        r = p+q;
    }
    return r;

}


#endif //OFFER_70_H

//
// Created by di on 2023/5/19.
//

#ifndef OFFER_OFFER_62_H
#define OFFER_OFFER_62_H
#include <vector>

using namespace std;
//用一个vector?
int lastRemaining(int n, int m) {
    int initm = m;
    vector<bool> hasvisited(n);
    int count_true = 0; //每次取出一个元素，count_true++
    int cur_index = -1;  //表示本次应该从vector的哪个部分开始，同时他也记录了应当删除的数字
    while(count_true != n-1){
        while(m>0){
            //没有被访问过的
            if(!hasvisited[cur_index]){
                m--;
            }
            //如果被访问过了则直接++cur_index
            cur_index++;
            //如果超界，则重新置回0
            if(cur_index >= hasvisited.size() ){
                cur_index = 0;
            }
        }
        hasvisited[cur_index] = true;
        count_true++;
        m = initm;
        m--;
    }
    return cur_index;

}


#endif //OFFER_OFFER_62_H

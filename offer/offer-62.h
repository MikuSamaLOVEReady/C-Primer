//
// Created by di on 2023/5/19.
//

#ifndef OFFER_OFFER_62_H
#define OFFER_OFFER_62_H
#include <vector>

using namespace std;
//��һ��vector?
int lastRemaining(int n, int m) {
    int initm = m;
    vector<bool> hasvisited(n);
    int count_true = 0; //ÿ��ȡ��һ��Ԫ�أ�count_true++
    int cur_index = -1;  //��ʾ����Ӧ�ô�vector���ĸ����ֿ�ʼ��ͬʱ��Ҳ��¼��Ӧ��ɾ��������
    while(count_true != n-1){
        while(m>0){
            //û�б����ʹ���
            if(!hasvisited[cur_index]){
                m--;
            }
            //��������ʹ�����ֱ��++cur_index
            cur_index++;
            //������磬�������û�0
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

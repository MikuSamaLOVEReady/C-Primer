//
// Created by ����� on 2024/5/18.
//

#ifndef OFFER_HOT_464_H
#define OFFER_HOT_464_H

class Solution_464 {
public:

    int visited[ 1<<21 ];   ///  ���� state ��״̬ -> ��ȡsum��ֵ�� �����indexΪ 20��Ԫ�ص�ѡ��״̬
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        int sum;
        for( int i = 1 ; i<= maxChoosableInteger ; ++i ){
            sum += i;
        }
        if(sum < desiredTotal) return false;

        return dfs(0 , 0 , maxChoosableInteger , desiredTotal);
    }


    /// ��state��ʣ��Ԫ���С��� ��ǰѡ����ܷ��ʤ��
    bool dfs( int state , int sum , int maxChoosableInteger, int desiredTotal ) {

        if( visited[state] == 1 ) return true;
        if( visited[state] == 2 ) return false;
        ///
        for( int x = 1 ; x <= maxChoosableInteger ; ++x ){

            if( (1<<x) & state ) continue;  /// ����Ѿ�ѡ���x��������
            if( sum+x >= desiredTotal ) {                 /// ֱ�ӻ�ʤ
                visited[state]  = 1;
                return true;
            }
            /// �����dfs��ʾ���ֵĲ�������������䣬�����Ǳ�ʤ
            if (  !dfs( (1<<x) | state , sum+x , maxChoosableInteger , desiredTotal )  )
            {
                visited[state]  = 1;
                return true;
            }
        }

        visited[state] = 2;
        return false;
    }



};


#endif //OFFER_HOT_464_H

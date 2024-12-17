//
// Created by 罗瑞笛 on 2024/5/18.
//

#ifndef OFFER_HOT_464_H
#define OFFER_HOT_464_H

class Solution_464 {
public:

    int visited[ 1<<21 ];   ///  根据 state 的状态 -> 获取sum的值。 数组的index为 20个元素的选择状态
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        int sum;
        for( int i = 1 ; i<= maxChoosableInteger ; ++i ){
            sum += i;
        }
        if(sum < desiredTotal) return false;

        return dfs(0 , 0 , maxChoosableInteger , desiredTotal);
    }


    /// 在state【剩余元素中】， 当前选择后能否获胜。
    bool dfs( int state , int sum , int maxChoosableInteger, int desiredTotal ) {

        if( visited[state] == 1 ) return true;
        if( visited[state] == 2 ) return false;
        ///
        for( int x = 1 ; x <= maxChoosableInteger ; ++x ){

            if( (1<<x) & state ) continue;  /// 如果已经选择过x，则跳过
            if( sum+x >= desiredTotal ) {                 /// 直接获胜
                visited[state]  = 1;
                return true;
            }
            /// 这里的dfs表示对手的操作、如果他必输，则我们必胜
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

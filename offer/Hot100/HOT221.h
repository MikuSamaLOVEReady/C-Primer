//
// Created by 罗瑞笛 on 2024/7/8.
//

#ifndef OFFER_HOT221_H
#define OFFER_HOT221_H

#include <vector>
using namespace std;

class Solution_221 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int max_col = matrix[0].size();
        int max_row = matrix.size();
        int max_result = 0;

         for( int i = 0 ; i < matrix.size() ; ++i) {
            for( int j = 0 ;  j < matrix[0].size() ; ++j) {
                /// 开启查找
                if( matrix[i][j] == '1'){
                    ///  当前node为左上角位置 如果row、col越界 或者碰到非1状态 -> break
                    int len = 1; /// len 表示当前size
                    int stride = 1; /// 下一次试探的步长
                   while( 1 ){

                       /// 边界检查
                        if( i+stride >= max_row || j+stride >= max_col ){
                            break;
                        }

                        /// 横着一行 + 竖着一列要全部查找
                        bool add_size = true;
                        for( int count = 0; count <= stride  ; count++){
                            if( matrix[i+stride][j+count] != '1' || matrix[i+count][j+stride] != '1' ){
                                add_size = false;
                                break;
                            }
                        }

                        if(add_size){
                            ++len;
                            ++stride;
                        }
                        else break;
                    }
                    max_result = max(max_result , len);
                }
            }
         }

         return max_result*max_result;
    }
};

#endif //OFFER_HOT221_H

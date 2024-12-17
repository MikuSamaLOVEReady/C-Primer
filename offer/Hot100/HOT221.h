//
// Created by ����� on 2024/7/8.
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
                /// ��������
                if( matrix[i][j] == '1'){
                    ///  ��ǰnodeΪ���Ͻ�λ�� ���row��colԽ�� ����������1״̬ -> break
                    int len = 1; /// len ��ʾ��ǰsize
                    int stride = 1; /// ��һ����̽�Ĳ���
                   while( 1 ){

                       /// �߽���
                        if( i+stride >= max_row || j+stride >= max_col ){
                            break;
                        }

                        /// ����һ�� + ����һ��Ҫȫ������
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

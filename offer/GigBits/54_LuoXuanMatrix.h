//
// Created by ����� on 2024/4/3.
//

#ifndef OFFER_54_LUOXUANMATRIX_H
#define OFFER_54_LUOXUANMATRIX_H

class Solution_Gigbits54 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        /// �߽�index
        int right = matrix[0].size() - 1;
        int left  = 0;
        int bottom = matrix.size() -1;
        int top = 0;
        vector<int> res;

        while( 1 ){

            if(left  > right || top> bottom ) break;
            /// ����
            for( int i = left ; i <= right  ; i++ ){
                res.push_back(matrix[top][i]);
            }
            top++;
            if( top> bottom ) break;


            /// ����
            for( int j = top ; j<= bottom  ; j++ ){
                res.push_back(matrix[j][right]);
            }
            right--;
            if(left  > right  ) break;


            ///����
            for( int k = right  ; k>=left ; k--  ){
                res.push_back(matrix[bottom][k]);
            }
            bottom--;
            if(top> bottom ) break;


            /// ����
            for (int l = bottom ; l>= top  ; l--){
                res.push_back(matrix[l][left]);
            }
            left++;
            if(left  > right  ) break;

        }
        return res;
    }
};

#endif //OFFER_54_LUOXUANMATRIX_H

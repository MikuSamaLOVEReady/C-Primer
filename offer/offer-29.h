//
// Created by di on 2023/5/16.
//

#ifndef OFFER_OFFER_29_H
#define OFFER_OFFER_29_H

#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {

    vector<int> result;
    int row = matrix.size();
    int col = matrix[0].size();
    int t =0 , l = 0; //
    int r = col-1; // t,l,r,b 表示下次的边界
    int b = row-1;
    int* res = new int[row * col];
    int x = 0;


    while(true){
        for( int  i = l ; i<=r ; ++i){
            res[x++] = matrix[t][i];
            //result.push_back(matrix[t][i]);
        }
        if(++t>b) break;
        for( int  i = t ; i <= b  ; ++i){
            res[x++] = matrix[i][r];
           // result.push_back(matrix[i][r]);
        }
        if(--r<l) break;
        for( int  i = r ;  i >= l; --i){
            res[x++] = matrix[b][i];
           // result.push_back(matrix[b][i]);
        }
        if(--b<t) break;
        for( int  i= b ; i<= t; ++i){
            res[x++] = matrix[i][l];
           // result.push_back(matrix[i][r]);
        }
        if(++l>r) break;
    }
    return result;

}

#endif //OFFER_OFFER_29_H

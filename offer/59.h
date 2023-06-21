//
// Created by ÂÞÈðµÑ on 2023/6/11.
//

#ifndef OFFER_59_H
#define OFFER_59_H
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    int count = 1;
    int top = 0 , left = 0 , bottom = n-1, right = n-1;
    vector<vector<int>> result(n, vector<int>(n));

    while( (left<=right) && (top<=bottom) ){
        //->
        for(int i = left; i<=right ; ++i){
            result[top][i]= count;
            count++;
        }
        top++;
        for(int i = top  ; i<= bottom ; ++i){
            result[i][right] = count;
            count++;
        }
        right--;
        for(int i = right ; i>=left ; --i){
            result[bottom][i] = count;
            count++;
        }
        bottom--;
        for(int i= bottom ; i >= top ; --i){
            result[i][left] = count;
            count++;
        }
        left++;
    }
    return result;
}

#endif //OFFER_59_H

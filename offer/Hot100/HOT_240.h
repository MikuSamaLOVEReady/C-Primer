//
// Created by ����� on 2024/6/29.
//

#ifndef OFFER_HOT_240_H
#define OFFER_HOT_240_H

#include <vector>
using namespace std;

///
/// \param row
/// \param start
/// \param end
bool binary_search_row( vector<int>&row , int start , int end  , int target){


    while( start != end ) {

        /// ��¼ start ����� end ֮�����1 �����Ҳ����������е�����һ��ʱ
        if ( end-start == 1 )
        {

        }


        int mid = start + (end-start)/2;

        if( row[mid] == target) return true;

        if( row[mid] < target ) {
            start = mid;
        }
        else {
            end = mid;
        }
    }

    /// start �� end���� �����ж�һ��
    if( row[start] == target) return true;
    else return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int x = 0 , y = 0;
    if(matrix.size()==0) return false;
    int max_row = matrix.size()-1 , max_col = matrix[0].size()-1;

    // ���ҵ�һ�� > target��
    int i = 0;
    int n = matrix.size()-1;
    while( i <= n ){
        if(matrix[0][i] < target) i++;
        else if (matrix[0][i] == target) return true;
        else {
            break;
        }
    }

    y = i-1;
    /// ��Χ�������½�
    while( matrix[x][y] != target ){

        if( x>max_row || y > max_col )
            break;
        /// ÿ�����·���һ�� ���ҵ���һ������ target��
        if ( matrix[x][y] < target ){
            x++;
        }
        /// �������
        if ( matrix[x][y] > target){
            x = x-1;
            y = y-1;
        }
        if (matrix[x][y] == target)
            return true;
    }

    return false;

}



#endif //OFFER_HOT_240_H

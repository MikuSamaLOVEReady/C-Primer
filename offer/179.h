//
// Created by ����� on 2024/7/20.
//

#ifndef OFFER_179_H
#define OFFER_179_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution_84 {
public:
    int largestRectangleArea_wrong(vector<int>& heights) {
        int result = 0;
        /// �ױ߳��� �Ӵ�->С /// ��С->��Ҳ�ǿ��Ե� 1 ----> max_width
        int max_width = heights.size();
        for( int width = max_width ; width>0 ; --width ) {
            ///Ѱ�ҵ�ǰÿ�������µ����height
            for( int start_index = 0 ; start_index+width <= max_width ; ++start_index ) {
                int min_height = INT_MAX;
                for( int i = start_index ; i< start_index+width  ; ++i){
                    if ( min_height > heights[i]  ) min_height = heights[i];
                }
                int cur_size  = width * min_height;
                if( result < cur_size ) result = cur_size;
            }
        }
        return result;
    }



    int largestRectangleArea(vector<int>& heights) {

        /// ö��height
        /// �õ���stack �ҵ�ǰheight����һ��<�� ��index ���Ҳ��һ��< ����index
        vector<int> left(heights.size() , -1); /// �洢��ǰindex����һ��С������ֵ

        stack<int> st;
        /// �������ұ���
        for( int i = 0 ; i<heights.size() ; ++i ){


        }



    }


};




#endif //OFFER_179_H

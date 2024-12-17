//
// Created by 罗瑞笛 on 2024/7/20.
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
        /// 底边长度 从大->小 /// 从小->大也是可以的 1 ----> max_width
        int max_width = heights.size();
        for( int width = max_width ; width>0 ; --width ) {
            ///寻找当前每个窗口下的最低height
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

        /// 枚举height
        /// 用单调stack 找当前height左侧第一个<它 的index 和右侧第一个< 它的index
        vector<int> left(heights.size() , -1); /// 存储当前index左侧第一个小于它的值

        stack<int> st;
        /// 从左向右遍历
        for( int i = 0 ; i<heights.size() ; ++i ){


        }



    }


};




#endif //OFFER_179_H

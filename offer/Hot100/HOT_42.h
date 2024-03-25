//
// Created by 罗瑞笛 on 2024/3/3.
//

#ifndef OFFER_HOT_42_H
#define OFFER_HOT_42_H


class Solution_42 {
public:

    /// \param vect
    /// \param start_index
    /// \return -1 表示没有找到
    int find_minsEqual( vector<int>& vect  , int start_index )
    {
        for(int i = start_index ; i<vect.size() ; ++i)
        {
            if( vect[i] <= 0) return i;
        }
        return -1;
    }


    /// Time out
    int trap_timeout(vector<int>& height) {

        vector<int> lower_fix(height.size());           /// 开始遍历、相邻两个0之间的_非0值 记录进result中
        vector<int> result (height.size() , 0);            /// 每轮记录槽位中的水 、 如果当前有水则覆盖。
        int scan_height = 1;
        bool isend = false;
        /// 如果没有0 则表示等位线 扫描到头 结束 Wrong
        /// while( std::find(lower_fix.begin(), lower_fix.end(),0) != std::end(lower_fix) )
        while ( !isend )
        {
            isend = true;
            for(int i = 0 ; i<height.size() ;++i)
            {
                lower_fix[i] = scan_height - height[i];
                if(lower_fix[i] < 0 ) isend =false;
            }

            // auto left = std::find(lower_fix.begin() , lower_fix.end() ,0);
            int left_index = find_minsEqual(lower_fix , 0);
            while( left_index != -1)
            {
                auto right_index = find_minsEqual(lower_fix , left_index+1);     /// !如果left == null 则这里的find 没有意义 如果没找到右端 、则可以直接结束了
                
                if ( right_index == -1) break;
                left_index++; ///细节 ！ 需要单独右移一位  ？？ why？？
                while ( left_index < right_index)
                {
                    if( lower_fix[left_index] > 0 ) {
                        /// 已经有 雨水与否已经不再重要、直接覆盖
                        result[ left_index ] =  lower_fix[left_index];
                    }
                    left_index++;
                }
                left_index = right_index;
                ///right = std::find(left , lower_fix.end() ,0);      /// 如果没找到右端 、则可以直接结束了
            }
            scan_height++;
        }

        int final_result = 0;
        for( int va : result){
            final_result += va;
        }

        return final_result;
    }


    /// find _ height;
    int trap(vector<int>& height) {

        int ans = 0;
        /// 每次寻找 cur _左侧 和 _右侧 各自最高的部分
        for(int i = 1 ; i<height.size() ; ++i)  // index 从 1 开始
        {
            int max_left  = -1 , max_right = -1;
            for( int left = i ; left >= 0 ; --left)
            {
                max_left =  (height[left] >= max_left) ? height[left] : max_left;
            }

            for( int right = i+1 ; right < height.size() ; ++right)
            {
                max_right =  (height[right] >= max_right) ? height[right] : max_right;
            }

            int smaller_side = (max_left > max_right) ? max_right : max_left;
            /// 如果 当前value >= 两者之间小的、则不可能有水
            ///  只计算 当前value <  两者之间的
            if( height[i] < smaller_side) {
                ans = ans + (smaller_side - height[i]);
            }
        }
        return ans;
    }


    int trap_dp(vector<int>& height) {

        /// 快速记录 下标位置 左侧/右侧 拥有最大值 是多少
        vector<int> cur_left_Max(height.size() , 0);
        vector<int> cur_right_Max(height.size() , 0);
        cur_left_Max[0] = 0;

        int ans = 0;
        /// 每次寻找 cur _左侧 和 _右侧 各自最高的部分
        for(int i = 1 ; i<height.size() ; ++i)  // index 从 1 开始
        {
            cur_left_Max[i] =  (cur_left_Max[i-1] >= height[i-1]) ? cur_left_Max[i-1] : height[i-1];
        }

        for( int i = height.size()-2 ; i>=0 ; i-- )
        {
            cur_right_Max[i] = (cur_right_Max[i+1] >= height[i+1]) ? cur_right_Max[i+1] : height[i+1];
        }

        for(int i = 1 ; i<height.size() ; ++i)
        {
            int cur_samall = (cur_left_Max[i] >= cur_right_Max[i]) ? cur_right_Max[i] : cur_left_Max[i];
            if( height[i] < cur_samall)
            {
                ans +=  (cur_samall - height[i]) ;
            }
        }

        return ans;
    }
};

#endif //OFFER_HOT_42_H

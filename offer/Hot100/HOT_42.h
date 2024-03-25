//
// Created by ����� on 2024/3/3.
//

#ifndef OFFER_HOT_42_H
#define OFFER_HOT_42_H


class Solution_42 {
public:

    /// \param vect
    /// \param start_index
    /// \return -1 ��ʾû���ҵ�
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

        vector<int> lower_fix(height.size());           /// ��ʼ��������������0֮���_��0ֵ ��¼��result��
        vector<int> result (height.size() , 0);            /// ÿ�ּ�¼��λ�е�ˮ �� �����ǰ��ˮ�򸲸ǡ�
        int scan_height = 1;
        bool isend = false;
        /// ���û��0 ���ʾ��λ�� ɨ�赽ͷ ���� Wrong
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
                auto right_index = find_minsEqual(lower_fix , left_index+1);     /// !���left == null �������find û������ ���û�ҵ��Ҷ� �������ֱ�ӽ�����
                
                if ( right_index == -1) break;
                left_index++; ///ϸ�� �� ��Ҫ��������һλ  ���� why����
                while ( left_index < right_index)
                {
                    if( lower_fix[left_index] > 0 ) {
                        /// �Ѿ��� ��ˮ����Ѿ�������Ҫ��ֱ�Ӹ���
                        result[ left_index ] =  lower_fix[left_index];
                    }
                    left_index++;
                }
                left_index = right_index;
                ///right = std::find(left , lower_fix.end() ,0);      /// ���û�ҵ��Ҷ� �������ֱ�ӽ�����
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
        /// ÿ��Ѱ�� cur _��� �� _�Ҳ� ������ߵĲ���
        for(int i = 1 ; i<height.size() ; ++i)  // index �� 1 ��ʼ
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
            /// ��� ��ǰvalue >= ����֮��С�ġ��򲻿�����ˮ
            ///  ֻ���� ��ǰvalue <  ����֮���
            if( height[i] < smaller_side) {
                ans = ans + (smaller_side - height[i]);
            }
        }
        return ans;
    }


    int trap_dp(vector<int>& height) {

        /// ���ټ�¼ �±�λ�� ���/�Ҳ� ӵ�����ֵ �Ƕ���
        vector<int> cur_left_Max(height.size() , 0);
        vector<int> cur_right_Max(height.size() , 0);
        cur_left_Max[0] = 0;

        int ans = 0;
        /// ÿ��Ѱ�� cur _��� �� _�Ҳ� ������ߵĲ���
        for(int i = 1 ; i<height.size() ; ++i)  // index �� 1 ��ʼ
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

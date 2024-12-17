//
// Created by 罗瑞笛 on 2024/3/2.
//

#ifndef OFFER_BINARYSEARCH_H
#define OFFER_BINARYSEARCH_H


/// 搜索区间_为全封闭 、 找到target的第一个
int binary_search_classic( vector<int>& nums , int target , bool find_lowest = true ){
    int left = 0 , right = nums.size()-1;
    int res  = -1;
    while ( left <= right )
    {
        int mid = (left + right) >> 1;
        if( nums[mid] == target )
        {
            if(find_lowest){
                right = mid - 1;
            }
            else left = mid + 1;
            res = mid;
        }
        else if ( nums[mid] > target) {
            right = mid -1;
        }
        else  {
            left = mid + 1;
        }
    }
    return res;
}

/// 找第一个 <= target 的值
/// 找最后一个 >= target 的值          找第一个 >target 元素-1
int binary_search_classic( vector<int>& nums , int target) {
    int left = 0 , right = nums.size()-1;

    while( right < left ) {

        int mid = left + (right - left) / 2;
        if( nums[mid] > target ){               //// wrong!!!!!! >=
            right = mid-1;
        }
        else {
            left = mid+1;
        };
    }
    return left;
}


/// 这是左闭 右开
/// 这是闭区间实现？
vector<int>::iterator  binary_search ( vector<int>::iterator it_begin , vector<int>::iterator it_end, int x ){
    while( it_begin < it_end ){
        auto mid_it = it_begin + (it_end - it_begin) / 2;
        if( *mid_it >= x){              /// >=
            it_end  = mid_it ;
        }
        else {
            it_begin = mid_it + 1;
        }
    }


    return it_begin;

}


#endif //OFFER_BINARYSEARCH_H

//
// Created by ����� on 2024/2/26.
//

#ifndef OFFER_HOT_15_H
#define OFFER_HOT_15_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution_015 {
public:
    /// BUG:�����޷��ų��ظ���
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            int target = -nums[i];
            /// <value �� index>
            unordered_multimap<int , int> hasvisted;
            for( int j = i+1 ; j<nums.size() ; j++ )
            {
                int va = target - nums[j] ;  /// ��Ѱ�ҵĵڶ�������
                auto it = hasvisted.find(va);
                if( it != hasvisted.end() )
                {
                    res.push_back( { nums[i] , nums[j] , it->first } );
                }
                hasvisted.insert(make_pair(nums[j] , j));
            }
        }
        return res;
    }



};

///
vector<vector<int>> threeSum_real(vector<int>& nums) {

    vector<vector<int>> res;
    std::sort(nums.begin(), nums.end());    /// ��Ȼ��Ҫ���ź���
    if( nums.size() == 0 || nums[0] > 0 ) return {};  /// �������

    for(int i = 0 ; i<nums.size() ; ++i)
    {
        while( nums[i] == nums[i+1]) ++i; ///���������ظ�����ʼλ��
        //if(i>0 && nums[i] == nums[i-1]) continue;

        int left = i+1;
        int right = nums.size()-1;

        while (left < right)
        {
            if( nums[left] + nums[i] + nums[right] == 0)
            {
                res.push_back( {nums[left] , nums[i] , nums[right]} );
                /// *** ע������ֻ�� ��ǰ�����̽��һ��λ�á������ϻ�û�ƶ�����ͬ��Ԫ��
                while( left < right && nums[left] == nums[left+1])
                    left++;
                while( left < right && nums[right] == nums[right-1])
                    right--;
                left++;
                right--;
            }
            else if ( nums[left] + nums[i] + nums[right] < 0 )  /// С�Ĳ�����
            {
                left++;
            }
            else{
                right--;    /// ���̫����
            }
        }
    }
    return res;
}



#endif //OFFER_HOT_15_H

//
// Created by di on 2023/6/15.
//

#ifndef OFFER_15_H
#define OFFER_15_H

#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    //ѡ��
    for(int i=0 ;  i<nums.size() && nums[i]<=0  ; ++i)
    {
        int front = i+1;
        int end   = nums.size()-1;
        //ĳһ�ֽ�����
        while(front<end){
            //�����ڵ�ʱ��ȥ��
            while(  front< end && nums[front] + nums[end] + nums[i] > 0 ){
                --end;
                while(front <= end && nums[end] == nums[end+1]) --end;
            }
            while(  front< end && nums[front]+ nums[end] + nums[i] < 0 ){
                ++front;
                while(front <= end && nums[front] == nums[front-1]) ++front;
            }

            //������ж� �� ���ȥ���ظ���
            if( nums[front]+ nums[end] + nums[i] == 0  && front< end ){
                vector<int> one = { nums[front], nums[end], nums[i] };
                result.push_back(one);
                ++front; --end;
                //�ƶ� ǰ��ָ�룬������������
                while (front< end && nums[end] == nums[end+1]) --end;
                while (front< end && nums[front] == nums[front-1]) ++front;
            }
        }
        //�ж�ǰ�� �Ƿ� �Ѿ����Ѿ��ҹ���Ԫ�� //pre_int
        while( i+1<nums.size() && nums[i+1] == nums[i] ){
            ++i;
        }
    }

    return result;
}

#endif //OFFER_15_H

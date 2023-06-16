//
// Created by ����� on 2023/6/12.
//

#ifndef OFFER_15_H
#define OFFER_15_H
#include <vector>
using namespace std;

//�ҳ����п��ܵ���� ������C{n,x}
// **********************̫����**********************
vector<vector<int>> threeSum(vector<int>& nums) {
    //int index = 0;
    vector<vector<int>> result;
    if(nums.size() <3 ) return result;
    for(int i = 0 ; i<nums.size() ;++i ){
        for(int j = i+1 ;j<nums.size() ; ++j){
            for( int k = j+1 ; k<nums.size() ; ++k ){
                if(nums[i] + nums[j] + nums[k] == 0){
                    bool alreadyin = false;
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    std::sort(temp.begin(), temp.end());
                    for(auto pre: result){
                        if(pre == temp) {
                            alreadyin = true;
                            break;
                        }
                    }
                    if(alreadyin) continue;
                    else result.push_back(temp);
                }
            }
        }
    }
    return result;
}



vector<vector<int>> threeSum2(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> copy(nums);
    std::sort(copy.begin(), copy.end());
    int left = 0 , right = 0;
    int pre_ivalue = 1e5+1;
    for(int i = 0 ; i<copy.size() && copy[i] <= 0  ; ++i){
        if(copy[i] == pre_ivalue) continue;
        pre_ivalue = copy[i];
        left = i+1 ;
        right = copy.size()-1;
        while(left < right){

            while( copy[i] + copy[left] + copy[right] > 0 && left < right){
                int pre_right = copy[right];
                right--;
                while(copy[right] == pre_right ){
                    right--;
                }
            }

            while(copy[i] + copy[left] + copy[right] < 0 && left < right){
                int pre_left = copy[left];
                left++;
                while(copy[left] == pre_left){
                    left++;
                } //left++;
            }

            //������˵һ������ȣ����в���ȵ������
            if(copy[i] + copy[left] + copy[right] == 0 && left < right){
                //result.push_back()
                vector<int> temp = {copy[i] , copy[left] , copy[right]};
                result.push_back(temp);
                //һ���ҵ�һ�飬�򲻿������������Χ���ҵ���һ��
                break;
            }

        }
    }
    return result;

}

#endif //OFFER_15_H

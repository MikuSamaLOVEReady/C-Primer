//
// Created by ����� on 2023/7/17.
//

#ifndef OFFER_16_H
#define OFFER_16_H

//�����һ�룬˫ָ�����yyds������������3�����������
int threeSumClosest(vector<int>& nums, int target) {
    //��С��������
    sort(nums.begin(), nums.end());
    int cur = 0;
    int below = INT16_MIN , above = INT16_MAX;
    for(int i = 1 ; i+1 < nums.size() ;++i){
        cur = nums[i] + nums[i-1] + nums[i+1];
        if(cur < target){
            below  =  cur;
        }
        else{
            above = cur;
            break;
        }
    }
    if(target-below > above - target){
        return above;
    }
    else{
        return below;
    }
}

//�����һ�룬˫ָ�����yyds������������3�����������
int threeSumClosest2(vector<int>& nums, int target) {
    //��С��������
    sort(nums.begin(), nums.end());
    int result = 0;
    int dis = INT16_MAX;

    for(int i = 0 ; i+2 < nums.size() ; ++i){
        int start = i+1 , end = nums.size() - 1;
        int cur_result = 0;
        while(start != end){
            cur_result = nums[i] + nums[start] + nums[end];
            if( cur_result < target) ++start;
            else if (cur_result > target) --end;
            else return target;
            // ͬ������ ��target�ľ��룬���
            int cur_dis = abs(target-cur_result);
            if(dis > cur_dis) {
                dis =cur_dis;
                result = cur_result;
            }
        }
    }
    return result;
}




#endif //OFFER_16_H

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
    //Ñ¡Ôñ
    for(int i=0 ;  i<nums.size() && nums[i]<=0  ; ++i)
    {
        int front = i+1;
        int end   = nums.size()-1;
        //Ä³Ò»ÂÖ½áÊøÁË
        while(front<end){
            //²»µÈÓÚµÄÊ±ºòÈ¥ÖØ
            while(  front< end && nums[front] + nums[end] + nums[i] > 0 ){
                --end;
                while(front <= end && nums[end] == nums[end+1]) --end;
            }
            while(  front< end && nums[front]+ nums[end] + nums[i] < 0 ){
                ++front;
                while(front <= end && nums[front] == nums[front-1]) ++front;
            }

            //Èç¹ûºóÅÐ¶Ï £¬ ÈçºÎÈ¥³ýÖØ¸´£¿
            if( nums[front]+ nums[end] + nums[i] == 0  && front< end ){
                vector<int> one = { nums[front], nums[end], nums[i] };
                result.push_back(one);
                ++front; --end;
                //ÒÆ¶¯ Ç°ºóÖ¸Õë£¬¼ÌÐøÇî¾¡ËùÓÐ×éºÏ
                while (front< end && nums[end] == nums[end+1]) --end;
                while (front< end && nums[front] == nums[front-1]) ++front;
            }
        }
        //ÅÐ¶ÏÇ°ºó ÊÇ·ñ ÒÑ¾­ÊÇÒÑ¾­ÕÒ¹ýµÄÔªËØ //pre_int
        while( i+1<nums.size() && nums[i+1] == nums[i] ){
            ++i;
        }
    }

    return result;
#include <vector>
using namespace std;

//ÕÒ³öËùÓÐ¿ÉÄÜµÄ×éºÏ £¬¼´ÇóC{n,x}
// **********************Ì«ÂýÁË**********************
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

            //°´ÀíÀ´ËµÒ»¶¨»áÏàµÈ£¬»áÓÐ²»ÏëµÈµÄÇé¿öÂð£¿
            if(copy[i] + copy[left] + copy[right] == 0 && left < right){
                //result.push_back()
                vector<int> temp = {copy[i] , copy[left] , copy[right]};
                result.push_back(temp);
                //Ò»µ©ÕÒµ½Ò»×é£¬Ôò²»¿ÉÄÜÔÙÔÚÕâ¸ö·¶Î§ÄÚÕÒµ½ÁíÒ»×é
                break;
            }

        }
    }
    return result;

}

#endif //OFFER_15_H

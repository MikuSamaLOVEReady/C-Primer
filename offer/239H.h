//
// Created by 罗瑞笛 on 2023/7/17.
//

#ifndef OFFER_239H_H
#define OFFER_239H_H


//暴力求解 -- 超时
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int cur_max = nums[0]; // 初始化最大值为第一个位置上
    vector<int> result = {};

    for(int i = 0 ; i+k <= nums.size() ; ++i){
        int count = k-1; //比较次数
        int offset = 0;
        cur_max = nums[i];
        while(count){
            cur_max = (cur_max >= nums[i+1+offset]) ? cur_max : nums[i+1+offset];
            --count;
            ++offset;
        }
        result.push_back(cur_max);
    }
    return result;
}

///Q： 我该怎么把之前的大小关系保存 -> 使用heap  的变种优先队列 priority_queue
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    // < num ，index>
    int n = nums.size();
    priority_queue<pair<int,int>> q;
    //先把前k个放入优先队列
    for(int i  = 0 ; i<k ; ++i){
        q.emplace(nums[i] ,i); //不用makez_pair
    }
    vector<int> ans = {q.top().first};
    for(int i = k ; i < n; ++i ){
        //empalce是提供原料构造一个Obj,而push_back 提供完整的元素
        q.emplace(nums[i],i);
        while(q.top().second <= i-k ){
            q.pop();
        }
        ans.push_back(q.top().first);
    }
    return ans;
}

class one_int_obj{

public:
    inline one_int_obj(int i) : value(i)
    {

    };

public:
    int value;

};



#endif //OFFER_239H_H

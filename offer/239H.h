//
// Created by ����� on 2023/7/17.
//

#ifndef OFFER_239H_H
#define OFFER_239H_H


//������� -- ��ʱ
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int cur_max = nums[0]; // ��ʼ�����ֵΪ��һ��λ����
    vector<int> result = {};

    for(int i = 0 ; i+k <= nums.size() ; ++i){
        int count = k-1; //�Ƚϴ���
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

///Q�� �Ҹ���ô��֮ǰ�Ĵ�С��ϵ���� -> ʹ��heap  �ı������ȶ��� priority_queue
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
    // < num ��index>
    int n = nums.size();
    priority_queue<pair<int,int>> q;
    //�Ȱ�ǰk���������ȶ���
    for(int i  = 0 ; i<k ; ++i){
        q.emplace(nums[i] ,i); //����makez_pair
    }
    vector<int> ans = {q.top().first};
    for(int i = k ; i < n; ++i ){
        //empalce���ṩԭ�Ϲ���һ��Obj,��push_back �ṩ������Ԫ��
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

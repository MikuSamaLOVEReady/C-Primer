//
// Created by ����� on 2023/7/6.
//

#ifndef OFFER_11_H
#define OFFER_11_H

//����ö�� -- O(n^2)
int maxArea(vector<int>& height) {
    int cur_max = INT16_MIN;
    int n = height.size();

    for(int i = 0 ; i < n ; ++i){
        for(int j = i+1 ; j<n ; ++j){
            int heigh = (height[i] <= height[j] ? height[i]:height[j]);
            int val = (j-i) * heigh;
            if(val > cur_max) {cur_max = val;}
        }
    }

    return cur_max;
}


//˫ָ��
/// ����˼·��
/// ���õױ߿�ȣ�ͷβָ���������� ֻ�бȵ�ǰ�����е͵�һ���ߵ�ʱ��ſ����ܵ��������
/// �����ָߵͷ�ת��ʱ����Ҫ�л���������
/// \param height
/// \return
int maxArea2(vector<int>& height) {
    //ȷ����ʼ״̬
    int front = 0 , end = height.size() - 1;
    int lower_index = (height[front] < height[end] ? front:end);
    int cur_max = INT16_MIN;

    //�����Ĺ����� ���ϸ���front �� end
    while(front != end){
        cur_max = (cur_max > (end - front) * height[lower_index] ? cur_max : (end - front) * height[lower_index]);
        //��ʱlower_index �� endָ��  ǰ <- �� ����
        if(lower_index == end){
            //�ҵ�front - end֮���end��΢��һ���ֵ(�������)
            while( lower_index > front && height[lower_index] <= height[end]){
                --lower_index;
            }
            //���·�Χ
            end = lower_index;
            // ֻ�е���С��תʱ������Ҫ�������
            if(height[lower_index] > height[front]){
                lower_index = front;
            }
        }
        //lower_index��ʱ��front  ǰ -> �� ����
        else{
            while( lower_index < end && height[lower_index] <= height[front]){
                ++lower_index;
            }
            //���·�Χ
            front = lower_index;
            //��ʱ�ϵ͵ı����end
            if(height[lower_index] > height[end]){
                lower_index = end;
            }
        }
    }

    return cur_max;
}



#endif //OFFER_11_H

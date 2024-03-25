//
// Created by ����� on 2024/3/18.
//

#ifndef OFFER_HOT_406_H
#define OFFER_HOT_406_H


class Solution_406 {
public:
    vector<vector<int>> reconstructQueue( vector<vector<int>>& people ) {

        vector<vector<int>> res;
        ///�������Ŀ�ġ�ʹ�� people[h,k] ���� ��������ʱ�򲻻�Ӱ��_�����򲿷�
        sort(people.begin() , people.end() , [] (const vector<int>& a , const vector<int>& b){
            if(a[0]  == b[0]) return a[1] < b[1];       /// ���ڶ���ɱȴ�С�Ĳ��֡�ѡ��ֱ�Ƚ�
            return a[0] > b[0];
        });

        for( int i=0 ; i<people.size() ;++i){
            if( res.size() <= people[i][1])  ///  people[i][1] ��ʾ��Ҫ�����λ�á������ǰsize���㹻
            {
                res.push_back(people[i]);
            }else{      ///���������λ����size֮ǰ
                res.insert( res.begin() + people[i][1] , people[i]);    /// people[i][1]  ��Ӧindexλ��
            }
        }
        return res;
    }
};

#endif //OFFER_HOT_406_H

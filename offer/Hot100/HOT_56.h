//
// Created by ����� on 2024/3/11.
//

#ifndef OFFER_HOT_56_H
#define OFFER_HOT_56_H

class Solution_56 {
public:


    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<string>> ans;
        /// ��������
        std::sort( intervals.begin() , intervals.end() , [](const std::vector<int>& a, const std::vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        res.push_back( *(intervals.begin()) );

        /// ���������򡢷�������
        /// case1��  vec[0] ��߽粻�� res[size-1] ���Ҳ�߽��ڡ����ʾ���µķֶΡ�ֱ�� res.push
        /// case2:  vec[0] ��߽���  res[size-1] ���Ҳ�߽��� (vec[0] <= res[size-1][0] )�� �������ұ߽�Ƚ�
        for( auto& vec : intervals){
            /// res[res.size()-1] һֱ���ʽ��ĩβ��
                if( vec[0] > res[res.size()-1][1] ){
                    res.push_back( vec );
                }
                else{
                    res[res.size()-1][1] = vec[1] > res[res.size()-1][1]  ?  vec[1] : res[res.size()-1][1];
                }
        }
        return res;
    }

};


#endif //OFFER_HOT_56_H

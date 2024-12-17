//
// Created by ����� on 2024/4/4.
//

#ifndef OFFER_157_ORDERSEQUENCE_H
#define OFFER_157_ORDERSEQUENCE_H

#include <set>
///�����Ͼ���ȫ����
class Solution_CLR157 {
public:
    vector<string> res;
    string cur_str{};
    void per_mute( vector<bool>& onPath , string& str){

        if(cur_str.size() == onPath.size()) {
            ///auto it = std::find(res.begin(), res.end(),cur_str); ��ʱ
            ///if(it == res.end()){
                res.push_back(cur_str);
            ///}
            return;
        }

        /// ��֧ char pre_ch = '1'; ����ֻ�ų�����һ������ĺͱ��Ρ���� ababcddc ���� ������a�޷��ų�
        ///  ÿ���ַ�ֻ�ڴ�λ�̶�һ��
        set<char> visited;
        for(int i = 0 ; i<onPath.size() ;i++){
            if( !onPath[i] ){
                if( visited.find(str[i]) != visited.end()) continue;
                onPath[i] = true;
                cur_str.push_back(str[i]);
                visited.insert(str[i]);
                per_mute(onPath , str);
                cur_str.pop_back();
                onPath[i] = false;
            }
        }
    }

    vector<string> goodsOrder(string goods) {

        vector<bool> On_Path(goods.size() , false);
        per_mute(On_Path , goods);
        return  res;
    }

};

#endif //OFFER_157_ORDERSEQUENCE_H

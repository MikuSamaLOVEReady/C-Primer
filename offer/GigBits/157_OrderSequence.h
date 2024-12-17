//
// Created by 罗瑞笛 on 2024/4/4.
//

#ifndef OFFER_157_ORDERSEQUENCE_H
#define OFFER_157_ORDERSEQUENCE_H

#include <set>
///本质上就是全排列
class Solution_CLR157 {
public:
    vector<string> res;
    string cur_str{};
    void per_mute( vector<bool>& onPath , string& str){

        if(cur_str.size() == onPath.size()) {
            ///auto it = std::find(res.begin(), res.end(),cur_str); 超时
            ///if(it == res.end()){
                res.push_back(cur_str);
            ///}
            return;
        }

        /// 剪支 char pre_ch = '1'; 这种只排除了上一个放入的和本次、如果 ababcddc 这种 第三个a无法排除
        ///  每种字符只在此位固定一次
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

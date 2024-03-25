//
// Created by 罗瑞笛 on 2024/3/18.
//

#ifndef OFFER_HOT_406_H
#define OFFER_HOT_406_H


class Solution_406 {
public:
    vector<vector<int>> reconstructQueue( vector<vector<int>>& people ) {

        vector<vector<int>> res;
        ///先排序的目的、使得 people[h,k] 中在 有序插入的时候不会影响_已有序部分
        sort(people.begin() , people.end() , [] (const vector<int>& a , const vector<int>& b){
            if(a[0]  == b[0]) return a[1] < b[1];       /// 存在多个可比大小的部分、选择分别比较
            return a[0] > b[0];
        });

        for( int i=0 ; i<people.size() ;++i){
            if( res.size() <= people[i][1])  ///  people[i][1] 表示想要插入的位置、如果当前size还足够
            {
                res.push_back(people[i]);
            }else{      ///如果想插入的位置在size之前
                res.insert( res.begin() + people[i][1] , people[i]);    /// people[i][1]  对应index位置
            }
        }
        return res;
    }
};

#endif //OFFER_HOT_406_H

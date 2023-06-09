//
// Created by ÂÞÈðµÑ on 2023/5/31.
//

#ifndef CHAPTER7_PAIR_H
#define CHAPTER7_PAIR_H


void creatPair(){
    std::vector<pair<string,int>> result;
    string str;
    int val;
    while(cin >> str >> val ){
        //pair<string ,int> cur_p = {str , val};
        pair<string ,int> cur_p (str , val);
        result.push_back(cur_p);
    }
}

#endif //CHAPTER7_PAIR_H

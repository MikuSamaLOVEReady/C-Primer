//
// Created by di on 2023/6/19.
//
#ifndef CHAPTER7_FORWARD_LIST_H
#define CHAPTER7_FORWARD_LIST_H

#include <forward_list>

using namespace std;
void func_9_27(forward_list<int>& it){
    //
    auto prev = it.before_begin();
    auto curr = it.begin();
    while(curr != it.end()){
        if(*curr%2){
            curr = it.erase_after(prev);
        }else{
            prev =curr;
            ++curr;
        }
    }
    return ;
}

void func_9_28(forward_list<string>& it , const string& s1 , const string& s2){
    auto cur = it.begin();
    auto prev = it.before_begin(); //一起移动，当

    while( cur!= it.end()){
        if(*cur == s1){
            it.insert_after(cur,s2);
            return;
        }
        prev = cur;
        cur++;
    }
    it.insert_after(prev,s2);
    std::cout << "woc" << std::endl;
    return;
}



#endif //CHAPTER7_FORWARD_LIST_H

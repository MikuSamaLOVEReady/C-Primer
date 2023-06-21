//
// Created by 罗瑞笛 on 2023/6/9.
//

#ifndef CHAPTER7_SEQUENCE_CONTAIN_H
#define CHAPTER7_SEQUENCE_CONTAIN_H
#include <list>
#include <deque>
#include <vector>
#include <array>
#include <string>

using namespace std;
vector<int>::const_iterator funcs( vector<int>::const_iterator  begin , vector<int>::const_iterator end , int value){
    list<int> l1;
    list<deque<int>> l2;
    // list<int>::size_type 足够表示元素数量MAX的type

    /*
    while(begin!=end){
        if(*begin == value) return true;
    }
    */
    list<int> list1;
    list<int>::iterator iter1 = list1.begin() , iter2 = list1.end();

    list<string>::iterator iter;
    auto it = list1.begin();

    const list<int> list2;
    auto it2 = list2.begin();


    list<string>::const_iterator con_iter;

    // for( vector<int>::size_type  i = 0 ; i<  ;++i )

    while(begin!=end){
        if(*begin == value){
            return begin;
        }
    }
    return end;
}

void test2(){
    vector<int> vec;
    auto it = vec.begin();
    auto it_2 = vec.end();

    list(it,it_2); //利用 vector的元素构造
    list<int> seq(10);

    vector<const char*> articles = {"a","an","the"};
    vector<std::string> ste = {"124","1241"};
    deque<string> authList(ste.begin(),ste.end());
    // 用const char* -> 初始化 string
    deque<string> authList2(articles.begin(),articles.end());
}

bool cmpvec(vector<int> &v1 , vector<int> &v2){
    return v1==v2;
}

//bool
bool cmpvecAlist (list<int> &v1 , vector<int> &v2){
    list v2_copy(v2.begin(),v2.end());
    return v1==v2_copy;
}

#endif //CHAPTER7_SEQUENCE_CONTAIN_H

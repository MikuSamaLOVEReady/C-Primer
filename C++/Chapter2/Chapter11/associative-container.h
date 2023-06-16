//
// Created by 罗瑞笛 on 2023/5/31.
//

#ifndef CHAPTER7_ASSOCIATIVE_CONTAINER_H
#define CHAPTER7_ASSOCIATIVE_CONTAINER_H

#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

void mapTest(){
    //构造函数创建空容器
    map<std::string , ::size_t> word_count;

    string word;
    while( cin >> word)
        ++word_count[word]; //key如果不在hash表中，则自动创建一个，个数为0[这个是默认值?]并+1;
    for(const std::pair<std::string , ::size_t>& w : word_count){
        cout<< w.first << "occurs" << w.second << "tims" << std::endl;
    }
}


void setTest(){
    //列表初始化
    set<string> exclude = {
            "The" , "But" , "And" , "Or" , "An" , "A",
            "The" , "but" , "and"
    };

    set<string> exclude2 = exclude;
    set<string> exclude3(exclude);
    //忽略符号
    map<string , ::size_t> word_count  {
            {"woc",10}, {"Austen",20},
    };
    string word;
    while( cin>>word ) {
        if(exclude.find(word) != exclude.end()){
            ++word_count[word];
        }
    }
}

void init_multi(){
    vector<int> ivec;
    for(int i = 0 ; i<10 ; ++i){
        ivec.push_back(i);
        ivec.push_back(i);//每种重复保存一次
    }
    //迭代器表示取得哪些范围内的数据
    set<int> iset(ivec.cbegin() , ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    std::cout<< ivec.size() << std::endl;
    std::cout<< iset.size() << std::endl;
}

void family(){
    map<string , vector<string>> fam;
    string name;
    for(string in ; cout<<"family :\n" , cin>>in && in != "@q";){
        for(string cn ; cout<<"child name :\n" , cin>>cn && cn != "@q";){
                fam[in].push_back(cn);
        }
    }
    return ;
}

void family_withdata(){
    map<string , vector< pair<string , int>> > fam;
    string name;
    int time = 0;
    for(string in ; cout<<"family :\n" , cin>>in && in != "@q";){
        for(string cn ; cout << "child name :\n" , cin >> cn >> time && cn != "@q";){
            auto child = make_pair(cn, time);
            fam[in].push_back(child);
        }
    }

    return ;
}

void map_iter(){
    multiset<string> sss { "A" , "B" , "C" };
    map<string , int> mpppd;
    map<string , int>::iterator map_it = mpppd.begin();
    cout << map_it->first;
    //viable conversion from 'ostream' to 'decltype(map_it->first)' (aka 'const std::string'
    //decltype(map_it->first) val =
    cout << typeid(decltype(map_it->first)).name() << std::endl;
    cout << map_it->second;
    //map_it->first = "new key"; // first
    multiset<string>::iterator set_it = sss.cbegin();
    while(set_it != sss.cend()){
        cout << *set_it <<endl;
        ++set_it;
    }
    //*set_it = "wete";
}






#endif //CHAPTER7_ASSOCIATIVE_CONTAINER_H

//
// Created by di on 2023/6/20.
//

#ifndef CHAPTER7_RESIZE_FUN_H
#define CHAPTER7_RESIZE_FUN_H
#include <list>

using namespace std;
void func_test(){
    list<int> ilist(10,42);
    ilist.resize(15); // 5个0会在后部出现
    ilist.resize(25,-1);
    ilist.resize(5,-1); //删除末尾的20个
    std::cout << "woc" <<std::endl;
}

void func_invalid_vec(){
    vector<int> val = {1,2,3,4,5};

    auto it = val.begin()+4; // 插入后将失效？
    std::cout << *it << std::endl;
    val.insert(val.begin()+2,77);
    std::cout << *it << std::endl;
}



#endif //CHAPTER7_RESIZE_FUN_H

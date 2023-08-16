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
    auto it = val.begin()+4; // 插入之后的元素将失效？
    std::cout << *it << std::endl;
    val.insert(val.begin()+2,77);
    std::cout << "WWWWWWWWWWWWWWWW" <<*it << std::endl;
}

void func_invalid_deque(){
    deque<int> dec_test = {1,2,3,4,5};

    auto it = dec_test.begin() + 2;
    cout << *it << endl;
    //头尾插入？ 只会让迭代器无效，ref和pointer将一直有效
    //So push_front() and push_back() will invalidate iterators,
    // but references to the elements themselves remain valid.
    dec_test.push_front(11);
    dec_test.push_front(22);
    cout << *it << endl;

    //如果插入到中间，则全部失效
    dec_test.insert(it , 88);
    cout << *it << endl;
    std::cout << "func_invalid_vec" << std::endl;
}

void func_donot_saveend(){
    vector<int> test = {1,2,3,4,5,6};
    auto head = test.begin();
    auto end = test.end();
    while(head != end){
        ++head;
        head = test.insert(head,42);
        auto end2 = test.end(); // 在扩大容器的时候会改变
        ++head;
    }
    return;
}

void fuc_9_31(){

    list<int> li = {0,1,2,3,4,5,6,7,8,9};
    auto it = li.begin();
    while(it!=li.end()){
        //复制奇数
        if( *it % 2){
               it = li.insert(it , *it);
               ++it;
               ++it;
        }
        //删除偶数
        else{
            it = li.erase(it);
        }
    }
    std::cout << "func_invalid_vec" << std::endl;
    return;
}






#endif //CHAPTER7_RESIZE_FUN_H

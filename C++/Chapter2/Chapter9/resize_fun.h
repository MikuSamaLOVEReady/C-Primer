//
// Created by di on 2023/6/20.
//

#ifndef CHAPTER7_RESIZE_FUN_H
#define CHAPTER7_RESIZE_FUN_H
#include <list>

using namespace std;
void func_test(){
    list<int> ilist(10,42);
    ilist.resize(15); // 5��0���ں󲿳���
    ilist.resize(25,-1);
    ilist.resize(5,-1); //ɾ��ĩβ��20��
    std::cout << "woc" <<std::endl;
}

void func_invalid_vec(){
    vector<int> val = {1,2,3,4,5};
    auto it = val.begin()+4; // ����֮���Ԫ�ؽ�ʧЧ��
    std::cout << *it << std::endl;
    val.insert(val.begin()+2,77);
    std::cout << "WWWWWWWWWWWWWWWW" <<*it << std::endl;
}

void func_invalid_deque(){
    deque<int> dec_test = {1,2,3,4,5};

    auto it = dec_test.begin() + 2;
    cout << *it << endl;
    //ͷβ���룿 ֻ���õ�������Ч��ref��pointer��һֱ��Ч
    //So push_front() and push_back() will invalidate iterators,
    // but references to the elements themselves remain valid.
    dec_test.push_front(11);
    dec_test.push_front(22);
    cout << *it << endl;

    //������뵽�м䣬��ȫ��ʧЧ
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
        auto end2 = test.end(); // ������������ʱ���ı�
        ++head;
    }
    return;
}

void fuc_9_31(){

    list<int> li = {0,1,2,3,4,5,6,7,8,9};
    auto it = li.begin();
    while(it!=li.end()){
        //��������
        if( *it % 2){
               it = li.insert(it , *it);
               ++it;
               ++it;
        }
        //ɾ��ż��
        else{
            it = li.erase(it);
        }
    }
    std::cout << "func_invalid_vec" << std::endl;
    return;
}






#endif //CHAPTER7_RESIZE_FUN_H

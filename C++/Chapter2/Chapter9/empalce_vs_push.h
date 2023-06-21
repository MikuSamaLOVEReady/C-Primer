//
// Created by ����� on 2023/6/17.
//

#ifndef CHAPTER7_EMPALCE_VS_PUSH_H
#define CHAPTER7_EMPALCE_VS_PUSH_H

class mytest{
public:
    inline mytest(int myval , string str):sal(myval), mytr(str){};

private:
    int sal;
    string mytr = "null";

};

class Sandbox
{
public:
    Sandbox(const string& n) : member(n) {}
    const string& member;
};


void fuc_9_20(){
    list<int> mylist = {1,2,3,4,5};
    deque<int> deque1 , deque2;
    auto it = mylist.begin();
    while( it !=mylist.end()){
       if( (*it) % 2 == 0) {
            deque1.push_back(*it);
       }else{
           deque2.push_back(*it);
       }
        ++it;
    }

    std::cout << "end" <<std::endl;
    return;
}

void fuc_9_21(){
    list<int> mylist = {1,2,3,4,5};
    vector<int> vec1 , vec2;
    auto it = mylist.begin();
    auto vec1_it = vec1.begin();
    auto vec2_it = vec2.begin();

    while( it !=mylist.end()){
        if( (*it) % 2 == 0) {
           vec1_it = vec1.insert(vec1_it , *it); //����ͷ����
        }else{
            vec2_it = vec2.insert(vec2_it , *it); //����ͷ����
        }
        ++it;
    }
    std::cout << "end" <<std::endl;
    return;
}

void fuc_9_22(){
    // �߲������->����
    vector<int> iv = {1,2,3,4 ,1,1, 1 ,1,1,1};
    auto iter = iv.begin();
    auto mid = iv.begin() + iv.size()/2;

    while(iter != mid)
    {
        if(*iter == 1){
            iv.insert(iter,2*2);
        }
        ++iter;
    }
    std::cout << "end" <<std::endl;
    return;
}

void fuc_9_26(){
    int ia[] = {0, 1 , 1,2,3,5,8,13,21,55,89};
    list<int> list1;
    vector<int> vet1;
    for(int va : ia){
        list1.push_back(va);
        vet1.push_back(va);
    }

    auto it = list1.begin();
    auto it_list_end = --list1.end();

    auto it_v   = vet1.begin();
    auto it_end = vet1.end()-1;
    while( it_v != vet1.end()){ //�����vet1 ��С��С���ؼ������ڿռ䲢û��ת�ƣ�����end()iterator�ܹ�һֱ��Ч�󶨵�ĩβ
        if( (*it_v)%2 == 0 ) it_v = vet1.erase(it_v);
        else ++it_v;
    }

    //ͬ�ϣ���Ȼ��Ч
    while(it != list1.end()){
        if( (*it)%2 != 0 ) it = list1.erase(it);
        else ++it;
    }

    std::cout << "end" <<std::endl;
    return ;
}



#endif //CHAPTER7_EMPALCE_VS_PUSH_H

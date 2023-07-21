//
// Created by ����� on 2023/7/14.
//

#ifndef CHAPTER7_COURSEWORK10_1_H
#define CHAPTER7_COURSEWORK10_1_H
#include <algorithm>
#include <list>

using namespace std;
void fun_10_1(int count){

    std::list<string> numbers;
    string input;

    /*
    int input;
    while(cin){
        std::cin >> input;
        std::cout << input << std::endl; //�����������ַ�������input = 0
        if(input == 0) break;
        numbers.push_back(input);
    }*/

    while(cin){
        std::cin >> input;
        numbers.push_back(input);
    }

    std::cout << "woc" << std::count(numbers.begin(), numbers.end(),"str") << std::endl;

    return;
}




//ע�� list��pop front��push front �Լ� pop_back �� push_back
class LRUCache {
public:
    LRUCache(int capacity) {
         capa  = capacity;
    }

    // ����ҵ�������Ҫ�������������λ��
    int get(int key) {
        auto it = lru_map.find(key);
        if(it == lru_map.end() ){
            return -1;
        }
        head_old_tail_new.push_back(*(it->second));
        head_old_tail_new.erase(it->second);
        lru_map[key] = --head_old_tail_new.end();
        //(*it).second
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = lru_map.find(key);
        //�����һ�ν�
        if( it == lru_map.end() ){
            //�����Ա
            if(lru_map.size() == capa){
                //�ȴ�����ɾ�����Ԫ��
                int val = head_old_tail_new.front().first;
                head_old_tail_new.erase( head_old_tail_new.begin()); //pop_�����
                //�ٰѶ�Ӧ��key ��hash��ɾ��
                lru_map.erase(val);
            }
            //�����µĲ������� ��û��Ա��ֱ�ӿ��Ӽ��ɣ�
            pair<int,int> cur_p(key,value);
            head_old_tail_new.push_back(cur_p);
            //����hash���������ӹ�ϵ
            lru_map[key] = --head_old_tail_new.end(); //����������ã������ΪʲôҪ��head����Ϊ��Ԫ�أ�β������Ϊ��Ԫ��
           // ͨ��begin����ֱ�ӷ��� iterator��end����֮���һ��λ��
        }
        //���֮ǰ��hash��
        else{
            //���������ҵ������Ƶ�ĩβ
            head_old_tail_new.push_back( pair<int,int>(key,value));
            //ɾ��֮ǰ �����е�Ԫ��
            head_old_tail_new.erase(it->second);
            //�����µ�����
            lru_map[key] = --head_old_tail_new.end(); //�����front�����µľͲ�����--�Ĳ���
        }
        return;
    }

private:
    int capa  = -1;
    list<pair<int,int>> head_old_tail_new;
    map<int , list<pair<int,int>>::iterator > lru_map;
};


#endif //CHAPTER7_COURSEWORK10_1_H

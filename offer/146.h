//
// Created by ����� on 2023/5/31.
//

#ifndef OFFER_146_H
#define OFFER_146_H

#include<map>
#include<list> //˫������Ľڵ�

//����֮��Ӧ������Ҫ���д洢��ǰԪ��
// û���������� ���� ʱ�临�ӶȲ���O(1)
using namespace std;
class LRUCache {

public:
    LRUCache(int capacity) : capacity(capacity){

    }

    int get(int key) {
        //���û�ҵ�
        if(data.find(key) == data.end()){
            return -1;
        }
        //����ҵ�
        data[key].second = 0;
        //�������ݼ���������
        auto it = data.begin();
        while(it!=data.end() ){
            (it->second.second) += 1;
            ++it;
        }
        return data[key].first;
    }

    void put(int key, int value) {
        //���ж��Ƿ���map��
        if(data.find(key) != data.end()){
            //���Ƽ���
            data[key].second = 1;
            data[key].first = value;
            //ֻ����
            return;
        }
        int cur_maxkey = -1;
        int cur_maxcout = 0;
        //����������������ޣ�����Ҫ���� ����������ֵ
        //������һ��vector����¼��ͷ�壿������Ҫ������ʲ��ң�����ͷ������Ľṹ��
       if(cur_count == capacity){
           //�������У� �ﲻ��O(1)
           auto it = data.cbegin();
           while(it!=data.cend() ){
               //���������ֵ���󣬸���max key
               if( it->second.second > cur_maxcout)
               {
                   cur_maxkey = it->first;
                   cur_maxcout =  it->second.second;
               }
               ++it;
           }
           //ɾ���û��
           data.erase(cur_maxkey);
           cur_count--;
       }

       //�������ݼ���������
        auto it = data.begin();
        while(it!=data.end() ){
            (it->second.second) += 1;
            ++it;
        }

       //�������µ�ֵ
       data.insert({key,std::pair<int ,int>(value, 1)});
       cur_count++;
    }

private:
    // key ��<value �� ʱ�������> ���ظ�
    map<int , std::pair<int, int> >  data;
    int capacity = 0;
    int cur_count = 0;

};

// hash_List Answer --> hash�ṩ���ٲ��ң�list�ṩ������
class LRUCache_HashList {
    //
    LRUCache_HashList(int capacity): capacity(capacity) {

    }

    int get(int key) {
      if( hashmap.find(key) == hashmap.end()){
            return -1;
      }
      //��Ȼ�Ѿ����� �������ֱ�Ӹ����±����
      //map<int, list<pair<int, int>>::iterator>::iterator result =  hashmap.find(key);
      //��Ҫ�ѽڵ��Ƶ��������
      auto value_pair =   *hashmap[key];
      cache.erase(hashmap[key]);    // ������ֻ�Ǵ�������
      cache.push_front(value_pair); // ����ͷΪ���£���βΪ���
      hashmap[key] = cache.begin();
      return hashmap[key]->second;
    }


    void put(int key, int value) {
        //����buffer��
        if(hashmap.find(key) == hashmap.end()){
            //�������������ɾ����ã��������¡���map hash�����¡�
            if(cache.size() == capacity){
                hashmap.erase(cache.back().first);
                cache.pop_back(); //ɾ������β�ã�ͷ��
            }
        }
        //��buffer�У������һ������Ӧ�����λ�ã�
        else{
            cache.erase(hashmap[key]);
        }
        cache.push_front(pair<int,int>(key,value)); //ÿ�αض������cache��˳�򣬲��ҽ�mapָ���µ�λ��
        hashmap[key] = cache.begin();
        //hashmap.insert(cache.begin()); ȱ��keyֵ����ֻ��value
    }


private:
    int capacity;
    map<int, list<pair<int, int>>::iterator> hashmap;   //ͬ��Ҳֻά��Ŀǰ��buffer�е�Ԫ��
    list<pair<int, int>> cache; //����ά�����������key

};

class LRUCache_HL_2{
    LRUCache_HL_2(unsigned int capacity):capacity(capacity){
    }

    //����
    int get(int key){
            //����ҵ���Ԫ��
            if(hash.find(key) != hash.end() ){
                //�ѷ��ʽڵ�Ӷ������ᵽ��ǰ��
                pair<int, int> exist_pair = *(hash.find(key)->second); //�ȼ��� hash[key] һ��
                queue.push_front(exist_pair);
                //ɾ��ԭλ�ýڵ�
                queue.erase( hash.find(key)->second);
                hash[key] = queue.begin(); //���ӵ�
                return hash.find(key)->second->second;
            }
            else{
                return -1;
            }
    }

    void put(int key , int value){
        //�ڴ���һ�ν���
        if(hash.find(key) == hash.end())
        {
            //����->ɾ��
            if(hash.size() == capacity){
                hash.erase(queue.back().first);
                queue.pop_back();
            }
        }
        //����Ѿ�����������
        else{
            queue.erase(hash[key]);
        }
        queue.push_front(pair<int,int>(key,value));
        hash[key] = queue.begin(); //���û���Զ����룬��������޸ġ�
    }






private:
    unsigned int capacity;
    list<pair<int,int>> queue; // ͷ��������Ԫ�أ�β�ͷ�����Ԫ��
    map<int, list<pair<int,int>>::iterator > hash;

};

#endif //OFFER_146_H

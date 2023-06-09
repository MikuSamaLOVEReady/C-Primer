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

    //
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

#endif //OFFER_146_H

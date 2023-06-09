//
// Created by 罗瑞笛 on 2023/5/31.
//

#ifndef OFFER_146_H
#define OFFER_146_H

#include<map>
#include<list> //双向链表的节点

//除此之外应当还需要队列存储当前元素
// 没法穷尽所有情况 并且 时间复杂度不是O(1)
using namespace std;
class LRUCache {

public:
    LRUCache(int capacity) : capacity(capacity){

    }

    int get(int key) {
        //如果没找到
        if(data.find(key) == data.end()){
            return -1;
        }
        //如果找到
        data[key].second = 0;
        //所有数据计数器自增
        auto it = data.begin();
        while(it!=data.end() ){
            (it->second.second) += 1;
            ++it;
        }
        return data[key].first;
    }

    void put(int key, int value) {
        //先判断是否在map中
        if(data.find(key) != data.end()){
            //重制计数
            data[key].second = 1;
            data[key].first = value;
            //只更新
            return;
        }
        int cur_maxkey = -1;
        int cur_maxcout = 0;
        //如果到大了容量极限，则需要弹出 计数器最大的值
        //可以用一个vector来记录，头插？【我想要随机访问并且，可以头部插入的结构】
       if(cur_count == capacity){
           //遍历所有？ 达不到O(1)
           auto it = data.cbegin();
           while(it!=data.cend() ){
               //如果计数器值更大，更新max key
               if( it->second.second > cur_maxcout)
               {
                   cur_maxkey = it->first;
                   cur_maxcout =  it->second.second;
               }
               ++it;
           }
           //删除最长没用
           data.erase(cur_maxkey);
           cur_count--;
       }

       //所有数据计数器自增
        auto it = data.begin();
        while(it!=data.end() ){
            (it->second.second) += 1;
            ++it;
        }

       //插入最新的值
       data.insert({key,std::pair<int ,int>(value, 1)});
       cur_count++;
    }

private:
    // key ：<value ， 时间计数器> 无重复
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
      //既然已经存在 ，则可以直接根据下标访问
      //map<int, list<pair<int, int>>::iterator>::iterator result =  hashmap.find(key);
      //需要把节点移到链表最后
      auto value_pair =   *hashmap[key];
      cache.erase(hashmap[key]);    // 这两步只是处理连表
      cache.push_front(value_pair); // 链表头为最新，表尾为最久
      hashmap[key] = cache.begin();
      return hashmap[key]->second;
    }

    //
    void put(int key, int value) {
        //不再buffer中
        if(hashmap.find(key) == hashmap.end()){
            //如果容量饱满，删除最久，插入最新。【map hash都更新】
            if(cache.size() == capacity){
                hashmap.erase(cache.back().first);
                cache.pop_back(); //删除链表尾久，头新
            }
        }
        //在buffer中，则更新一下它对应链表的位置，
        else{
            cache.erase(hashmap[key]);
        }
        cache.push_front(pair<int,int>(key,value)); //每次必定会更新cache的顺序，并且将map指向新的位置
        hashmap[key] = cache.begin();
        //hashmap.insert(cache.begin()); 缺少key值，我只有value
    }


private:
    int capacity;
    map<int, list<pair<int, int>>::iterator> hashmap;   //同样也只维护目前在buffer中的元素
    list<pair<int, int>> cache; //用于维护最新与最久key

};

#endif //OFFER_146_H

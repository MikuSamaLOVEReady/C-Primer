//
// Created by 罗瑞笛 on 2023/7/14.
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
        std::cout << input << std::endl; //如果输入的是字符串，则input = 0
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




//注意 list的pop front和push front 以及 pop_back 和 push_back
class LRUCache {
public:
    LRUCache(int capacity) {
         capa  = capacity;
    }

    // 如果找到，还需要更新它在链表的位置
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
        //如果第一次进
        if( it == lru_map.end() ){
            //如果满员
            if(lru_map.size() == capa){
                //先从链表删除最久元素
                int val = head_old_tail_new.front().first;
                head_old_tail_new.erase( head_old_tail_new.begin()); //pop_会更快
                //再把对应的key 从hash中删除
                lru_map.erase(val);
            }
            //构造新的插入链表 （没满员则直接开加即可）
            pair<int,int> cur_p(key,value);
            head_old_tail_new.push_back(cur_p);
            //并在hash中增加链接关系
            lru_map[key] = --head_old_tail_new.end(); //这里如何设置？这就是为什么要把head设置为新元素，尾巴设置为旧元素
           // 通过begin就能直接返回 iterator，end返回之后的一个位置
        }
        //如果之前在hash中
        else{
            //从链表中找到，并移到末尾
            head_old_tail_new.push_back( pair<int,int>(key,value));
            //删除之前 链表中的元素
            head_old_tail_new.erase(it->second);
            //建立新的链接
            lru_map[key] = --head_old_tail_new.end(); //如果用front存最新的就不存在--的操作
        }
        return;
    }

private:
    int capa  = -1;
    list<pair<int,int>> head_old_tail_new;
    map<int , list<pair<int,int>>::iterator > lru_map;
};


#endif //CHAPTER7_COURSEWORK10_1_H

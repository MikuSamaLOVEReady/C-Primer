//
// Created by 罗瑞笛 on 2023/7/21.
//

#ifndef CHAPTER7_READ_ONLY_H
#define CHAPTER7_READ_ONLY_H
#include <numeric>

void fun_10_3(){
    vector<int> vtr ={1,2,3,4,5};
    int val = 0;
    val = std::accumulate(vtr.cbegin(), vtr.cend(), val);
    std::cout << val <<std::endl;
}

void fun_10_4(){
    std::vector<double> vd = { 1.1, 0.5, 3.3 };
    int val = 0;
    // for( int val in vd) 在累加的时候已经将浮点数截断了
    val = std::accumulate(vd.cbegin(), vd.cend(), val);
    std::cout << val <<std::endl;
}

void fun_10_5(){
    std::string  s1 = "mufault";
    //s1 == "dd"

    //写入
    vector<int> vtr ;
    //fill_n(vtr.begin(), 10 , 15); //如果是空容器，则未定义操作
    //插入，此时写入的同时改变了容器size
    vector<int> vec;
    fill_n(back_inserter(vec),10,15);

    back_insert_iterator<vector<int>> it = back_inserter(vec); //指向end()
    *it = 235;
    std::cout << "oc";
    //std::cout << (*it) << std::endl;

    //数组copy
    int a1[] = {0,1,2,3,4,5,6,7,8,9};
    int a2[sizeof(a1)/sizeof(*a1)];

    //真 copy
    auto ptr = copy(begin(a1), end(a1),a2); //依然是
    std::cout << *ptr << std::endl;

    vector<int> vtet = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "PRE ADDRESS" << &(*vtet.begin()) << std::endl;
    replace(vtet.begin(), vtet.end(), 8, 100); // 改变同一位置上的元素
    std::cout << "AFTER ADDRESS" << &(*vtet.begin()) << std::endl;

    vector<int> copy_des;
    replace_copy(vtet.begin(), vtet.end(), back_inserter(copy_des) ,10 , 999); //第三个参数额外，指明替换后存放整体存放的位置
    std::cout << "AFTER ADDRESS" << &(*copy_des.begin()) << std::endl;
}


void fun_10_7() {
    list<int> lis;
    vector<int> des;
    int val;
    while ( cin >> val ){
        lis.push_back(val);
    }
    //将list中的数据插入到vector中
    copy(lis.begin(),lis.end(), back_inserter(des));
    for(auto v : des){
        std::cout <<v <<std::endl;
    }
}

//获得一个不重复的vector
void fun_delete_repeat(vector<string> &words){
    sort(words.begin(), words.end());
    auto it = unique(words.begin(),words.end()); //前闭后开，返回所有不重复元素的下一个
    words.erase(it,words.end());
}




#endif //CHAPTER7_READ_ONLY_H

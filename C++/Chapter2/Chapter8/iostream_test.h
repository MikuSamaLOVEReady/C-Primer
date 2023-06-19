//
// Created by 罗瑞笛 on 2023/6/7.
//

#ifndef CHAPTER7_IOSTREAM_TEST_H
#define CHAPTER7_IOSTREAM_TEST_H
#include <iostream>

using namespace std;

istream& my_fun(istream& in){
   //while(in.rdstate()) //rdstate 读出来4bit 表示当前状态

   string buf;
   while(in >> buf){
       cout<< buf << endl;
   }
   in.clear(); //重置为全部有效

}




#endif //CHAPTER7_IOSTREAM_TEST_H

//
// Created by ����� on 2023/6/7.
//

#ifndef CHAPTER7_IOSTREAM_TEST_H
#define CHAPTER7_IOSTREAM_TEST_H
#include <iostream>

using namespace std;

istream& my_fun(istream& in){
   //while(in.rdstate()) //rdstate ������4bit ��ʾ��ǰ״̬

   string buf;
   while(in >> buf){
       cout<< buf << endl;
   }
   in.clear(); //����Ϊȫ����Ч

}




#endif //CHAPTER7_IOSTREAM_TEST_H

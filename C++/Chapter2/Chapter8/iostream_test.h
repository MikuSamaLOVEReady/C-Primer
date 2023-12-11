//
// Created by 罗瑞笛 on 2023/6/7.
//

#ifndef CHAPTER7_IOSTREAM_TEST_H
#define CHAPTER7_IOSTREAM_TEST_H
#include <iostream>
#include <fstream>
#include <iomanip>

istream& my_fun(istream& in){
   //while(in.rdstate()) //rdstate 读出来4bit 表示当前状态

   //本质上是一个 unsigned int
   istream::iostate cur_stat;
   /*
    typedef unsigned int iostate;
    static const iostate badbit  = 0x1; //从低位开补
    static const iostate eofbit  = 0x2;
    static const iostate failbit = 0x4;
    static const iostate goodbit = 0x0;
    */

   if(in.eof()){
       std::cout << in.rdstate() << std::endl;
   }
   std::cout << in.rdstate() << std::endl;
   string buf;
   //commands_D
   while(in >> buf){
       cout<< buf << endl;
   }
   std::cout << "finish _input \n";
   in.clear(); //重置为全部有效
   return in;
}

// 定义一个结构体
struct MyStruct_f {
    int field1 = 10;
    double field2 = 20.3f;
};

void bind_cin_cout(){
    std::ofstream cout;
    std::cin.tie(&cout); //cin流 与 cout该吗；哦啊吗
    std::ostream *old_tie = cin.tie(nullptr); // old_tie指向对应的关联流, 并且cin不在有所指向
    cin.tie(&cerr);
}


void file_wrte(){
    std::ofstream outputfile("result.txt");
    if(outputfile.is_open()){
        outputfile << std::left << std::setw(4) << "Name" << std::setw(10) << "Age" << std::setw(10) << "Score" << std::endl;
        outputfile << std::left << std::setw(15) << "John" << std::setw(10) << 25 << std::setw(10) << 95.5 << std::endl;
        outputfile << std::left << std::setw(15) << "Alice" << std::setw(10) << 22 << std::setw(10) << 87.0 << std::endl;
    }

    int num1 = 123;
    double num2 = 45.678;
    std::string text = "Hello";

    // 输出左对齐的内容
    std::cout << std::left << std::setw(10) << num1 << std::setw(10) << num2 << std::setw(10) << text << std::endl;

}



#endif //CHAPTER7_IOSTREAM_TEST_H

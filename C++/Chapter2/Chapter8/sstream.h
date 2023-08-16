//
// Created by 罗瑞笛 on 2023/8/4.
//

#ifndef CHAPTER7_SSTREAM_H
#define CHAPTER7_SSTREAM_H

#include <sstream>

void sstr_test(){

    std::string input = "apple banana orange grape";
    std::istringstream iss(input);
    std::string fruit;
    //std::getline(iss, fruit, ',');
    while(iss >> fruit){
        std::cout << fruit << std::endl;
    }

    std::string  s1 , cur_num;
    vector<string> numebrs;
    while(getline(std::cin,s1)){
        istringstream recode(s1);
        while(recode >> cur_num){
            numebrs.push_back(cur_num);
        }
    }
}

void  fun_8_10(){
    vector<string> file_;
    ifstream infile("data.txt");
    string file_read;
    if(!infile){
        cerr << "wronmg" << std::endl;
    }
    //从文件中读取每一行
    while(getline(infile,file_read)){
        file_.push_back(file_read);
    }
    string cur;
    for(auto& vec_str:file_ ){
        stringstream cur_s(vec_str); //将string copy到流中
        while(cur_s >> cur){
            std::cout << cur << " !endl" << std::endl;
        }
    }
}

struct Point {
    int x;
    int y;
};

class obj {

private:
    int va;
};

void fun_8_11(){
    Point   p1;
    string line , word;
    vector<int> ve;
    istringstream  record;
    while(getline(cin , line)){
        record.clear();
        record.str(line); //重新绑定
    }
}

void fun_8_3(){
    ostringstream ostr;
    ostr << "woc" << " ";
    ostr << "1245163";
    ostr << 52;
    string s1 =  "woc";
    int va = 52;
    s1 += va;//
    std::cout <<  s1 << ":va 值" << va <<std::endl;
    std::cout << ostr.str() << std::endl; //没有刷新buffer
}





#endif //CHAPTER7_SSTREAM_H
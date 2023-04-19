//
// Created by 罗瑞笛 on 2023/4/11.
//

#ifndef CHAPTER2_FUNCTION_H
#define CHAPTER2_FUNCTION_H

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstring>
#include <cctype>
namespace funcs{

    double sqqer(double x){
        return x*x;
    }


    size_t count_calls(){
        static size_t ctr = 0;
        return ctr++;
    }

    size_t first_0(){
        static int flag = 0;
        if(flag > 0) {
            return flag;
        }
        else {
            return flag++;
        }
    }

    void swt ( int *p1 , int *p2 ){
        int tem = *p2;
        *p2  = *p1 ;
        *p1 = tem;
    }

    bool compStr(const std::string  &s1 , const std::string &s2){
            return s1.size() > s2.size();
    }

    void reset(int &val){
        val = 0;
        int const va1 = 1000;
        const int val2 = 1222;
    }

    void reset(int *val){

    }

    void fcn(const int i){} //只读 顶层const
    //void fcn(int i){}

    bool is_empty(std::string &s){return s.empty();}

    bool find_big( const std::string &s1){
        for( char v : s1){
             if(isupper(v)) return true;
        }
    }

    void change_big( std::string &s){
        for(char &cha2 : s){
            if(isupper(cha2)) {
                cha2 = tolower(cha2);
            }
        }
    }

    double calc(double);
    int count(const std::string & , char){};
    int count2(std::string &){}; //
    int count2(std::string const &){}; // 这是一个底层const不会被忽视
    int sum(std::vector<int>::iterator, std::vector<int>::iterator, int);

    //pass pointer
    // 只要是 int* 或者 const int*
    // void print(const int*);
    // void print(const int[]);
    // void print(const int[10]);

    void print(const char *s){
        if(s)
            while(*s){
                //*s = 'd';
                std::cout<< *s++ <<std::endl;
            }
    }

    void print(int (&arr)[10]){
        for( auto elem : arr)
            std::cout << elem <<std::endl;
    }

    void print(int (&arr)[2]){
        //
        // std::cout << arr[0] << arr[1] << std::endl;
    }

    void swt_pointer(int*& pt1 , int*& pt2){
        auto temp = pt1;
        pt1 = pt2;
        pt2 = temp;
    }

    //pthread（C语言实现,没有ref）

    void printt(const int ia[10]){
        for(size_t i =0 ; i != 10 ;i++){
            std::cout<< ia[i] << "ia[i]" << std::endl;
        }
    }



}



#endif //CHAPTER2_FUNCTION_H

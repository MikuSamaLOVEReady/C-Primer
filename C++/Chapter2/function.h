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

    void fcn(const int i){} //只读 顶层const 会被忽略
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


    //返回一个pointer，string(*)[10] , 指针指向数组头指针
    std::string (*f(int i))[10] {

    }

    //返沪ref string(&)[10]
    //传递的参数是数组
    std::string (&f2(std::string (&str)[10])) [10]{

    }

    void testtt(const int* be){

    }

    //返回数组指针(指向数组的pointer)
    int arr[] = {1,2,3};
    //decltype(arr) *arrPtr(int i){}
    //返回数组引用
    //decltype(arr)& arrPtr2(int i){}

    const std::string& shorterString(const std::string &s1 , const std::string &s2){

    }

    std::string& shorterString(std::string &s1, std::string &s2){
            const std::string &r = shorterString( const_cast<const std::string&>(s1),
                                            const_cast<const std::string&>(s2)
                                           );
            return const_cast<std::string&>(r);  //原本就是安全的
    }

    //int calc(int ,int ){};

    void printtt(const std::string &){};
    void printtt(double){};
    //void printtt(int){};
    void fooBar(int ival){
        //void printtt(int);
        //printtt("woc");
    }

    void default_fun(  int val , int i = 10 ){

    }


    // 这里报错是前面 width 和 height有默认值 而c没有
    //int scrren(int width = 24 , int height = 48 , char c);
    //int scrren(int width , int height , char c ='*');
    //int scrren(int width , int height , char ='g');


    //局部变量
    int ht(){
        return 10;
    }

    //


    int wd = 80;
    char def ='x';
    int screentt(int sz = funcs::ht() , int = wd , char = def){
        std::cout << sz << std::endl << wd ;
    };

    void f2(){
        def = 'S';   //全局的可以改变
        int wd = 25; //局部变量不能改变参数初始值
        int ava = screentt(); //调用 screentt( ht() , 80 ,'S')
    }

    //
    int ts(int ht , int wd=80 , char bckgrnd  = 'a'){

    }

    //constexpr fun 返回类型与参数必须是字面值
    constexpr int new_sz(){ return  42; }

    //实参是常量表达式的时候，返回值也是constexpr. 并不是给定了constexpr他返回就一定是。
    constexpr size_t scale(size_t cbt ) {
            return new_sz() * cbt;
    }

    void f1(){};
    void f1(int ){};
    void f1(int , int){};
    void f1(double , double=3.14) {};

    /*
    inline constexpr bool isShorter(const std::string &s1 , const std::string &s2){
        return s1.size() < s2.size();
    }*/

    void printt(){
    #ifndef NDEBUG
        //std::cerr << "Error: " << __FILE_NAME__ << " in function " << __func__ << std::endl;
    #endif
    }

    void manip(long);
    void manip(float);

    void manip(int, int);
    int calc(int & , int &);
    int calc(const int& , const int& );

    int calc(char* , char*);/**/
    int calc(const char* , const char*);/**/
    int calc( char *const ,  char *const);/**/

    bool lengthCompare(const std::string& , const std::string &);
    bool lengthCompare(const std::string& );

    void passarray(int* arr){
        //auto head = std::end(arr);
        std::cout << *arr++ <<std::endl;
    }









}



#endif //CHAPTER2_FUNCTION_H

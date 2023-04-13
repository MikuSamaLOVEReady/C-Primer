//
// Created by 罗瑞笛 on 2023/4/1.
//

#ifndef CHAPTER2_STRING_CHAPTER3_H
#define CHAPTER2_STRING_CHAPTER3_H

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstring>

namespace strr{
    void strrun(){
        std::string s("hello < world .");

        int pun_count = 0;
        decltype(s.size()) p = 0;
        for (auto c: s){
            if(ispunct(c))
                pun_count++;
        }
        std::cout << pun_count
                  << "punctuation characters" << s << std::endl;
    }

    void changeSTR(){
        std::string s("Hello EEE !!!");
        for(auto &c  : s){
            c = toupper(c);
        }

        //C++ 不检查index是否合法
        for( decltype(s.size()) index = 0 ; index!= s.size() && !isspace(s[index]) ;  index++){
            s[index] = toupper(s[index]); //整型提升
        }

        std::cout<< s << std::endl;
    }

    const std::string hexdigits = "0123456789ABCDEF";
    void deciToHex(){
        std::string result;
        std::cout << result[0] << std::endl;
        std::string::size_type n;
        while(std::cin >> n)
            if(n < hexdigits.size())
                result += hexdigits[n];
        std::cout << "Result" << result <<std::endl;
    }

    void initVector(){
        std::vector<int> v1; //default constructor
        std::vector<int> v4(10); // 10个做了值的初始化 的value

        std::vector<int> ivec2(v4);  // 制作了一个副本，并不是原来的. 拷贝构造
        std::vector<int> ivec3 = v4; //同上 赋值拷贝 两种是不同的constructor

        //初始化方法
        std::vector<std::string> articles = {"a" , "an", "the"};
        std::vector<int> ivec(10,-1);                   //提供了初值
        std::vector<std::string> str(10,"woc");         //
        std::vector<int> ivecc(10);                       // 如果类型有默认值，则可以只给 个数
        std::vector<std::string> v8{10,"hi"};           // 确认无法列表初始化，类型不匹配 -> 转而调用（10,"hi"）
        std::vector<int> v9{"sd", "s"};             //

        std::vector<std::vector<int>> kivec;
        //std::vector<std::string> svec = kivec;
        std::vector<std::string> svec2(10,"null");

        std::vector<int> v2;

//        for(int i=0 ; i!=100 ;i++){
//            v2.push_back(i);
//        }

        int value;
//        while(std::cin >> value){
//            v2.push_back(value);
//        }
        std::string s1;
        std::vector<std::string> s2;
//        while(std::cin >> s1){
//            s2.push_back(s1);
//        }

        std::cout << (&v4) << std::endl;
        std::cout << (&ivec2) << std::endl;
        std::cout << ivec2.size() << std::endl;

        std::cout<<"SSS"<<std::endl;
    }

    void scourCal(){
        std::vector<unsigned > scores(11,0);
        unsigned grade;
        while(std::cin>>grade){
            if(grade <= 100)
                ++scores[grade/10];
        }
    }

    void chagneToBig(){
        std::string s;
        std::vector<std::string> s1;
        while(std::cin >> s){
            s1.push_back(s);
        }

        for(int i = 0 ; i< s1.size() ; i++){
            for(char &c : s1[i]){
                c = toupper(c);
            }
        }
        std::cout<<"ddd";
    }

    void _t3_19(){
        int val;
        std::vector<int> intva;
        while(std::cin >> val){
            intva.push_back(val);
        }

        int mid = -1;
        //中间时停止 得分奇偶
        if( (intva.size()%2) == 0 ){
            mid = (intva.size()-1)/2 + 1;
        }
        else{
            mid = (intva.size()-1)/2 ;
        }

        for(int i=0 ; i< intva.size() ; i++){
//            if( i+1 != intva.size())
//            {
//                std::cout << intva[i] + intva[i+1] << std::endl;
//            }

            if( i < mid ){
                std::cout << intva[i] + intva[intva.size()-i-1] << std::endl;
            }
        }

    }

    void _itera(){
        std::string sss("some string deewf");
        std::string sssempty;
        std::string sss2("soKe string");
        std::vector<std::string> strvec = {sss, sss2, sssempty};
        auto iter = strvec.begin();
        while(iter != strvec.end() && !iter->empty()) {
            std::cout<< *iter << std::endl;
            iter++;
        }

        auto cit = sss.cbegin();
        auto itsss =   sss.begin() + 1;
        auto itsss2 =   sss.begin() + 1;
        if(itsss == itsss2 )
            std::cout<<"SAME!!" << std::endl;
        else
            std::cout<<"DIFF!!" << std::endl;

        if(sss.begin() != sss.end()){
            auto it = sss.begin();
            *it = toupper(*it); //可以类似指针做deref
        }
        std::vector<int>::iterator  it;
        std::vector<int>::const_iterator c_it; //read_only

        //for (cit ; cit != sss.cend() && cit-> ; ++cit )
    }

    void _itevector(){
        std::vector<int> v2(10);
        auto it = v2.begin();
        while(it!=v2.end()){
            std::cout << *it << std::endl;
            it++;
        }
    }

    void _doubleValue(){
        std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
        for(auto it = v.begin() ; it!=v.end() ; it++){
            *it *= 2;
        }
        for(auto one : v){
            std::cout<< one <<std::endl;
        }
    }

    void _iterCount(){
        std::vector<int> v = {1,2,4,3};
        auto begin = v.begin();
        auto end = v.end();
        std::cout << begin - end <<std::endl; // begin
        auto mid = v.begin() + v.size()/2;
        std::cout << *mid<<std::endl; // begin
    }

    void _binarySearch( int target){
        std::vector<int> v = {1,2,4,3,5};
        auto begin = v.begin() , end = v.end();
        auto mid = begin + (end - begin)/2;
        while( *mid != target && mid!= end){
            if(*mid <target){
                begin = mid + 1 ; //由于已经判断了mid不是我们要的内容，顾跳过
            }else{
                end = mid ; //end本身就表示一个范围最后一个数的下一个。
            }
            mid = begin + (end - begin)/2;
        }
    }

    void _scoureCount(){
        int val;
        int move;
        std::vector<int> count (10,0);
        while(std::cin >> val){
           if(val <= 100){
               move = val/10;
               auto it = count.begin() + move;
               (*it)++;
           }
        }

        std::cout << count[0] << std::endl;
    }

    void _initArray(){
        int arr[] = {1,2,3};
        char a1[] = {'C', '+','+'}; //没有空字符
        char a2[] = {'C', '+','+','\0'};
        char a3[] = "C++";  //有空字符

        int (*ptr)[3] = &arr;
        int (&ptrr)[3] = arr;

        for(auto i : arr){
            std::cout<< i << std::endl;
        }

        std::cout << (*ptr)[0] << std::endl;
        std::cout << (*ptr)[1] << std::endl;
        std::cout << (*ptr)[2] << std::endl;

        std::cout << arr[0] << std::endl;
    }

    void _getVal(){
        constexpr size_t array_size = 10; //size_t unsigned int
        int array[array_size];
    }

    void  _ArrayPtr(){

        std::string nums[] = {"one", "two", "three"};
        std::string *ptr = &nums[0];
        std::string *ptr2 = nums; //数组名被转成
        std::string *beginptr = std::begin(nums);
        std::string *endptr = std::end(nums);
        while(beginptr != endptr){
            std::cout << *beginptr << std::endl;
            beginptr ++;
        }

    }

    void _CompPtr(){
        int arr1[] = {1,2,3,4};
        int *p = arr1;
        int *p2 = arr1 + 2;
        if(p < p2){
            std::cout<< "SSSSS" <<std::endl;
        }
    }

    void _ptr_move(){
        constexpr size_t sz =5;
        int arr[sz] = {1,2,3,4,5};
        int *ip = arr;
        int *ip2 = ip + 4;
        auto n = std::begin(arr) - std::end(arr); //输出 = 5
        int *b = arr, *e = arr + sz; //e指向了末尾
        while(b<e) {
            ++b;
        }
    }

    void _ptr_move2(){
        int arry[5] = {0,1,2,3,4} ;
        int *p = &arry[2];
        int p1 = p[-1]; // arry[2-1] = arr[1]
        int p2 = p[2]; //  arry[2+2] = arr[4]
        std::cout << p1  << "woc" << p2 <<std::endl;
    }

    void _ptr_minus(){
        int arry[] = {} ;
        int *p1 = &arry[4];
        int *p2 = arry;
        std::cout << p2 - p1  <<std::endl; //预计=4
        p1 += p2 - p1; //p1指向 p2
        std::cout << *p1 <<std::endl; //预计=4
    }

    void _all_zero(){
        int arr[] = {1,2,3,4,5};
        int* arr_begin =  std::begin(arr);
        int* arr_end =  std::end(arr);
        while(arr_begin != arr_end ){
            *arr_begin = 0;
            arr_begin++;
        }
        for(int i = 0 ; i < 5 ;i++){
            std::cout<< arr[i] <<std::endl;
        }
    }

    bool _compareVector(){
       int arr[] = {1,2,3,4};
       int arr2[] = {1,3,3};

       int * const b1 = arr;
       int * const b2 = arr2;
       int * const end1 = std::end(arr);
       int * const end2 = std::end(arr2);

       for(int *i = b1 , *i2 =b2 ; i<end1 && i2<end2  ;++i,++i2 ){
           if( (end1 - b1) != (end2 - b2) ){
               std::cout << "false" << std::endl;
               return false;
           }
           else{
               if(*i != *i2) {
                   std::cout << "false" << std::endl;
                   return false;
               }
           }
       }
       return true;
    }

    void c_str(){
        char  ca[] = {'C', '+','+', '\0'}; // '\0'
        std::cout << strlen(ca) <<"lenth" << std::endl;

        const char a[] = {'h', 'e', 'l', 'l' ,'o'}; //没有'\0'结尾
        const char *cp = a;
        while(*cp){
            std::cout << *cp << std::endl;
            ++cp;
        }
    }

    void c_str_string(){
        const char a[] = {'h', 'e', 'l', 'l' ,'o','\0'}; //没有'\0'结尾
        char a2[] = {'w','2','2','\0'};
        std::string s1 = a; //std::string可以用 char[]构造。
        s1 += a2; // std::string 可以+= 一个char[]
        std::string s2 = s1 + a2; //或者 std::string + char[]
        std::cout << s2 <<std::endl;
        std::string s2s = "woc";
        const char *ch2 = s2s.c_str();
        s2s[0] = 'D';
        std::cout << s2s <<std::endl;
        std::begin(s2s);
        std::cout << ch2 <<std::endl; //
    }

    void c_modify(std::string &str){
        str += " worldfasfsdfagadgagargernana";
        const char* ptr = str.c_str();
        std::cout << "c_str() resturns "<< ptr << std::endl;
    }

    void c_stirngModify(std::string &str){
        str.reserve(100);
        const char* ptr = str.c_str();
        std::cout << "c_str() resturns "<< ptr << std::endl;
    }

    void c_stirng_char(){
        std::string hello = "hello";
        const char* ptr = hello.c_str(); //取到一个pointer 指向了string
        c_stirngModify(hello);  // string是动态分配的内存，可能
        std::cout << "c_str() returns: " << ptr << std::endl;
    }


    void arry_to_vector(){
        int in_arr[] = {0,1,2,3,4,5};
        std::vector<int> ivec(std::begin(in_arr), std::end(in_arr));
        std::vector<int> ivec2(std::begin(in_arr)+1, std::end(in_arr)-2);
        std::cout << "c_str() returns: " << std::endl;
    }

    void arry_copy(std::vector<int> &v){
        int *array = (int*)malloc(v.size()*sizeof(int)); //malloc返回一个void*
        int index = 0;
        for(int it : v){
            array[index] = it;
            std::cout << array[index] <<std::endl;
            index++;
        }
        //std::cout << array[100] <<std::endl;
    }

}



#endif //CHAPTER2_STRING_CHAPTER3_H

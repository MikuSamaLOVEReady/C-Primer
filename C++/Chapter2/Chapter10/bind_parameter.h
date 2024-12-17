//
// Created by 罗瑞笛 on 2023/7/31.
//

#ifndef CHAPTER7_BIND_PARAMETER_H
#define CHAPTER7_BIND_PARAMETER_H

#include <functional>

bool check_size(const string& s, string::size_type sz) {
    return s.size() > sz;
}

void print_new(int a , int b ){
    std::cout << "a: " << a << "b: " <<  b << std::endl;
}

void find_string(const string& s){

    //像是adapter，修改了一个接受两个参数的函数 -> 使得函数变成接受一个参数的callablwe
    auto new_callable = bind(check_size,placeholders::_1, 6);
    string s1 = "woc";
    auto re = new_callable(s1);

    vector<string> vec{ "a", "ddddddddd", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    auto result = find_if(vec.begin(), vec.end(),new_callable);
    auto result2 = find_if(vec.begin(), vec.end(),bind(check_size,placeholders::_1,10));
    std::cout << "woc" ;
}

//place holder
void place_hold(vector<string>& vec){
    //auto 对
    sort(vec.begin(), vec.end() , bind(isShorter, placeholders::_2 ,placeholders::_1));
}

ostream& print_myos(std::ostream& os , const string &s , char c){
    return os << s <<c;
}

bool find_les_six(const string& s , ::size_t sz){
    return s.size() < sz;
}

void fun_10_22(vector<string>& s , ::size_t sz ){
    //一元谓词
    count_if(s.begin() , s.end() , [sz](const string& s) -> bool{
       return s.size() < sz;
    });

    count_if(s.begin(), s.end() , bind(find_les_six,placeholders::_1 ,6));
}


void bind_learn(){

    auto print_with_b_10 = std::bind(print_new, std::placeholders::_1, 10);
    /// 这种跳过了placement1 的就会报错，调用的时候
    /// auto print_with_jump = std::bind(print_new, std::placeholders::_2, 10);
    auto new_ptr = std::bind(print_new, std::placeholders::_2, std::placeholders::_1);
    new_ptr(5,10);  /// 传递的参数按顺序 分别对应placeholder1 ... 2 ... 3 这样
    print_with_b_10(99);
    //    print_with_jump(99);
}







#endif //CHAPTER7_BIND_PARAMETER_H

//
// Created by ����� on 2023/7/31.
//

#ifndef CHAPTER7_BIND_PARAMETER_H
#define CHAPTER7_BIND_PARAMETER_H

#include <functional>

bool check_size(const string& s, string::size_type sz) {
    return s.size() > sz;
}

void find_string(const string& s){

    //����adapter���޸���һ���������������ĺ��� -> ʹ�ú�����ɽ���һ��������callablwe
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
    //auto ��
    sort(vec.begin(), vec.end() , bind(isShorter, placeholders::_2 ,placeholders::_1));
}

ostream& print_myos(std::ostream& os , const string &s , char c){

    return os << s <<c;
}

bool find_les_six(const string& s , ::size_t sz){
    return s.size() < sz;
}

void fun_10_22(vector<string>& s , ::size_t sz ){

    //һԪν��
    count_if(s.begin() , s.end() , [sz](const string& s) -> bool{
       return s.size() < sz;
    });

    count_if(s.begin(), s.end() , bind(find_les_six,placeholders::_1 ,6));
}









#endif //CHAPTER7_BIND_PARAMETER_H

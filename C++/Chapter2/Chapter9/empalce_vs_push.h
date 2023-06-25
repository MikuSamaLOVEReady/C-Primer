//
// Created by 罗瑞笛 on 2023/6/17.
//

#ifndef CHAPTER7_EMPALCE_VS_PUSH_H
#define CHAPTER7_EMPALCE_VS_PUSH_H

class mytest{
public:
    inline mytest(int myval , string str):sal(myval), mytr(str){};

private:
    int sal;
    string mytr = "null";

};

class Sandbox
{
public:
    Sandbox(const string& n) : member(n) {}
    const string& member;
};


void fuc_9_20(){
    list<int> mylist = {1,2,3,4,5};
    deque<int> deque1 , deque2;
    auto it = mylist.begin();
    while( it !=mylist.end()){
       if( (*it) % 2 == 0) {
            deque1.push_back(*it);
       }else{
           deque2.push_back(*it);
       }
        ++it;
    }

    std::cout << "end" <<std::endl;
    return;
}

void fuc_9_21(){
    list<int> mylist = {1,2,3,4,5};
    vector<int> vec1 , vec2;
    auto it = mylist.begin();
    auto vec1_it = vec1.begin();
    auto vec2_it = vec2.begin();

    while( it !=mylist.end()){
        if( (*it) % 2 == 0) {
           vec1_it = vec1.insert(vec1_it , *it); //类似头插入
        }else{
            vec2_it = vec2.insert(vec2_it , *it); //类似头插入
        }
        ++it;
    }
    std::cout << "end" <<std::endl;
    return;
}

void fuc_9_22(){
    // 边插入边用->出错
    vector<int> iv = {1,2,3,4 ,1,1, 1 ,1,1,1};
    auto iter = iv.begin();
    auto mid = iv.begin() + iv.size()/2;

    while(iter != mid)
    {
        if(*iter == 1){
            iv.insert(iter,2*2);
        }
        ++iter;
    }
    std::cout << "end" <<std::endl;
    return;
}

void fuc_9_26(){
    int ia[] = {0, 1 , 1,2,3,5,8,13,21,55,89};
    list<int> list1;
    vector<int> vet1;
    for(int va : ia){
        list1.push_back(va);
        vet1.push_back(va);
    }

    auto it = list1.begin();
    auto it_list_end = --list1.end();

    auto it_v   = vet1.begin();
    auto it_end = vet1.end()-1;
    while( it_v != vet1.end()){ //这里的vet1 大小缩小，关键是所在空间并没有转移，所以end()iterator能够一直有效绑定到末尾
        if( (*it_v)%2 == 0 ) it_v = vet1.erase(it_v);
        else ++it_v;
    }

    //同上，依然有效
    while(it != list1.end()){
        if( (*it)%2 != 0 ) it = list1.erase(it);
        else ++it;
    }

    std::cout << "end" <<std::endl;
    return ;
}

void fun_9_32(){
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while(iter != vi.end()){
        //iter只加了一次？ 先返回一个iter的复制品，insert返回后更新iter后再+1？ yes, 并且在内部的*it++不起作用
        iter = vi.insert(iter,*iter++);
        std::cout << "out put" << *iter << std::endl;
        ++iter;
    }
}

void fun_9_33(){
    vector<int> vi = {0};
    auto begin = vi.begin();
    while(begin != vi.end()){
        ++begin;
        vi.insert(begin,42);
        ++begin;
    }
    return;
}


// 我的capacity和size有点不一样
void fun_9_34(){
        vector<int> custom = {1,2,3,4,5};
        custom.resize(1024);
        //custom.reserve(30);
        std::cout << custom.capacity() << std::endl;
        custom.shrink_to_fit(); //不一定返还
        std::cout << custom.capacity() << std::endl;
}

//
void fun_9_35(){
    char str[] = {'m','k','s','m','5','2','0'}; // 不是以空字符结尾
    char str_nullend[] = {'m','k','s','m','5','2','0','\0'}; //以空字符结尾
    const char* str_nullenf = "woc"; //C++ 11不允许   字符串字面值 赋值给 char*

    string s1 = "miku sama";
    string s_array_copy(str,4);     //复制str指向开始的前4个元素
    string s_null (str);               //未定义
    string s_string_copy(s1,5);  //从stirng的下标5开始复制到结尾【包括【5】】
    string s_string_copy_2(s1,5,2);  //从stirng的下标5开始复制2个元素，如果过大则不超过结尾
    string s2 = s1.substr();
    std::cout << s2 << std::endl;
}

void fun_9_41(){
    vector<char> v_cha = {'a','b','c'};
    string s1 (v_cha.cbegin(), v_cha.cend());
    std::cout << s1 <<std::endl;
}

void fun_9_42(){
    std::string s; //被理解为函数声明
    s.reserve(100);
}

void change_string(){
    string s = "aka";
    //string 独有
    s.insert(s.size(),5,'!'); //接受下标, pos表示第一个插入的位置
    s.erase(s.size(),5);  // pos表示删除的位置（删除时包括该index上的元素）

    const char* cp = "Stately, pump Buck";
    string ss;
    ss.assign(cp,7); //从哪个 const string中获取数值，获取多少个？
    ss.insert(s.size() , cp+7);    // 从pos所给的index位置之前，开始插入cp+7所指向的元素
}

void stirng_append_replace(){


}

void string_erasetest(){
    string s = "mikusama";
    auto it = s.erase(s.begin()+3 , s.end());
    if(it == s.end()) {
        std::cout << s  << std::endl;
    }
}

void string_insert(){
    string s = "mikusama";
    string s2 = "LRD";
    auto it = s.insert(s.begin()+3 , s2.begin() , s2.end());
    std::cout << *it <<std::endl;
}

void fun_9_43(string& s , const string& oldVal , const string& newVal){
    //这里单独保存begin问题不大吧
    auto cur = s.begin();
    //
    while( cur <= s.end() - oldVal.size() ){
        //前闭后开,直接构造临时变量
        if(oldVal == string{cur , cur+oldVal.size()}){
            //abcd -> ad
            cur = s.erase(cur , cur+oldVal.size() ); //删除的也是前闭后开范围, 返回最后一个删除的下一个位置
            cur = s.insert(cur,newVal.begin(), newVal.end());
            cur += newVal.size();
        }
        else{
            ++cur;
        }
    }
}

void fun_9_44(string& s , const string& oldVal , const string& newVal){
    int i = 0;
    // "abcd" cd  size - oldcout
    while( i <= s.size() - oldVal.size() ){
        //这个搜索操作确实ok
        if( oldVal == s.substr(i,oldVal.size()) ){
            s.replace(i,oldVal.size() , newVal);
            i += newVal.size();
        }
        else{
            ++i;
        }
    }
}

string fun_9_45(string& s , const string& front , const string& end){
    s.insert(s.begin(), front.cbegin() , front.cend());
    return  s.append(end);
}

string fun_9_46(string& s , const string& front , const string& end){
    s.insert(0, front);
    return s.insert(s.size(),end);;
}

void find_str(){
    string s = "05678str";
    string numbers = "0123456789";
    int id = s.find_first_not_of(numbers);
    int id_2 = s.find_first_of(numbers);
    std::cout << s <<std::endl;
}

void fun_9_47(){
    string s1 = "ab2c3d7R4E6";
    string numbers = "0123456789";
    string chara = "zxcdvbnmasdfghjklqwertyuiopZXCVBNMASDFGHJKLQWERTYUIOP";
    string::size_type pos = 0;
    while( (pos = s1.find_first_of(numbers,pos)) != string::npos ){
            std::cout << s1[pos] << std::endl;
            ++pos;
    }
    pos = 0;
    while((pos = s1.find_first_of(chara,pos)) != string::npos ){
        std::cout << s1[pos] << std::endl;
        ++pos;
    }
}

//
void fun_changeString(){
    int  i = 42;
    string s = to_string(i);
    double d = stod(s);
}





#endif //CHAPTER7_EMPALCE_VS_PUSH_H

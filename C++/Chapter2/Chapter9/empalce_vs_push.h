//
// Created by ����� on 2023/6/17.
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
           vec1_it = vec1.insert(vec1_it , *it); //����ͷ����
        }else{
            vec2_it = vec2.insert(vec2_it , *it); //����ͷ����
        }
        ++it;
    }
    std::cout << "end" <<std::endl;
    return;
}

void fuc_9_22(){
    // �߲������->����
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
    while( it_v != vet1.end()){ //�����vet1 ��С��С���ؼ������ڿռ䲢û��ת�ƣ�����end()iterator�ܹ�һֱ��Ч�󶨵�ĩβ
        if( (*it_v)%2 == 0 ) it_v = vet1.erase(it_v);
        else ++it_v;
    }

    //ͬ�ϣ���Ȼ��Ч
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
        //iterֻ����һ�Σ� �ȷ���һ��iter�ĸ���Ʒ��insert���غ����iter����+1�� yes, �������ڲ���*it++��������
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


// �ҵ�capacity��size�е㲻һ��
void fun_9_34(){
        vector<int> custom = {1,2,3,4,5};
        custom.resize(1024);
        //custom.reserve(30);
        std::cout << custom.capacity() << std::endl;
        custom.shrink_to_fit(); //��һ������
        std::cout << custom.capacity() << std::endl;
}

//
void fun_9_35(){
    char str[] = {'m','k','s','m','5','2','0'}; // �����Կ��ַ���β
    char str_nullend[] = {'m','k','s','m','5','2','0','\0'}; //�Կ��ַ���β
    const char* str_nullenf = "woc"; //C++ 11������   �ַ�������ֵ ��ֵ�� char*

    string s1 = "miku sama";
    string s_array_copy(str,4);     //����strָ��ʼ��ǰ4��Ԫ��
    string s_null (str);               //δ����
    string s_string_copy(s1,5);  //��stirng���±�5��ʼ���Ƶ���β��������5����
    string s_string_copy_2(s1,5,2);  //��stirng���±�5��ʼ����2��Ԫ�أ���������򲻳�����β
    string s2 = s1.substr();
    std::cout << s2 << std::endl;
}

void fun_9_41(){
    vector<char> v_cha = {'a','b','c'};
    string s1 (v_cha.cbegin(), v_cha.cend());
    std::cout << s1 <<std::endl;
}

void fun_9_42(){
    std::string s; //�����Ϊ��������
    s.reserve(100);
}

void change_string(){
    string s = "aka";
    //string ����
    s.insert(s.size(),5,'!'); //�����±�, pos��ʾ��һ�������λ��
    s.erase(s.size(),5);  // pos��ʾɾ����λ�ã�ɾ��ʱ������index�ϵ�Ԫ�أ�

    const char* cp = "Stately, pump Buck";
    string ss;
    ss.assign(cp,7); //���ĸ� const string�л�ȡ��ֵ����ȡ���ٸ���
    ss.insert(s.size() , cp+7);    // ��pos������indexλ��֮ǰ����ʼ����cp+7��ָ���Ԫ��
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
    //���ﵥ������begin���ⲻ���
    auto cur = s.begin();
    //
    while( cur <= s.end() - oldVal.size() ){
        //ǰ�պ�,ֱ�ӹ�����ʱ����
        if(oldVal == string{cur , cur+oldVal.size()}){
            //abcd -> ad
            cur = s.erase(cur , cur+oldVal.size() ); //ɾ����Ҳ��ǰ�պ󿪷�Χ, �������һ��ɾ������һ��λ��
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
        //�����������ȷʵok
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

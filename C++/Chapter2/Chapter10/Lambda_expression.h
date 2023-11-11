//
// Created by 罗瑞笛 on 2023/7/30.
//

#ifndef CHAPTER7_LAMBDA_EXPRESSION_H
#define CHAPTER7_LAMBDA_EXPRESSION_H

//

void labda_test(){
    void (*f)() = [] {};
    auto f2 = [] {};

    //is short
    [](const string &a , const string& b){
        return a.size() < b.size();
    };

    vector<string> ve;
    stable_sort(ve.begin(),ve.end(),
                [](const string &a , const string& b){
                    return a.size() > b.size();}
                    );
}

void bigges(vector<string> &words , vector<string>::size_type sz){
    elimDups(words);
    auto wc = find_if(words.begin(), words.end() ,
                      [sz](const string& a){
                return a.size() >= sz;
    });

    for_each(wc , words.end(),[](const string& s) ->void {
        std::cout<< s << std::endl;
    });

}

void fun_10_14(){
    auto f = [] (int a, int b) ->int {
        return a+b;
    };
    int a[10] = {1,2,3,4,5};
    int b[sizeof(a)/sizeof(*a)];
    auto ret = copy(begin(a), end(a),b);
    std::cout << "woc" << std::endl;
}

void fun_10_15(){

    int value  = 17;
    auto f2 = [value] (int i) -> int {
        return value + i;
    };

    std::cout << f2(55) <<std::endl;
    return;
}

void fun_10_17(vector<Sales_data>& sdata_vec){
        sort(sdata_vec.begin() , sdata_vec.end() , [](Sales_data& s1 , Sales_data& s2){
                return s1.isbn() < s2.isbn();
        });
}

void fun_10_18(vector<string>& vec , std::size_t sz){
    partition(vec.begin(), vec.end(),[sz](const string& s){
        return s.size() >= sz;
    });
}

void fun_10_19(vector<string>& vec , std::size_t sz){
    stable_partition(vec.begin(), vec.end(),[sz](const string& s){
        return s.size() >= sz;
    });
}

void value_copy(){
    ::size_t  v1 = 42;
    //在创建时确定被捕获的值
    auto f = [v1] {
        return v1;
    };
    v1 = 100;
    auto j = f();



    std::cout << j << std::endl;
}

void ref_copu(){
    ::size_t  v1 = 66;
    auto f = [&v1] {
        return v1;
    };
    v1 = 100;
    auto j = f();
    std::cout << j <<std::endl;
}

void biggest(vector<string> &words , vector<string>::size_type sz, ostream &os = cout , char c =' '){
    for_each(words.begin(), words.end() , [&os , c](const string&s ){
        os << s << c;
    });
}

void shadow_lamb(vector<string> &words , vector<string>::size_type sz){
    auto wc = find_if(words.begin() , words.end() , [=](const string& s){
        return s.size()>sz;
    });
}

void merge_lamb(vector<string> &words , vector<string>::size_type sz
                 ,  std::ostream& os , char c = ' '){
    for_each(words.begin(), words.end(), [&, c] (const string& s) {
            os << c << s;
    });

    for_each(words.begin(), words.end() , [=, &os](const string& s){
             os << c << s;
    });
}

void fcn3(){
    ::size_t v1 = 42;
    auto f = [v1] () mutable ->int  {return ++v1;};
    std::cout << f() << std::endl;
    std::cout << v1  << std::endl;
}

void fuc4(){
    const ::size_t v1 = 42;
    //auto f = [&v1] {return ++v1;};
}

void rever_nage(vector<int>& vec){
    transform(vec.begin(), vec.end(),vec.begin(), [](int i) {
         if(i<0) return -i ;
         else return i;
    });
}

int cont_if(vector<string>& str){
    int number = 0;
    //一元谓词
    auto res = count_if(str.begin(),str.end(),[](const string& s) {
        return s.size()>6 ;
    });
    return res;
}


int fun_10_21(int value){

    [&value]() -> bool {
        if(value == 0) return true;
        while(value) --value;
        return false;
    };

    int i = 7;
    auto check_and_decrement = [&i](){ return --i ? false : true; };
    std::cout << "ex10.21: ";
    while(!check_and_decrement())
        std::cout << i << " ";
}









#endif //CHAPTER7_LAMBDA_EXPRESSION_H

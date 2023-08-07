//
// Created by 罗瑞笛 on 2023/7/30.
//

#ifndef CHAPTER7_SEND_FUNC_TO_ALGORITHM_H
#define CHAPTER7_SEND_FUNC_TO_ALGORITHM_H

//前向声明
bool isShorter(const string& s1, const string& s2);
void custmized_sort(vector<string>& words);
bool is_Les( const Sales_data& sales_1 , const Sales_data& sales_2);
//bool less_5(int counter);
bool less_5(const string &s);

void elimDups(vector<string>& words){
    //按照字典序 排序
    sort(words.begin() , words.end());
    //按照长度排序
    custmized_sort(words);
}

//实现字符串 1.先按照长度排序 2.长度相同再按照字典排序
void custmized_sort(vector<string>& words){
    //传递一个callabl给算法
    stable_sort(words.begin(), words.end(), &isShorter);
}

//为true的时候，被排序在前
bool isShorter(const string& s1, const string& s2){
    return s1.size() > s2.size();
}

bool Sales_data_Comparing(vector<Sales_data>& sales_vec){
    sort(sales_vec.begin() , sales_vec.end() , is_Les);
}

//这是一个二元谓词
bool is_Les( const Sales_data& sales_1 , const Sales_data& sales_2){
    return sales_1.isbn() < sales_2.isbn();
}


//长度小于5的都放前面
bool less_5(const string &s){
    return s.size() < 5;
}


bool predicate(const std::string &s)
{
    return s.size() < 5;
}



#endif //CHAPTER7_SEND_FUNC_TO_ALGORITHM_H

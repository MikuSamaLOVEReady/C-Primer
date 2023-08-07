//
// Created by ����� on 2023/7/30.
//

#ifndef CHAPTER7_SEND_FUNC_TO_ALGORITHM_H
#define CHAPTER7_SEND_FUNC_TO_ALGORITHM_H

//ǰ������
bool isShorter(const string& s1, const string& s2);
void custmized_sort(vector<string>& words);
bool is_Les( const Sales_data& sales_1 , const Sales_data& sales_2);
//bool less_5(int counter);
bool less_5(const string &s);

void elimDups(vector<string>& words){
    //�����ֵ��� ����
    sort(words.begin() , words.end());
    //���ճ�������
    custmized_sort(words);
}

//ʵ���ַ��� 1.�Ȱ��ճ������� 2.������ͬ�ٰ����ֵ�����
void custmized_sort(vector<string>& words){
    //����һ��callabl���㷨
    stable_sort(words.begin(), words.end(), &isShorter);
}

//Ϊtrue��ʱ�򣬱�������ǰ
bool isShorter(const string& s1, const string& s2){
    return s1.size() > s2.size();
}

bool Sales_data_Comparing(vector<Sales_data>& sales_vec){
    sort(sales_vec.begin() , sales_vec.end() , is_Les);
}

//����һ����Ԫν��
bool is_Les( const Sales_data& sales_1 , const Sales_data& sales_2){
    return sales_1.isbn() < sales_2.isbn();
}


//����С��5�Ķ���ǰ��
bool less_5(const string &s){
    return s.size() < 5;
}


bool predicate(const std::string &s)
{
    return s.size() < 5;
}



#endif //CHAPTER7_SEND_FUNC_TO_ALGORITHM_H

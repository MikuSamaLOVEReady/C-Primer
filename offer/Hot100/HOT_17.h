//
// Created by ����� on 2024/2/27.
//

#ifndef OFFER_HOT_17_H
#define OFFER_HOT_17_H

#include <string>
#include <vector>
#include <unordered_map>


class Solution_17 {
public:

    vector<string> res;
    /// ʣ���ַ��� �� ��ǰ�����е��ַ���
    void find_all_pair( vector<string>& groups , string& cur_str)
    {
        /// �˳���������ʾ��ǰ�����һ���ַ���ѡ
        if(groups.size() == 1){
            for(char& ch : groups[0])
            {
                res.push_back(cur_str + ch);
            }
            return;
        }

        /// �ݹ�ѭ��
        vector<string> sub_group( groups.begin()+1 , groups.end() );
        for(char i : groups[0])
        {
            //cur_str += i;
            string tem_str = cur_str+i;
           find_all_pair( sub_group , tem_str);
        }

    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        /// <  key = char , value = string >
        unordered_map< char , string >  str_dict;
        str_dict.insert(make_pair('2', "abc"));
        str_dict.insert(make_pair('3', "def"));
        str_dict.insert(make_pair('4', "ghi"));
        str_dict.insert(make_pair('5', "jkl"));
        str_dict.insert(make_pair('6', "mno"));
        str_dict.insert(make_pair('7', "pqrs"));
        str_dict.insert(make_pair('8', "tuv"));
        str_dict.insert(make_pair('9', "wxyz"));

        vector<string> str_groups;
        for(const char ch : digits)
        {
            string str = str_dict.at(ch);   /// ���û�ҵ����׳��쳣 ����û�����find��
            str_groups.push_back(str);
        }

        string s = "";
        find_all_pair(str_groups , s);
        return res;
    }
};



#endif //OFFER_HOT_17_H

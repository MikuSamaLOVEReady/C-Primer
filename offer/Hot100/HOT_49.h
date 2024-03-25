//
// Created by ����� on 2024/3/8.
//

#ifndef OFFER_HOT_49_H
#define OFFER_HOT_49_H

#include <map>
#include <numeric>
#include <array>

class Solution_49 {
public:

    vector<vector<string>> res;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //for( auto it = strs.begin() ; it!=strs.end() ;++it)
        while( !strs.empty()  )
        {
            auto it = strs.begin(); ///�������Ҳȷʵɧ
            map<char , int> cur_test{};
            /// ÿ�δ��г�ȡʣ��� string - ͳ���ַ�����
            for( const char& ch : *it)
            {
                if( cur_test.find(ch) == cur_test.end() ){
                    cur_test[ch] = 1;
                }
                else{
                    cur_test[ch] += 1;
                }
            }

            vector<string> s_group;
            s_group.push_back(std::move(*it));  ///���뱾���һ���ַ���
            strs.erase(it);

            /// ��ʼ����ʣ���ַ���
             for(auto sub_it = it ; sub_it != strs.end() && !strs.empty();)
            /// while( !strs.empty()  )
            {

                 /// ���⴦�������ͷ�ַ���==""
                 if ( (*(s_group.begin())).empty()  )
                 {
                     if( (*sub_it).empty() ) {
                         s_group.push_back(std::move(*sub_it));
                         strs.erase(sub_it);
                         continue;
                     }
                     else{
                         ++sub_it;
                         continue;
                     }
                 }

                //auto sub_it = strs.begin(); ///�������Ҳȷʵɧ
                bool not_has = false;
                map<char , int> temp(cur_test); /// ����һ�ݱ����ͷ���ַ���
                for( const char& sub_ch : *sub_it)
                {
                    if(temp.find(sub_ch) == temp.end()) {
                        /// ������û�����ĸ ��һ��-1
                        not_has = true;
                        break;
                    }
                    else{   /// ����и���ĸ������������ȷ
                        temp[sub_ch] -=1;
                        if( temp[sub_ch] < 0 ) break;
                    }
                }

                if(not_has) {
                    ++sub_it;
                    continue;
                }

                /// ���temp�л���ʣ�ࡢ��Ҳ������������ ����������������ļ��
                bool is_ans = true;
                for( const auto& pair : temp )
                {
                    if(pair.second != 0 ) {
                        is_ans = false;
                        break;
                    }
                }
                if(is_ans ) {
                    s_group.push_back(std::move(*sub_it));
                    strs.erase(sub_it);
                }
                else{
                    ++sub_it;
                }
            }

            res.push_back(s_group);
        }
        return res;
    }


    void test_move_vector(){
        string s1 = "af";
        string s2(std::move(s1));

        std::vector<std::string> source = {"one", "two", "three", "four", "five"};
        std::vector<std::string> destination;

        destination.push_back(std::move(source[0]));     /// ��ֵRef���졢���
        source.erase(source.begin());               /// ����

        std::cout << ">>>" << std::endl;

    }

    void erase_it_test(){
        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it = vec.begin();
        auto it_3 = vec.begin()+2;
        vec.erase(vec.begin()); // �Ƴ���һ��Ԫ��
        std::cout<< *it  << std::endl ; // ����ʧЧ�ĵ����� ������δ���塢��������ֵ
        test_move_vector();
        std::cout<< *it_3  << std::endl ; // ����ʧЧ�ĵ�����
        *it = 114;
        *it_3 = 155;
        std::cout << "stock_2"  << std::endl ;
    }

    vector<vector<string>> groupAnagrams_test (vector<string>& strs) {

        auto arrayHash = [ fn = hash<int>{} ] (const array<int , 26>& arr) -> size_t {
            return accumulate(arr.begin() , arr.end() , 0u , [&](::size_t acc , int num){
              return (acc << 1)^ fn(num);
            });
        };

        /// array<int , 26>   ����array
        /// lambda���ʽ �� �������ͣ��޷���ȡ����typeֻ�� ͨ��decltypeʵ��
        unordered_map< array<int , 26> , vector<string> , decltype(arrayHash) > mp(0,arrayHash);  /// ����ѡ��hash����
        /// ÿ�ζ����������
        for( const string& str : strs){
            array<int , 26> counts{};
            int length = str.size();
            for(int i = 0 ; i<length ; ++i){
                counts[str[i] - 'a'] += 1;
            }
            mp[counts].emplace_back(str);       /// ӵ����ͬ�������ַ����ᱻ ����hash���ͬһ��key��
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin() ; it != mp.end() ; ++it)
        {
            ans.push_back(it->second);
        }

        return ans;
    }



};

#endif //OFFER_HOT_49_H

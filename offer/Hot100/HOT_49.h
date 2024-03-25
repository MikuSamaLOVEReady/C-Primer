//
// Created by 罗瑞笛 on 2024/3/8.
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
            auto it = strs.begin(); ///这个操作也确实骚
            map<char , int> cur_test{};
            /// 每次从中抽取剩余的 string - 统计字符个数
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
            s_group.push_back(std::move(*it));  ///加入本组第一个字符串
            strs.erase(it);

            /// 开始遍历剩余字符串
             for(auto sub_it = it ; sub_it != strs.end() && !strs.empty();)
            /// while( !strs.empty()  )
            {

                 /// 特殊处理、如果排头字符串==""
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

                //auto sub_it = strs.begin(); ///这个操作也确实骚
                bool not_has = false;
                map<char , int> temp(cur_test); /// 复制一份本组的头号字符串
                for( const char& sub_ch : *sub_it)
                {
                    if(temp.find(sub_ch) == temp.end()) {
                        /// 根本就没这个字母 藏一个-1
                        not_has = true;
                        break;
                    }
                    else{   /// 如果有该字母、但个数不正确
                        temp[sub_ch] -=1;
                        if( temp[sub_ch] < 0 ) break;
                    }
                }

                if(not_has) {
                    ++sub_it;
                    continue;
                }

                /// 如果temp中还有剩余、则也不符合条件。 在这里做所有情况的检查
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

        destination.push_back(std::move(source[0]));     /// 右值Ref构造、清空
        source.erase(source.begin());               /// 西沟

        std::cout << ">>>" << std::endl;

    }

    void erase_it_test(){
        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it = vec.begin();
        auto it_3 = vec.begin()+2;
        vec.erase(vec.begin()); // 移除第一个元素
        std::cout<< *it  << std::endl ; // 访问失效的迭代器 、操作未定义、可能有真值
        test_move_vector();
        std::cout<< *it_3  << std::endl ; // 访问失效的迭代器
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

        /// array<int , 26>   死序array
        /// lambda表达式 是 匿名类型，无法获取具体type只能 通过decltype实现
        unordered_map< array<int , 26> , vector<string> , decltype(arrayHash) > mp(0,arrayHash);  /// 主动选择hash函数
        /// 每次都会遍历所有
        for( const string& str : strs){
            array<int , 26> counts{};
            int length = str.size();
            for(int i = 0 ; i<length ; ++i){
                counts[str[i] - 'a'] += 1;
            }
            mp[counts].emplace_back(str);       /// 拥有相同个数的字符串会被 放在hash表的同一个key中
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

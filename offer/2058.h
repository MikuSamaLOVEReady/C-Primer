//
// Created by YX on 2024/1/2.
//

#ifndef OFFER_2058_H
#define OFFER_2058_H

#include <vector>
#include <string>
#include <set>
#include <unordered_map>

namespace leet_2058{

    int countwords(vector<string>& words1 , vector<string>& words2){

        int sum = 0;
        for(auto it = words1.begin() ; it!=words1.end() ; ++it){
            if(std::count(words1.begin() , words1.end(), *it) != 1) continue;
            int count = 0;
            for(string& ite2 : words2){
                if(ite2 == *it) count++;
            }
            if(count == 1) {
                ++sum;
            }
        }
        return sum;
    }

    int official_solu(vector<string>& words1 , vector<string>& words2){
        std::unordered_map<string , int> mp_w1 , mp_w2;
        for(const string& word1 : words1){
             ++mp_w1[word1];
        }

        for(const string& word2 : words2){
            ++mp_w2[word2];
        }

        int res = 0;
        for(const auto & [word1, cnt1] : mp_w1){
                if(cnt1 == 1 && mp_w2[word1] == 1){
                    ++res;
                }
        }
        return res;

//        for(const auto& w : mp_w1){
//             //w.second
//        }

    }


    class A {
        public:
        int _a;

    };

    class B : A {
    public:
//        B():A(){
//
//        };
        B();

    };

}


#endif //OFFER_2058_H

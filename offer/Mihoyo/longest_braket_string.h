//
// Created by ÂÞÈðµÑ on 2024/8/22.
//

#ifndef OFFER_LONGEST_BRAKET_STRING_H
#define OFFER_LONGEST_BRAKET_STRING_H

#include <stack>
#include <string>

using namespace std;
namespace quest1{

    int main(string str){
        stack<int> stk{};
        int result = 0;
        int cur_result = 0;
        for(int i = 0; i<str.size() ;++i){

            if( str[i] == '(' ){
                stk.push(str[i]);
            }
            else{ /// str[i] == ')'
                if(stk.empty()){
                    /// ½áËãresult
                    result = cur_result > result ? cur_result : result;
                    cur_result = 0;
                }
                else{
                    stk.pop();
                    cur_result += 2;
                }
            }
        }
        result = cur_result > result ? cur_result : result;
        return result;
    }

}


#endif //OFFER_LONGEST_BRAKET_STRING_H

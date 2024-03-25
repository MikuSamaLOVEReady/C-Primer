//
// Created by ����� on 2024/3/25.
//

#ifndef OFFER_SIGTON_LEARN_H
#define OFFER_SIGTON_LEARN_H

#include <unordered_map>
/// #include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace  std;
class Sigton_learn {

public:
    static Sigton_learn& GetInstance(){
         static Sigton_learn Instance;      /// ȷ����ȫ��Ψһ �����ڵ���ʱ�ٴ���
         return Instance;
    }

    void Add_Object(const string& s , int num){
        Order_seq.push_back(s);
        cart[s] += num;
    }

    void viewCart(){
        for(auto obj : Order_seq){
             std::cout <<  obj <<" " << cart.at(obj)  << std::endl;
        }
    }

private:
    Sigton_learn()  = default;
    std::unordered_map<std::string , int> cart;
    vector<string> Order_seq;

};

void SigtonLaern(){

    string ObjName;
    int num;
    while( cin >> ObjName >> num ){
        Sigton_learn::GetInstance().Add_Object(ObjName , num);
    }

    Sigton_learn::GetInstance().viewCart();
    return ;
}


#endif //OFFER_SIGTON_LEARN_H

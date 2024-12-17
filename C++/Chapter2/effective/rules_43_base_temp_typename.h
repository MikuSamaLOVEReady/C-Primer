//
// Created by 罗瑞笛 on 2024/7/17.
//

#ifndef CHAPTER7_RULES_43_BASE_TEMP_TYPENAME_H
#define CHAPTER7_RULES_43_BASE_TEMP_TYPENAME_H

#include <iostream>

template<typename Company>
class MsgSender {
public:
    void  sendClear(){
        std::cout << " send !! " << std::endl;
        Company c;
        c.snedClaer();
        return ;
    }

};

class CompanyZ{
    public:

};

template<>
class MsgSender<CompanyZ>{

//    void SendSecret(const MsgInfo& info){
//    }

};

template<typename T>
class emclosurClass {
public:
    void print(){
     typename T::iterator* itt; ///
    }
};

template<typename T>
class emclosurSub: public emclosurClass<T>::Nested {
public:

    /// initialize_list -> 中也不可以
    explicit emclosurSub()
    :emclosurClass<T>::Nested(){

    }

    void print(){
        typename T::iterator* itt; //
    }
};


#endif //CHAPTER7_RULES_43_BASE_TEMP_TYPENAME_H

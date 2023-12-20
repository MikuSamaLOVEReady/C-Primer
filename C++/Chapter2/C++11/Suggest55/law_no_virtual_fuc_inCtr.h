//
// Created by YX on 2023/12/5.
//

#ifndef CHAPTER7_LAW_NO_VIRTUAL_FUC_INCTR_H
#define CHAPTER7_LAW_NO_VIRTUAL_FUC_INCTR_H

#include <iostream>

class law_no_virtual_fuc_inCtr {

};

// 该如何当一个obj 体系上的obj被创建时候，就能打印出相关的信息？
/// virtual 方法X
class Transaction{
public:
    Transaction();
    virtual void logTransaction() const = 0;
};

class BuyTransaction : public Transaction{
public:
    virtual void logTransaction() const override;
};

class SellTransaction: public Transaction{
public:
    virtual void logTransaction() const override; // 是否是const的也是用于区分 能否override的问题之一

};

//BuyTransaction b; //会调用base的构造函数。


class MyTransction{
public:
    MyTransction() = default;
    MyTransction(const std::string& loginfo);
    void logTransaction(const std::string& loginfo){};

};

class myBuyTransaction : public MyTransction{
public:
    myBuyTransaction(std::string& st1)
    : MyTransction(creatLog(st1))
    {}


private:
    static std::string creatLog( const std::string& s1 ); //应该用parameter ，来组成

};

#endif //CHAPTER7_LAW_NO_VIRTUAL_FUC_INCTR_H

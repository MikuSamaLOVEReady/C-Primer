//
// Created by YX on 2023/12/5.
//

#ifndef CHAPTER7_LAW_NO_VIRTUAL_FUC_INCTR_H
#define CHAPTER7_LAW_NO_VIRTUAL_FUC_INCTR_H

#include <iostream>

class law_no_virtual_fuc_inCtr {

};

// ����ε�һ��obj ��ϵ�ϵ�obj������ʱ�򣬾��ܴ�ӡ����ص���Ϣ��
/// virtual ����X
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
    virtual void logTransaction() const override; // �Ƿ���const��Ҳ���������� �ܷ�override������֮һ

};

//BuyTransaction b; //�����base�Ĺ��캯����


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
    static std::string creatLog( const std::string& s1 ); //Ӧ����parameter �������

};

#endif //CHAPTER7_LAW_NO_VIRTUAL_FUC_INCTR_H

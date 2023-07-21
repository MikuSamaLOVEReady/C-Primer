//
// Created by 罗瑞笛 on 2023/6/26.
//

#ifndef CHAPTER7_INHERIT_H
#define CHAPTER7_INHERIT_H
#include <string>
#include <iostream>
using namespace std;

//类的定义
class base_01{
public:
    //pass by value
    base_01(double p , const string& s2): p(p), str(s2){};

    static void statemem();

private:
    double p;
    string str;
};


class inhert_01 : public base_01{
public:
    inhert_01(const string& s , double p1 , double v1 ,std::size_t quantity)
    :  value(v1),base_01(p1,s), result(quantity){};

    void f(const inhert_01&);

private:
    std::size_t result;
    double value;
};


class NoDerived final {

};

//继承一下后，终止继承
class Base{

};

//定义Last为 final
class Last final : Base{

};


class Quote {
public:
    Quote() = default;
    //这俩构造方法提供了 copy constructor 和
    Quote(const Quote& ){};
    Quote operator = (const Quote& ){};

    Quote(const std::string& b , double p) : bookNo(b) , price(p){}
    std::string isbn() const {return bookNo;}
    virtual double net_price(std::size_t n) const {return n* price;}


    virtual ~Quote() = default;
private:
    std::string bookNo;

protected:
    double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n);

class Bulk_quote3 : public Quote{
public:
    Bulk_quote3() = default;
    virtual double net_price(std::size_t n) const override{
        return 15.99f;
    }
};

class Limit_quote : public  Quote{
public:
    Limit_quote();
    Limit_quote(const std::string& b , double p , std::size_t max , double disc)
    :Quote(b,p) ,max_qt(max) , discount(disc){}
    virtual  double net_price(std::size_t n) const override;
    //virtual void vir_test();
    void non_vir_test();
private:
    std::size_t max_qt = 0;
    double discount = 0.0;
};

class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string& book , double price ,
               ::size_t qty, double disc) : Quote(book,price), quantity(qty), discount(disc)  {}

    //不想继承Quote的版本，因为用户会创建这个对象，并调用他，如果不是纯虚函数，则需要定义，如果不定义与Quote一致
    double net_price(std::size_t )  const override = 0;

protected:
    ::size_t  quantity = 0;
    double discount = 0.0;
};

class Bulk_quote_2: public Disc_quote{
public:
    Bulk_quote_2() = default;
    Bulk_quote_2(const std::string& book , double price , std::size_t qty , double disc)
    : Disc_quote(book,price,qty,disc){};
    //virtual 只能出现在类内部声明语句之前
    virtual double net_price(std::size_t) const override {
        return 15.0f;
    }
};

class Mybulk_quote : public Disc_quote{
public:
    Mybulk_quote() = default;
    Mybulk_quote(const std::string& book , double price , std::size_t qty , double disc )
    : Disc_quote(book , price, qty, disc){};
    virtual double net_price(std::size_t count) const override {
        if(count > quantity ){
            return 1000000;
        }else{
            return 0.5;
        }
    }
};
















#endif //CHAPTER7_INHERIT_H

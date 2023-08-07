//
// Created by 罗瑞笛 on 2023/4/27.
//

#ifndef CHAPTER2_SALES_DATA_H
#define CHAPTER2_SALES_DATA_H

#include <string>
#include <iostream>
class Sales_data{
 friend Sales_data add(const Sales_data& , const Sales_data&);
 friend std::ostream& print(std::ostream& , const Sales_data&);
 friend std::istream& read(std::istream&, Sales_data&);
 friend bool compareIsbn(const Sales_data &lhs , const Sales_data &rhs);

public:
    std::string isbn() const { return this->BookNO;}
    Sales_data& combine(const Sales_data&){};
    Sales_data(std::string s , unsigned cnt , double price):BookNO(s),units_sold(cnt),revenue(cnt*price){
        std::cout<< "most base" <<std::endl;
    }
    Sales_data(): Sales_data("",0,0) {
        std::cout<< "empty" <<std::endl;
    } //
    explicit Sales_data(std::istream &is ) {
        std::cout<< "cin" <<std::endl;
        read(is,*this);
    }

    Sales_data(std::string ss) {
        std::cout<< "cin" <<std::endl;
    }

    //Sales_data(std::string s = ""):BookNO(s) {};
    double avg_price() const;

 std::string BookNO;
 unsigned units_sold = 0;
 double revenue = 0.0;
};

///////////////非成员函数//////////////
Sales_data add(const Sales_data& , const Sales_data&);
std::ostream& print(std::ostream& , const Sales_data&);
std::istream& read(std::istream& , Sales_data&);
bool compareIsbn(const Sales_data &lhs , const Sales_data &rhs);


typedef std::string Type;
Type initVal();

class Exercise{
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};



class Myhouse{
    //初始化
    Myhouse(int myval):value(myval){}
    //赋值
    //Myhouse(int in_val){value = in_val;}
private:
    int value;

};

class ConstRef{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci; // 必须初始化
    int &ri;      // ri没有被初始化
};



struct X{
    X(int i , int j) : base(i), rem(base%j) {}
    int  base,rem;
};

#endif //CHAPTER2_SALES_DATA_H

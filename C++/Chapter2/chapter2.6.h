//
// Created by di on 2023/3/17.
//

#ifndef CHAPTER2_CHAPTER2_6_H
#define CHAPTER2_CHAPTER2_6_H
#include <iostream>

struct Sales_data{
    //声明
    Sales_data(const std::string& s, int *pttr);
    Sales_data(const std::string& s) : bookNo(s){};
    Sales_data(std::istream &is){
    };

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0f;
    int arr[10];

    int *ptr; // 指针不会被default初始化为nullptr

    void tettt() const{
        std::cout << "woc";
    }

    void carry() const;
};

//Sales_data s_data = {"woc",123,32.0f} ;
void Sales_data::carry() const {
        int sum = units_sold + revenue;
}
struct Person;
std::istream& read(std::istream &is, Person& person);

class Person{
    friend std::istream  &read(std::istream &is , Person &person);
    friend Sales_data::Sales_data (const std::string &s , int* pttr);
    /*
     * 因为在一个const成员函数【参数列别后有const值】中返回一个非const引用是不允许的。这是因为const成员函数的目的是为了保证对象的状态不被修改，
     * 如果允许返回一个非const引用，那么就有可能通过这个引用来修改对象的状态，这就破坏了const成员函数的原本意义。
     */
public:
    const std::string& returnName() const {
        return Name;
    }
    Person() = default;
    Person(const std::string sname , const std::string saddr) : Name(sname) , Address(saddr){}
    Person(std::istream &is) { read(is,*this);}

    std::string getName() const {return Name;}
    std::string getAddress() const {return Address;}
private:
    std::string Name;
    std::string Address;
};

//pass by ref
std::istream  &read(std::istream &is , Person &person){
    return is >> person.Name >> person.Address;
}

Sales_data::Sales_data(const std::string &s , int* pttr) : bookNo(s) , ptr(pttr){}




#endif //CHAPTER2_CHAPTER2_6_H

//
// Created by di on 2023/3/17.
//

#ifndef CHAPTER2_CHAPTER2_6_H
#define CHAPTER2_CHAPTER2_6_H
#include <iostream>

struct Sales_data{
    //����
    Sales_data(const std::string& s, int *pttr);
    Sales_data(const std::string& s) : bookNo(s){};
    Sales_data(std::istream &is){
    };

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0f;
    int arr[10];

    int *ptr; // ָ�벻�ᱻdefault��ʼ��Ϊnullptr

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
     * ��Ϊ��һ��const��Ա�����������б����constֵ���з���һ����const�����ǲ�����ġ�������Ϊconst��Ա������Ŀ����Ϊ�˱�֤�����״̬�����޸ģ�
     * ���������һ����const���ã���ô���п���ͨ������������޸Ķ����״̬������ƻ���const��Ա������ԭ�����塣
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

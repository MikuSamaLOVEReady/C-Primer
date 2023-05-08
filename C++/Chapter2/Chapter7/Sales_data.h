//
// Created by 罗瑞笛 on 2023/4/27.
//

#ifndef CHAPTER2_SALES_DATA_H
#define CHAPTER2_SALES_DATA_H

#include <string>
#include <iostream>
struct Sales_data{
 std::string isbn() const { return this->BookNO;}

 Sales_data& combine(const Sales_data&){};
 double avg_price() const;

 std::string BookNO;
 unsigned units_sold = 0;
 double revenue = 0.0;
};

///////////////非成员函数
Sales_data add(const Sales_data& , const Sales_data&);
std::ostream& print(std::ostream& , const Sales_data&);
std::istream& read(std::istream& , Sales_data&);

#endif //CHAPTER2_SALES_DATA_H

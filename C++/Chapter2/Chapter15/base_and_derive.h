//
// Created by di on 2023/6/25.
//

#ifndef CHAPTER7_BASE_AND_DERIVE_H
#define CHAPTER7_BASE_AND_DERIVE_H


class Quote{
public:
    Quote() = default;
    Quote(const std::string& book):bookNo(book){};

    //虚函数
    virtual double net_price(std::size_t n) const {return n*price; }
    //为什么要？
    virtual ~Quote() = default; //
private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class base_derive{
public:
    base_derive();
};

class Bulk_quote: public Quote{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& , double , std::size_t , double);
    //只能出现在类内部声明语句之前
    virtual double net_price(std::size_t) const override;
//新增两个元素
private:
    std::size_t  mid_qty = 0;
    double discount = 0;
};

class Bulk_quote2: private base_derive , public Quote{
public:
    Bulk_quote2();

};




#endif //CHAPTER7_BASE_AND_DERIVE_H

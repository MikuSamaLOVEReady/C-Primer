//
// Created by 罗瑞笛 on 2023/8/1.
//

#ifndef CHAPTER7_SMART_PTR_H
#define CHAPTER7_SMART_PTR_H

#include <memory>
#include <list>
#include <queue>
#include <iostream>

/*
void shar_ptr(){
    //std::string s1("woc");
    std::shared_ptr<int> pint;
    std::shared_ptr<std::string> p1;
    std::shared_ptr<std::string> p3;
    std::shared_ptr<std::list<int>> p2;
    auto p= p1.get() ;
    std::swap(p1,p3);
    p1.swap(p3);

    int a;

   // auto pt = std::make_shared<obj>(10);


    //read imu thread uwb*
    //
    // std::make_pair( uwb , imu)
    // writed ->
    //std::queue<std::pair<uwb,imu>> q; // 5000
    //q.push(std::make_pair<uwb,imu>(uwb(),imu()));

    p3 = p1;
    std::cout << "woc !" << p1.use_count() << std::endl;

    std::shared_ptr<int> p4 = std::make_shared<int>(42);
    pint = p4;
    std::cout << "woc !" << p4.use_count()  << "use " << pint.use_count() << std::endl;

    std::shared_ptr<std::string> p5 = std::make_shared<std::string>(10,'9'); //
    std::shared_ptr<int> p6 = std::make_shared<int>(); // 默认给值给0
    std::shared_ptr<std::vector<std::string>> p7 = std::make_shared<std::vector<std::string>>();

    std::cout << *p4 << std::endl;

    std::shared_ptr<int> r = std::make_shared<int>(42);
    //r = q;
}*/

class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob():data(std::make_shared<std::vector<std::string>>()){};

    //StrBlob(std::initializer_list<std::string> il):data(make_shared<std::vector<std::string>>(il)){};

    //如果用explicit的好处是什么？ 我们能把控类的全部初始化
    //               坏处是什么？
    explicit StrBlob(std::initializer_list<std::string> il)
    :data(std::make_shared<std::vector<std::string>>(il)){};

    size_type  size() const {return data->size();}
    bool empty() const {return data->empty();}
    //添加元素
    void push_back(const std::string& t){data->push_back(t);}
    void pop_back();
    //元素访问
    std::string& front();
    std::string& back();

    std::string& front() const;
    std::string& back() const;

private:
    std::shared_ptr<std::vector<std::string>> data; //唯一的数据成员 一个函数指针，需要通过make_shared创建
    void check(size_type i , const std::string &msg ) const;
};


void fun_directly_control();







#endif //CHAPTER7_SMART_PTR_H

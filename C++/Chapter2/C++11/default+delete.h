//
// Created by 罗瑞笛 on 2023/11/4.
//

#ifndef CHAPTER7_DEFAULT_DELETE_H
#define CHAPTER7_DEFAULT_DELETE_H


class Zoo{

public:
    Zoo()= default;;
    Zoo(const Zoo&) = default;
    //Zoo(const Zoo&)= default;


};


//允许 friend 和 member class 调用。
class Zoo2{

private:
    Zoo2(const Zoo2&) = default;
    Zoo2& operator = (const Zoo2&) = default;

public:
    Zoo2();

};


#endif //CHAPTER7_DEFAULT_DELETE_H

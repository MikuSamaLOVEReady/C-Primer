//
// Created by ����� on 2023/11/4.
//

#ifndef CHAPTER7_DEFAULT_DELETE_H
#define CHAPTER7_DEFAULT_DELETE_H


class Zoo{

public:
    Zoo()= default;;
    Zoo(const Zoo&) = default;
    //Zoo(const Zoo&)= default;


};


//���� friend �� member class ���á�
class Zoo2{

private:
    Zoo2(const Zoo2&) = default;
    Zoo2& operator = (const Zoo2&) = default;

public:
    Zoo2();

};


#endif //CHAPTER7_DEFAULT_DELETE_H

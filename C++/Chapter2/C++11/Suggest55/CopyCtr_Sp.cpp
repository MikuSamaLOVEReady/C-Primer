//
// Created by ����� on 2024/1/5.
//

#include "CopyCtr_Sp.h"
#include <iostream>

extern int exttvava;

CopyCtr_Sp::CopyCtr_Sp(const CopyCtr_Sp &copy):
    i(copy.i) , va(copy.va)
{
    std::cout << exttvava << std::endl;
    //ps = new std::string(*copy.ps);
}


CopyCtr_Sp &CopyCtr_Sp::operator=(const CopyCtr_Sp &ref) {

    i = ref.i;
    std::string* tem_str = new std::string(*ref.ps);
    delete ps;
    ps = tem_str;
    return *this;
}


int copy_count = 0;

number_::number_(const number_ &other) {

    this->mysn = ::copy_count++;
    std::cout << "Copy Ctr" << std::endl;
}

number_ &number_::operator = (const number_ &ref)
{
    auto new_ps = new std::string (*(ref.ps));  //������һ��λ��
    delete ps;
    ps = new_ps;       // ref �� ��ǰ����ָ��ͬһ���ط�������һ����ɾ����

    std::cout << "Assign Ctr" << std::endl;
    //sthis->mysn = random();
    return *this;
}




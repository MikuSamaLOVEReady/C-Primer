//
// Created by ����� on 2024/8/22.
//

#ifndef CHAPTER7_CASE1_NOTVIRTUAL_DECTR_H
#define CHAPTER7_CASE1_NOTVIRTUAL_DECTR_H
#include <iostream>

class Base {
public:
    // ���û�� virtual��������������������౻ɾ��ʱ����������������������
    ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        data = new int[100]; // ��̬������һЩ�ڴ�
    }
    ~Derived() {
        delete[] data; // �ͷŶ�̬������ڴ�
        std::cout << "Derived destructor called" << std::endl;
    }
private:
    int* data;
};

int main() {
    Base* obj = new Derived();
    delete obj; // ֻ����� derived ��������������������� base ���������� //�޷���̬��
    return 0;
}


#endif //CHAPTER7_CASE1_NOTVIRTUAL_DECTR_H

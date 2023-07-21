//
// Created by ����� on 2023/7/6.
//

#ifndef CHAPTER7_VIRTUAL_FUN_H
#define CHAPTER7_VIRTUAL_FUN_H

using namespace std;
struct Base2{
//virtual �޶��壿
virtual void f1(int) const {
        std::cout << " BASE f1" << std::endl;
};

virtual void f2( const string& s1 = "wc") {
    std::cout << " BASE f2" << s1 << std::endl;
};

void f3();

};

// �̳�f2 �� f3
// f2��������¶��壬��D2���õİ汾����B�ģ�
struct D2 :Base2{
    void f1(int) const override {
        std::cout << " D2 f1" << std::endl;
    };
};


struct D3 : D2{
    virtual void f1(int) const override{

        //�����Ҫ����Base��f1 ��������������������������ѭ��
        //f1(5);
        D2::f1(5);
        Base2::f1(5);

        std::cout << " D3 f1" << std::endl;
    };

    void f2( const string& s1 = "didala" ) override{

        std::cout << "D3 " <<  s1 <<std::endl;
    }; // ��������override
// void f1(int) const; ���ܼ����̳�
};


//
void default_paraprint( D2* base ){
    //base->f2();     //��Ȼ��D3 ����bsse�ṩ���βε�Ĭ��ֵ�������ɰ���base��ֵ��ӡ��
    //base->D2::f1(5);   //������������Baseָ�룬��ֻ�ܿ���Base2�Ĳ���
    //base->D2::f1(5);     //����������D2�������ܹ�����Base2�� D2�Լ��Ĳ���
    //base->Base2::f1(5);
    base->f1(5);
    
}


/*
void B::f3() {

}

void B::f2() {

}
*/

#endif //CHAPTER7_VIRTUAL_FUN_H

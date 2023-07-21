//
// Created by ����� on 2023/7/8.
//

#ifndef CHAPTER7_PROTECTED_INHERIT_H
#define CHAPTER7_PROTECTED_INHERIT_H

class Base_protec{
protected:
    int prot_mem;

private:
    int pri_mem;

public:
    int pub_mem;
};

//�൱���ڲ���һ�� public
// prot_mem  �൱��ǰ���� public protected int pro_meme;
class Sneaky : public Base_protec{
    friend void clobber(Sneaky& );
    friend void clobber(Base_protec& );

    void f(){
        //Ĭ�ϵĶ���ͨ�����this ���ʳ�Ա��Ҳ����˵  ����Ԫ+�����ࣩ ����ͨ�������������ܷ���
        // �����г�Ա��
        //
    }
    int j;
private:
    int mk;
};

// ��Ԫ�޷�ֱ�ӻ�� _ base �� protected ��Ա
//
void clobber(Sneaky& s){
    s.pub_mem = 15;
    s.j = s.prot_mem = 0;
    s.mk = 15;
}

void clobber(Base_protec& b){
    std::cout << ":w";
}

class Base_3p{
public:
    void pub_mem(){
        std::cout << ":w";
    };

private:
    int priv_men;

protected:
    int prot_men;
};

// ����̳й�ϵ�� ���������ṩһ�� �ѻ������� ǰ������������ţ�д��calss��
struct Pub_Drive : public Base_3p{
    int f() { return prot_men;}
};

struct Priv_Drive : private Base_3p{
    int f() { pub_mem(); return prot_men;}
};

//protect �̳е�ʱ�� ��Ҫ
struct pro_Drive : protected Base_3p{
    int f() { pub_mem(); return prot_men; }
};



#endif //CHAPTER7_PROTECTED_INHERIT_H

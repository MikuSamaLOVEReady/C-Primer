//
// Created by 罗瑞笛 on 2023/7/8.
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

//相当于内部有一个 public
// prot_mem  相当于前面有 public protected int pro_meme;
class Sneaky : public Base_protec{
    friend void clobber(Sneaky& );
    friend void clobber(Base_protec& );

    void f(){
        //默认的都是通过添加this 访问成员，也就是说  （友元+派生类） 必须通过派生类对象才能访问
        // 基类中成员。
        //
    }
    int j;
private:
    int mk;
};

// 友元无法直接获得 _ base 的 protected 成员
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

// 这个继承关系符 更像是在提供一种 把基础的类 前面加上描述符号，写在calss中
struct Pub_Drive : public Base_3p{
    int f() { return prot_men;}
};

struct Priv_Drive : private Base_3p{
    int f() { pub_mem(); return prot_men;}
};

//protect 继承的时候 需要
struct pro_Drive : protected Base_3p{
    int f() { pub_mem(); return prot_men; }
};



#endif //CHAPTER7_PROTECTED_INHERIT_H

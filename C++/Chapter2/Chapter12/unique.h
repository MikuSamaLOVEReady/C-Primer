//
// Created by 罗瑞笛 on 2023/8/30.
//

#ifndef CHAPTER7_UNIQUE_H
#define CHAPTER7_UNIQUE_H


void unique_base(){

    unique_ptr<string> p1(new string("My unique"));
    unique_ptr<string> p2;

    unique_ptr<double> p4();
    unique_ptr<double> p3;

    //p1.release(); // 不释放所保存的对象，直接返回保存的指针，p1本身将指向null
    //p1.reset();   // 释放p1所保管的指针所指向的内存，并且p1本身也指向null

    unique_ptr<string> pnew1(p1.release());
    unique_ptr<string> pnew2(new string("mtr"));
    pnew1.reset(pnew2.release());


    string* mystr = new string("2341");
    std::cout << "woc!!!! " << *mystr << std::endl;
    p2.reset(mystr);  // 将p2指向mystr
    p2.reset();          // p2指向null 并且它保管的内存指针（mystr）所指的空间也同时释放
    if(mystr == nullptr) // 所指向地址的内存被清理，但是mystr指针本身仍然有指向
    {
        std::cout << "woc" << std::endl;
    }
    //std::cout << "woc!!!! " << *mystr << std::endl;
}

//返回一个对象 , 底层调用了std::move , move本身是将左值转换成右值应用啊
unique_ptr<int> copy_unique(int p){
    unique_ptr<int> ret(new int(p));
    return ret;
}

void copy_unique_test (){
    unique_ptr<int> p1(new int (5));
    unique_ptr<int> p2;
    //p2 = p1;
    //unique_ptr<int> p3(p1); 这两个constructor是被删除了
}

void fun_12_17(){
    int ix = 1024 , *pi = &ix;
    //unique_ptr<int> p0(ix);
    unique_ptr<int> p2(&ix);
    unique_ptr<int> p3(&ix);
    std::cout << "woc" <<std::endl;

}



#endif //CHAPTER7_UNIQUE_H

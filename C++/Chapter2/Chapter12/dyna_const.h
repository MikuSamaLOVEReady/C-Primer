//
// Created by 罗瑞笛 on 2023/8/9.
//

#ifndef CHAPTER7_DYNA_CONST_H
#define CHAPTER7_DYNA_CONST_H

class BB{
public:
    int x, y;
};



class my_cl{
public:
    my_cl() = default;
    int v;
};

auto make_dynamic(){
    return new std::vector<int>();
}

vector<int>* decon_vec(vector<int>* v_ptr){
    int va = 0;
    while(cin >> va){
        v_ptr->push_back(va);
    }
    return v_ptr;
}

vector<int>* print_vec(vector<int>* v_ptr){
    for(auto in = v_ptr->begin() ; in !=v_ptr->end() ; ++in){
        std::cout << *in << std::endl;
    }
    return v_ptr;
}

shared_ptr<vector<int>> fun_12_7_create(){
        return std::make_shared<vector<int>>();
}

shared_ptr<vector<int>> fun_12_7_read( shared_ptr<vector<int>>  sptr){
    int va = 0;
    while(cin >> va){
        sptr->push_back(va);
    }
    return sptr;
}

void fun_12_7_print(shared_ptr<vector<int>> sptr){
    for(auto i : *sptr){
        std::cout<< i << std::endl;
    }
}

//
shared_ptr<int> genShar(){
    return shared_ptr<int>( new int(15) );
}

bool b_ptrr(){
    int* p = new int;
    return p;
}

void process(shared_ptr<int> ptr){

}

void smart_ptr(){
    int* i = new int(234);
    //shared_ptr<int>(i); //

    shared_ptr<int> p(new int(44));
    int *q =  p.get(); //获得一个同样指向44的ptr q，只不过这里的是普通指针
    std::cout << "PRE" << *q << std::endl;
    {
        //shared_ptr<int> sp(q);
        auto sp = shared_ptr<int>(q); //智能sp指向44，与外层的q是一致的
        //shared_ptr<int>(q);   //我希望创建一个临时智能指针与q指向相同元素，但貌似它直接创建了一个指向别的地方的智能指针
        std::cout << "AFTER" << *sp << std::endl;
    }
    //int foo = *p; //此时p所指内容已经消失
    //p.reset(new int (123)); // reset 与 unique()常用 当多个share_ptr指同一个对象，我们修改不想影响到所有

    if(!p.unique()){ //此时
        p.reset(new int(*p));
    }
    *p += 3; //对复制出来的数据做+操作
    std::cout <<  "woc !" << std::endl;
}

void func_12_10(std::shared_ptr<int> ptr)
{
    //2
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

void func_12_10_main(){
    std::shared_ptr<int> p(new int(42));
    func_12_10( std::shared_ptr<int>(p)); //这里回拷贝一个share ptr，导致所指向的OBJ ref+1
    std::cout << p.use_count() << std::endl;  //1 离开函数后销毁刚刚拷贝的Share_ptr, 这就导致计数变回1
    auto  q = p;
    std::cout << p.use_count() << std::endl; // 2
    return;
}

void func_12_11_main(){
    std::shared_ptr<int> p(new int(42));

    /// 不一样，使用get初始化另一个智能指针，这里复制出来的临时share_ptr与p不一样是两个不同的指针
    /// 但确实是指向同一个内存(OBJ)的指针，在fun中会被释放p所指的OBJ,在函数结束的时候又会再释放一次。
    func_12_10(shared_ptr<int>(p.get()));
    std::cout << *p << std::endl; //由于上面的sp离开scop，导致所指向空间被释放
    std::cout << p.use_count() << std::endl;  //1
    return;
}

void fun_12_12(){
    auto p = new int();
    auto sp = make_shared<int>();
    func_12_10(sp);
    //func_12_10(p);
    //func_12_10(new int());
    func_12_10(shared_ptr<int>(p)); //显示初始化，最好别将内置指针与smart混用
}

/// 产生double free错误
void fun_12_13(){
    {
        auto sp = std::make_shared<int>();
        auto p = sp.get();
        delete p;
    }
}


struct connection {
    std::string ip;
    int port;
    connection(std::string ip_, int port_):ip(ip_), port(port_){ }
};

struct destination {
    std::string ip;
    int port;
    destination(std::string ip_, int port_):ip(ip_), port(port_){ }
};

connection connect(destination* pDest)
{
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void end_disconnect(connection* p){

}

void fun_12_14(){

    //std::shared_ptr<>()
    destination dest("202.118.176.67", 3316);
    connection conn = connect(&dest);
    std::shared_ptr<connection> p (&conn,[](connection *p){  });
    //std::shared_ptr<connection> p (&conn, end_disconnect);
}

void uniq_delet(){

    destination dest("202.118.176.67", 3316);
    connection conn = connect(&dest);
    unique_ptr<connection, decltype(end_disconnect)* > p(&conn,end_disconnect) ;
}



#endif //CHAPTER7_DYNA_CONST_H

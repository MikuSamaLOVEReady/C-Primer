//
// Created by ����� on 2023/8/9.
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
    int *q =  p.get(); //���һ��ͬ��ָ��44��ptr q��ֻ�������������ָͨ��
    std::cout << "PRE" << *q << std::endl;
    {
        //shared_ptr<int> sp(q);
        auto sp = shared_ptr<int>(q); //����spָ��44��������q��һ�µ�
        //shared_ptr<int>(q);   //��ϣ������һ����ʱ����ָ����qָ����ͬԪ�أ���ò����ֱ�Ӵ�����һ��ָ���ĵط�������ָ��
        std::cout << "AFTER" << *sp << std::endl;
    }
    //int foo = *p; //��ʱp��ָ�����Ѿ���ʧ
    //p.reset(new int (123)); // reset �� unique()���� �����share_ptrָͬһ�����������޸Ĳ���Ӱ�쵽����

    if(!p.unique()){ //��ʱ
        p.reset(new int(*p));
    }
    *p += 3; //�Ը��Ƴ�����������+����
    std::cout <<  "woc !" << std::endl;
}

void func_12_10(std::shared_ptr<int> ptr)
{
    //2
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

void func_12_10_main(){
    std::shared_ptr<int> p(new int(42));
    func_12_10( std::shared_ptr<int>(p)); //����ؿ���һ��share ptr��������ָ���OBJ ref+1
    std::cout << p.use_count() << std::endl;  //1 �뿪���������ٸոտ�����Share_ptr, ��͵��¼������1
    auto  q = p;
    std::cout << p.use_count() << std::endl; // 2
    return;
}

void func_12_11_main(){
    std::shared_ptr<int> p(new int(42));

    /// ��һ����ʹ��get��ʼ����һ������ָ�룬���︴�Ƴ�������ʱshare_ptr��p��һ����������ͬ��ָ��
    /// ��ȷʵ��ָ��ͬһ���ڴ�(OBJ)��ָ�룬��fun�лᱻ�ͷ�p��ָ��OBJ,�ں���������ʱ���ֻ����ͷ�һ�Ρ�
    func_12_10(shared_ptr<int>(p.get()));
    std::cout << *p << std::endl; //���������sp�뿪scop��������ָ��ռ䱻�ͷ�
    std::cout << p.use_count() << std::endl;  //1
    return;
}

void fun_12_12(){
    auto p = new int();
    auto sp = make_shared<int>();
    func_12_10(sp);
    //func_12_10(p);
    //func_12_10(new int());
    func_12_10(shared_ptr<int>(p)); //��ʾ��ʼ������ñ�����ָ����smart����
}

/// ����double free����
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

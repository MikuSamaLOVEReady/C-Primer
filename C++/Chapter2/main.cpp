#include <iostream>
#include <stack>
//#include "chapter2.6.h"
#include "file_1.h"
#include <string>
#include <vector>
#include <deque>
#include <forward_list>
#include "string_chapter3.h"
#include "multi_array.h"
#include "function.h"
#include "arrays.h"
#include "effective/chapter-0.h"
#include <unordered_set>
#include "Unordered/unordered_map.h"
#include "Unordered/unordered_set.h"
#include <map>
#include "Chapter11/associative-container.h"
#include "Chapter7/Sales_data.h"
#include "list"
#include "Chapter11/pair.h"
#include "Chapter7/defaule_vale.h"
#include "Chapter7/Data.h"
#include <array>
#include "Chapter9/empalce_vs_push.h"
#include "Houjie/iterator_detail.h"
#include "Chapter9/Adapter.h"
#include <algorithm>
#include "Chapter8/iostream_test.h"
#include "Chapter9/forward_list.h"
#include "Chapter9/resize_fun.h"
#include "Chapter15/base_and_derive.h"
#include "Chapter15/virtual_fun.h"
#include "Chapter15/inherit.h"
#include "Chapter15/protected_inherit.h"
#include "Chapter10/Coursework10_1.h"
#include "Chapter10/read_only.h"
#include "Chapter10/send_func_to_Algorithm.h"
#include "Chapter10/Lambda_expression.h"
#include "Chapter10/bind_parameter.h"
#include <fstream>
#include "Chapter12/smart_ptr.h"
#include "Chapter15/deCons.h"
#include <filesystem>
#include "Chapter8/filesteam.h"
#include "Chapter8/sstream.h"
#include "Chapter12/dyna_const.h"
#include "Chapter12/deltetor.h"
#include "Chapter12/trickofSp.h"
#include "Chapter5/exception_test.h"
#include "Chapter12/unique.h"
#include "EgienLearn/Eigen_test.h"
#include "edabit/QuadraticEquation.h"
#include "C++11/Variadic_test.h"
#include "C++11/Variadic_class.h"
#include "C++11/Extra_nullptr_t.h"
#include "C++11/functional_std/functional_test.h"
#include <unordered_map>
#include "C++11/InitializeList.h"
#include "Chapter11/unordered_(multi)map.h"
//#include <tuple>
#include <array>
#include "C++11/default+delete.h"
#include "C++11/Aliastemp.h"
#include "C++11/variadic_printf.h"
//#include "C++11/decltype_test.h"
#include "C++11/Variadic_class.h"
#include "C++11/STLNew/RValue_Ref.h"
#include "C++11/STLNew/STLhash.h"
#include "bitset"
#include "C++11/Suggest55/law_no_virtual_fuc_inCtr.h"
#include "C++11/Suggest55/pass_by_value.h"
#include "C++11/Suggest55/Pointer_implment.h"
#include "C++11/Suggest55/DefiniVSDeclar.h"
#include "C++11/Suggest55/Pure_virDef.h"
#include "C++11/Suggest55/suggTemlateMeth.h"
#include "C++11/Suggest55/CopyCtr_Sp.h"
#include "Chapter13/swap_opera13_3.h"
#include "Chapter12/allocator_learn.h"
#include <queue>
#include "STL_Learn/Priority_learn.h"
#include "init_test.h"
#include "after_global.h"
#include "C++11/smart_ptr/recursive_shared_ptr.h"

#include "Chapter13/move_test.h"
#include "STL_Learn/std_functionLearn.h"
#include  "Chapter12/My_Sp.h"
#include "C++20/Chpter19/func_ptr.h"
#include "C++20/Chpter19/call_back_learn.h"
#include "C++20/Chpter19/functor_learn.h"
#include <functional>
#include "effective/rules_09.h"
#include "C++20/Chpter16/excp_test.h"
#include "Chapter7/Data.h"
#include "YuanRon/M1.h"
#include "C++11/decltype_test.h"

void excp_test(){
    morden_20::exptest1(15);
}


void  memo_alloc(){
    int* p = (int*)malloc(4);   /// 分配内存但不初始化
    cout<< p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;
    free(p);
    p = (int*)calloc(4, 1); /// 4个size = 1的空间 初始化为0？？？
    cout<< p[0] << " " << p[1] << " " << p[2] << " " << p[3] << endl;
    /// free(p);
    /// p = (int*)realloc(p,8);
    p = (int*)realloc(p , 8);
    cout<< p[0] << " " << p[1] << " " << p[2] << " " << p[3] <<  " " << p[4] << " " << p[5] << " " << p[6] << " " << p[7]<< endl;

}

void effec_09(){
    {
        effective_09::derive d;
    }
}

void un_map_learn(){
    un_map::unorder_interface();
}

void struc_inher(){
    te1_derive t1{};
    t1.der_print();
}

void cla_inher(){
    cl_derive te1;
    /// te1.prt();

}

void rvalueRef_lifetime(){
    int count{5};
    {
        int&& rtemp { count + 3 };
    }
    //cout << rtemp << endl;
    int va = 10;

    shared_ptr<int> sp1 = make_shared<int>( va );
    cout << " sp1_count " << sp1.use_count() << endl;

    shared_ptr<int> sp2 = make_shared<int>( va );
     // delete va;
     // free(&va); 在stack 上分配   、free不起作用 [操作未定义]
    cout << " sp1_count " << sp1.use_count() << endl;   ///
    cout << " sp2_count " << sp2.use_count() << endl;
}

long fcc(long* , int){
    std::cout << "woc! "  << std::endl;
    return 1;
}

bool cmpSTR( const std::string& s1 , const std::string& s2 ){

   return true;
}


void func_tpr_test() {

    /// Definition only
    long (*fun_ptr) (long* , int);

    /// Definition & initialize
    long (*fun_ptr2) (long* , int) { fcc };

    ///
    auto fun_ptr3 = fcc;
    fun_ptr = fuc1_ptr;

    /// Comparison_ptr<std::string> cm_ptr = cmpSTR;
    Comparison_ptr<std::string> cm_ptr { cmpSTR };

    Less less;
    const bool is_less = less( 5, 6 ); /// useless

    std::less<> less_fuctor;
    std::greater<> greater_func;

    {
        char buffer[1024]; /// 也分配在stack上
    }

    std::cout << "wic" << std::endl;

};

void sp_test(){

    std::shared_ptr<Foo> sptr = std::make_shared<Foo>(100);

    std::cout << "Foo::bar = " << sptr->getBar() << ", use_count() = "
              << sptr.use_count() << '\n';

    std::shared_ptr<Foo> sptr2 = sptr;
    std::cout << "sptr2: use_count() = " << sptr.use_count() << std::endl;
    // Reset the shared_ptr without handing it a fresh instance of Foo.
    // The old instance will be destroyed after this call.
    std::cout << "call sptr.reset()...\n";
    sptr.reset(); // calls Foo's destructor here
    std::cout << "After reset(): use_count() = " << sptr.use_count() << std::endl;
    sptr2.reset();
    std::cout << "After reset(): use_count2() = " << sptr2.use_count() << std::endl;

    Foo f1{100};
    const Foo& cRef = f1;
    Foo f2(std::move(cRef));        /// 无效move
    // f2 =  ;   /// ==   , 调用copy Ctr

}



void and_oprat( int n ){

    int count = 0;
    while ( n ){
        count++;
        n = n & n-1;
    }

    std::cout << " woc " << std::endl;
}

void struct_test(){
    SomeData s1;
    SomeData::print();

    SomeDataB sb{};
    SomeData& d = sb;
    // shared_ptr<SomeData2> d2 {SomeData2::Create()};
    /// shared_ptr<SomeData3> sd3 = std::make_shared<SomeData3>();
    SomeData3 sd3 = SomeData3();


    // d2->NeedCallSome();
    // sd3.NeedCallSome();
    /// SomeDataB obj = SomeDataB();

    d.display();

}

void wek_ptr_learn(){

    int va = 10;
    std::shared_ptr<int>  va_sp = std::make_shared<int>(va);
    std::weak_ptr<int> wk_ptr();        /// 空
    std::weak_ptr<int> wk_ptr2(va_sp);

    std::cout << va_sp.use_count() << " weak gen share" << std::endl;   /// weak 不增加count_但 lock可以增加
    if( !wk_ptr2.expired())
    {
        shared_ptr<int> ptr = wk_ptr2.lock();
        std::cout << "NOT EXPIRE" << std::endl;
    }

    std::cout << va_sp.use_count() << " weak gen share" << std::endl;
}

void share_ptr_incres(){

    static int vv;
    std::cout << vv << "VVVV" << std::endl;

    int va = 10;
    std::shared_ptr<int>  va_sp = std::make_shared<int>(va);
    va_sp.use_count();
    int* va_ptr = va_sp.get();  /// 返回一个复制品指针
    std::cout << "va_sp " << va_sp.use_count() << std::endl;
    /// 用 get() 返回的指针构造sp 不会增加计数
    std::shared_ptr<int>  va_copy_sp(va_ptr);
    std::cout << "va_copy_sp " << va_copy_sp.use_count() << std::endl;

    wek_ptr_learn();
    /// va_sp.get() 退stack的时候会发生 doule free 、 并且引用计数不增加
}



void recursive_smart() {
    std::shared_ptr<smart_learn::A> a = make_shared<smart_learn::A>();
    std::shared_ptr<smart_learn::B> b = make_shared<smart_learn::B>();
    std::weak_ptr<smart_learn::A>  wek_ptr = a;
    std::cout << " before A " << a.use_count() << " B " << b.use_count() << endl;

    b->ptr_A = a;
    a->ptr_B = b;
    std::cout << " before A " << a.use_count() << " B " << b.use_count() << endl;
};
//""
std::string globe_str;
int global_int; //“0”


move_test v1 , v2;

/// 返回右值
move_test getVec()
{
    move_test m{};
    return m;
}

void move_Assign_test()
{
    v1 = getVec();          ///move assignment
    v1 = v2;
}

void vec_test()
{
    vector<int> tes {1,2,3};
    vector<int> tes2(tes.begin() , tes.begin());
    if(tes2.empty())
        std::cout << "woc" << std::endl;
    //vector<int> tes3(tes.end()+1 , tes.end());
    //std::cout << "woc" << std::endl;
}

void BM44_stack_test()
{
    stack<int> va;

    ///std::cout << va.top() << std::endl;
}


//const int value;
void CrunNewFeature(){
    std::cout << __cplusplus <<std::endl;
    printX(7.5 , "woc" , bitset<16>(377) , 42);

    //递归继承
    mytuple<int , float , string> (1,25.3 , "woc");

    //std::nullptr_t vs nullptr

    int va = 100;
    int* ptt = nullptr;
    //foo(ptt);
    bar(ptt);
    //f(ptt);
    //f(0);

    auto I = [](int x) -> bool{
    };

    //vector<std::string>();
    // {arg1 , arg2 , arg3 } ->  initializer_list<int> --> 并转化为 array<T,n> 数组，
    // 在调用构造函数时候，特别是vector容器的时候  ， 这些 元素会被 一个个 拿出来 作为参数构造 容器的元素
    // 但如果直接存在 一个initializer_list 则会直接整体传递

    int i; // 未初始化
    int j{};
    int* p; // 未初始化
    int* q{}; //设置指针初值 = NULL
    //int x3{5.0}; // 初始化不允许 大精度 -> 小精度

    std::cout << "WOC" << std::endl;
}

void Arraytest(){

    array<int , 10> ar;
    //initializer_list

    vector<double> vec{1,2,3,4,5};

    //for(auto elem : vec){}

    //for( auto& elem : vec){}

//    for(auto _pos = vec.begin() ,
//            _end = vec.end()
//            ; _pos != _end ;++_pos)
//    {
//
//    }


}

void defauAndDelete(){
    Zoo z1;
    Zoo z2(z1);
}

template<typename T>
using Vec = std::vector<T, std::allocator<T>>;

void printDispaly(Window w) {
    w.display();
}

void printDisplayRef(const Window& wref){
    wref.display();
}

void templateAlise(){
    int aa = 100;
    float bb = 10.234f;
    test_move(aa , bb);
    XCls<string , Vec> c1;
    MyTransction obj;

    WindowWithScrool wsr1;
    printDispaly(wsr1);
    printDisplayRef(wsr1);
    Pointer_implment();
}


void f(const number_& num){

    std::cout << num.mysn << std::endl;

}

void f2( number_ num2){

    std::cout << num2.mysn << std::endl;
    string  s1 = "woerofa";
    s1.size();

}

void pure_vir(){
//        Shape_v* ps = new Shape_v();
        Shape_v* ps2 = new Rectangle_v;
        ps2 -> draw();
        ps2 -> Shape_v::draw(); //纯虚函数也能有定义

        Pure_virDefin* p = new deri();
        deri* der_p = new deri();

        p -> Pure_virDefin::pure_test();
        p->healthValue();
        der_p->healthValue();

        Enemy enemy{};
        enemy.headValue();

        // shared_ptr 按值传递，copy ctr会赋值一份
        CopyCtr_Sp cp{};
        cp.va = std::make_shared<int>(15);
        std::cout << "spppp " <<cp.va.use_count() << std::endl; //1
        CopyCtr_Sp cp2(cp);
        std::cout << "spppp " <<cp2.va.use_count() << std::endl; //2


        number_ a;
        number_ b = a , c = b;
        f2(a);
        f2(b);
        f2(c);

        Shape_v* ps;
        Shape_v* pc = new Rectangle_v();
        pc->static_ca();

}

void f_swap_opear(){

    Foo_op13 f1 , f2;
    swap(f1,f2);

    allocator<std::string> alloc;                           ///通过对象返回一个 指针？
    std::string* const p = alloc.allocate(10);           /// 指向分配的空间头部
    auto q = p;                                     /// q
    //alloc.
    //alloc.construct()
    // alloc.deallocate(p , size) // *p 、size n    [p必须是allocate返回的ptr]
    // alloc.


    std::string ssss = "001";
    int vava = 51;
    const int& ref = 14;                      // non-const lvalue reference to type 'int'
    const int& reff2 = vava * 6;              //
    int var = std::stoi(ssss);

    int itt = 42;
    // 右值 Ref
    //int&& r_ref = itt;
    //int& l_ref = itt * 8;                 /// [left ref 无法绑定表达式计算结果，计算结果可能是临时的、匿名的] non-const lvalue reference to type 'int' cannot bind to a temporary of type 'int'
    int&& r_ref = itt * 8;
    //int&& r_ref_2 = r_ref;                  /// 变量(r_ref)都是左值、无法让右值绑定它

    int&& rr3 = std::move(r_ref);           /// r_ref 变得没有意义、不能再使用它的值
}

struct Enetity
{
    int x , y;
};

void type_punning() {

    int a = 50;
    double value = a;                                                        /// implicity conversion
    Enetity e = {5,7};
    int* position = (int*)&e;
    std::cout << position[0] << " c " <<  position[1] << std::endl;         /// &获取Address 后 （pointer2*） cast一下

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(double) << std::endl;                               /// 以字节的形式打印

    double vv = 145.6235;
    std::cout << static_cast<int>(vv) << std::endl;
};

void priority_test()
{
    Priority_sigton_learn* ptr = Priority_sigton_learn::getInstance();
    const initializer_list<int> data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    for(int val : data)
    {
        Priority_sigton_learn::q_1.push(val);
        Priority_sigton_learn::q_2.push(val);
    }

    std::cout << "从大到小: " <<  Priority_sigton_learn::q_1.top() << std::endl;
    std::cout << "从小到大: " <<  Priority_sigton_learn::q_2.top() << std::endl;
}

void alloca_test(){
    //分离 空间分配 和 具体构造

}

void use_queue(){
    queue<int> var;
    var.push(12);
    var.front();
    var.pop();
}


void setdeclTest(){
    //std::set<int , decltype(cmp)> coll(cmp);

    //cout << make_tuple(7.5 , "woc" , bitset<16>(377) , 42);

    tup2<int> t(41);//6.3 , "nico"
    tup2<int ,float> t2 (41, 6.3);
    std::cout << sizeof(t) << std::endl;
    std::cout << sizeof(t2) << std::endl;
    //std::cout << t.head() << std::endl;
    //std::cout << t.tail().head() << std::endl;
    //std::cout << t.tail().tail().head() << std::endl;

    compositetup< int , float , std::string> coposiTupobj (41 , 6.3 , "nico");

    std::string s1("Hello");
    std::string s2("World");
    s1+s2 = s2; // s1 + s2 不是 rvalue？？？
    std::string() = "Woc"; // 例外！

    //std::complex<int>
    myMoveStr mmsrt = myMoveStr();
    forward(15);

    int vav = 155;
    int&& va_right_ref = vav *15;                // 右值引用
    const int& va_left_ref = va_right_ref;       // 延长右值引用的寿命
    recive_value( std::move(vav) );         // trivially-copyable 是指可以通过简单copy 来完成移动

    std::unique_ptr<myMoveStr> ptr{};
    receve_value_unique_ptr(std::move(ptr));


}

void hash_test(){
    print_hash();
}

void STL_Lear01(){

    int ia[6] = {1,2,3,4,5,6};
    vector myv(ia , ia+6);
    //for_each(myv.begin() , myv.end(), printt<int>()); //functor 就像是一个对象
    //printt<double>() (15.5f);

    //printt<int> prttobj;

    //printt<int> prttobj2();  //最好用 printt<int> prttobj3{}; uniform initialize来解决。


    /// constexpr
    int n = 1;
    const int m = 10;
    std::array<int , m> a1;


}


int main() {

    struct_test();
    //用的是一个const值
    std::cout << val <<std::endl;

    std::cout << globe_str << std::endl;
    std::cout << global_int << std::endl;

    int local_int;  //未定义的随机值
    std::string local_str;

    std::cout << local_str << std::endl;
    std::cout << local_int << std::endl;

    //todo:: 定义[分配空间] 声名
    //extern int i;  // 只是声明没有空间=
    //i = 10;       // 初始化一个 extern 标记的变量【没有空间】

    int j;          // 分空间，但没初始化 或被分一个随机的数值

    //NOTE:  Ref of pointer
    int m = 43;
    int n = 55;
    int* p = &m;
    int* &r = p;

    r = &n;
    std::cout<< *p <<std::endl;

    int i = 0;
     for(i=0; i<=15 ; i++)
     {
         //find this tag in the list
         if(i  == 7)
             break;
         std::cout <<   i <<std::endl;

     }

    //p = &m;

    const int value= 10;
    const int &ref = value;
    int const &arg = 123;

    int va = 100;
    const int &r1 = va; // 只要类型不同 int VS const int -- 都会创建一个临时
    //int &r4 = r1 *2;


    //类型可转换
    double dval = 3.14;
    const int &ri = dval;
    //本质是创建了一个类型一致的零时变量
    //const int temp = dval;
    //ri = temp;

    //常量ref 可以指向一个 非常量
    int i3 = 325;
    int &rr = i3;
    const int &rl = i3; ///
    //rl = 755;

    //
    double errnum = 3.14;
    const double *dpt = &errnum; //dpt仿佛知道了这个区域是不可通过指针更改的，但其实所指区域不是const
    //*dpt = 777;

    const double corret = 55.2;
    const double *dptt = &corret;

    int min1 =-1;
    const int i2 =min1;

    int min2 = -3;
    int const *pttt = & min1;
    //*pttt = 333;


    int *p1;
    const int iic =15;
    //int &mkx;
    const int* const p3 = &iic;
    //p1 = p3;

    const int v2 =0 ;
    int v1  = v2;
    int &vv = v1;

    constexpr int mf = 20;
    constexpr int limt = mf+1;

    constexpr int *q = nullptr; // 常量指针 不能指向别处
    int null = 0 , *ppp = 0;

    typedef double wages;    //wages 会被替换成double
    typedef wages base,*pptt; //

    /*
    typedef char* pstring;  //pstring -> char pointer
    const pstring cstr = 0; //这俩种是不同的，上面是常量ptr
    const char* cstr2 = 0; //下面是指向常量的 ptr
    const pstring *ps; // ps 指向另一个 ptr[data是常量
    */

    double mmkk = 234;
    base value22 = 13;
    pptt double_ptr = &mmkk;

    //decltype();

    std::string s1 = "ST T";
    std::string s2 = s1;
    std::cout << "ssss" <<s1.size() << std::endl;
    std::cout <<  s1[3] << std::endl;

    /*
    std::string s3;
    while(std::cin>>s3)
      std::cout << s3  <<std::endl;
    }
     */

    std::string sa= "Hello";
    std::string sb = "Hiya";

    if (sa < sb) {
        std::cout << sa << " comes before " << sb << " in the dictionary." << std::endl;
    } else {
        std::cout << sa << " comes before " << sb << " in the dictionary." << std::endl;
    }

    /*
     * 一行一行都 ，包括空白符，
        std::string line;
        while(std::getline(std::cin,line))
        {
            std::cout << line  <<std::endl;
        }
     */

    std::string com1;
    std::string com2;

    /*
    while(std::cin >> com1 >> com2)
    {
        if(com1 == com2)
        {
            std::cout<<"Same"<<std::endl;
            return 1;
        }
        else if( com1 >= com2 )
        {
            std::cout << com1 <<std::endl;
        }
        else{
            std::cout<<com2 <<std::endl;
        }
    }
    */

    /*
    while (std::cin >> com1 >> com2 )
    {
        if(com1.size() ==com2.size())
            std::cout<<"True" <<std::endl;
        else
            std::cout<<"Langer" << (com1.size() > com2.size())? com1 : com2;
    }
     */


    int ival, *pavl;
    //ival = pavl = 0; //不能给int 赋值pointer

    if(ival = 1)
    {
        std::cout << "woc? " <<std::endl;
    }

    std::vector<std::string>::iterator  it;
    //++*it;

    int array[15];
    std::vector<int> vec {1, 2, 3, 4, 5,6,7,8};

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(long) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(pavl) << std::endl;
    std::cout << sizeof(array) << std::endl;
    std::cout << sizeof(vec) << std::endl;

    int a = 55 , b = 70 , c =80 , d =90;
    int grade = b;
    std::string result = (grade > 90 ) ? "High pass"
                          : (grade > 75) ? "pass"
                          : (grade > 60) ? "low pass" :"fail" ;
    std::cout << result << std::endl;

    unsigned char char1 = 0145;

    //类型转换
    1UL << 27;

    //算数转换
    bool flag;
    short sval;
    int ival_2;

    int ai[10];
    std::cout << &ai << std::endl; //ai 不会被当作一个pointer
    std::cout << ai << std::endl; //ai 不会被当作一个pointer
    int intvalueA = 3 , intvalueB = 5;
    double slop = intvalueA / intvalueB; //需要强制类型转换一下

    std::cout << slop <<std::endl;
    3.14159L + 'a';  //'a' -> int -> long double

    double dcast;
    void *pt = &dcast;
    double *decasted = static_cast<double*>(pt); //把pt ->转化成 decasted （两pointer所指向内容相同）
    std::cout << pt << " + " << decasted <<std::endl;

    //const char  str[] = "hello"; //非const内容 （可以通过去掉const操作修改内容） | const内容时不一定能被修改。【操作有风险，如果在程序的只读段】
    char  str[] = "hello";  //
    const char *pc = str; //用一个const pointer指向它 [封住了写权限]
    char *ppt = const_cast<char *>(pc);//可强制类型转换获得写权限
    ppt[0] = 'j';
    std::cout << *str <<std::endl;

    int *ip;
    char *pcc = reinterpret_cast<char*>(ip);

    std::string spre , slater;
    std::string concat;
    int count = 0;
//    while(count < 3 && std::cin >>spre >> slater)
//    {
//        std::cout << ( (spre > slater) ?  spre : slater ) << std::endl; // (？:) 优先级太低 ASC||值越大，结果就越大。
//        count++;
//        concat += spre += slater + " ";
//    }
//    std::cout <<   concat  <<std::endl;

    //strr::strrun();
    //strr::changeSTR();
    //strr::deciToHex();
    //strr::initVector();
    //strr::chagneToBig();
    //strr::_t3_19();
    //strr::_itera();
    //strr::_itevector();
    //strr::_initArray();
    //strr::_ArrayPtr();
    //strr::_CompPtr();
    //strr::_ptr_move2();
    //strr::_ptr_minus();
    //strr::_all_zero();
    //strr::_compareVector();
    //std::cout << (bool)strr::_compareVector() << std::endl;
    strr::c_str();
    //strr::c_stirng_char();
    //std::vector<int> ivec = {1,2,3,4};
    //strr::arry_copy(ivec);
    //multi_array::multi_dim_array();
    //multi_array::iterator_2D_array();
    //multi_array::array_2D_poitner();
    //multi_array::print_array();
    //std::cout <<  funcs::first_0() << std::endl;
    //std::cout <<  funcs::first_0() << std::endl;
    //std::cout <<  funcs::first_0() << std::endl;
    //funcs::first_0();
    //int val_a = 10 , val_b = 9;
    //funcs::swt( &val_a, &val_b);
    //std::cout <<  val_a << val_b << std::endl;
    //int vaa = 1000;
//    funcs::reset(vaa);
//    std::cout <<  vaa << std::endl;
//    int vv2 = 10;
//    const int vv3 = vv2;
//    funcs::fcn(vv2);
    //int i_ff = 0;
    //const int ci = i_ff;
    //const int &r = i_ff;
    //funcs::reset(&i_ff); //ptr
    //funcs::reset(&ci);  // const int* != int *
    //funcs::reset(i);
    //funcs::reset(ci);
    //funcs::reset(42); // 字面值只能绑定const ref
    //funcs::is_empty("weferaf");
//    std::string s11 = "wWWWoc";
//    bool t = funcs::find_big(s11);
//    funcs::change_big(s11);
//    std::cout <<  s11  << std::endl;
//    funcs::calc(66);
//    funcs::count("abcd", 'a');
//    funcs::sum(vec.begin(),vec.end(),3.8);

    //int arr[4] = {1,2,3,4};
    //const int* arr2 = arr;
    //funcs::print(arr2);
   // std::string s_c = "abc";
   // funcs::print(s_c.c_str());
//   int value_AA = 199;
//   int value_BB = 299;
   //funcs::swt_pointer()
//   int array22[2] = {1,2};
//   funcs::print(array22);
//    int arrr[10] = {1};
//    funcs::printt(arrr);
//    multi_array::foo(12,3413);
//    int va786  =  multi_array::null_return();
//     std::cout << va786 << std::endl;
//    std::string s122 = "swoc";
//    int vaa = 29;
//    int vaa2 = 39;//multi_array::foo(vaa , s122);
//    multi_array::get_val( s122, 0)  = 'K' ;
//    std::vector<std::string > vecStr = multi_array::proecess();
//    std::cout << vecStr.front() << std::endl;
    /*
      int ia[10];
      for(int i= 0; i != 10 ;i++){
         // std::cout <<  multi_array::get(ia,i) << std::endl;
         multi_array::get(ia,i) = i;     //给函数返回值赋值
      }
            */
// vec {1, 2, 3, 4, 5,6,7,8};
//     multi_array::print(vec.cbegin() , vec.cend());

    //typedef int arrT[10] ;
    /*
    using arrT =  int[10] ;  //以上两种别名方法等价
    arrT myArray; // 等价于 int myArray[10];
    arrT* func(int i); // 返回指针，指向一个长为10的int型数组

    int arrnoAlise[10];
    int* p1noAlise[10];
    int (*p_noalise)[10] = &arrnoAlise; //pointer to pointer

    int odd[] = {1,3,5,7,9};
    int even[] = {0,2,4,6,8};
     */

   // decltype(odd) *ptr
   /*
   std::string stt[10] = {};
   //被当成数组
   std::string (*strsdddd)[10] = nullptr;
   std::string (&strrssRef)[10] = stt;
   auto val = funcs::f(10);

   int arrayyy[10] = {0};
   //arrayyy
   std::begin(arrayyy);

   const char aatt = 'a';
   const char* cp = &aatt;  //
   char *pppt = const_cast<char*>(cp);
   *pppt = 't';
    */
   //funcs::scrren(15);
   //funcs::ts();
   //funcs::ts(24,'*');

    //constexpr int mffff = 20; //理解为const int
    //mffff = 55;


    //constexpr int a1333 =   funcs::scale(iii);
    //int iii =  1;
    //int vavva = funcs::scale(iii);
    //int arrrr[vavva];
    //assert(false);
    //funcs::printt();

    //std::string ssst;
    //while(std::cin >> ssst && ssst != "woc"){};
    //assert(std::cin); //总是有值的
    //funcs::manip(3.14);
    //double dobj;
    //funcs::manip('a','z'); //类型提升 高于
    //funcs::manip(55.4,dobj);// 算数类型转换
    //funcs::f1(42, 2.56);
    //std::begin(arrayyy);

    //声明函数指针
    //bool (*pf) (const std::string& , const std::string&);
    //bool (*pf2) (const std::string&);
    //pf2 = funcs::lengthCompare; // 这俩指向不同函数
    //pf = &funcs::lengthCompare;

    //pf("hello" ,"susu");
    //(*pf)("wer","rerw");
    //int arr[20] = {89,2,4};
    //这里仍然是数组类型并没有退化成指针
    //funcs::passarray(arr);
    //auto heade = std::begin(arr);

    //typedef decltype(lengthCompare) Func2;
    //typedef bool Func(const std::string& , const std::string&);
    //Func* fp  = funcs::lengthCompare;
//    std::string::size_type (*ptrr)(std::string &s1 , std::string &s2) = getFunc("woc");
//    auto funcPtr = getFunc("woc");
//
//    int (*funptrr)(int , int) = &intfunc;
//    int (*funptrr2)(int , int) = &intfunc2;
//    int (*funptrr3)(int , int) = &intfunc3;
//    int (*funptrr4)(int , int) = &intfunc4;
//
//    std::vector< int (*)(int, int)> fpvec;
//    fpvec.push_back(funptrr);
//    fpvec.push_back(funptrr2);
//    fpvec.push_back(funptrr3);
//    fpvec.push_back(funptrr4);
//
//    for( auto it = fpvec.begin() ; it != fpvec.end() ; it++){
//        std::cout << "___" <<(*it)(4, 2) << std::endl;
//    }

//    typedef bool (*FuncP) (const std::string& , const std::string&);
    //typedef decltype(lengthCompare) *FuncP2;
    //FuncP fptr = funcs::lengthCompare;

   // const int valdd = 124;
   // int *const cstptr = &valdd;

    //const Sales_data sstae; //初始化一个OBJ
    //sstae.tettt();
//    Person per1 , per2;
    //read(std::cin , per1);
    //Sales_data sd("woc");
    //read(read(std::cin , per1), per2);
    //std::cout << "___" << std::endl;

    //B obj1;
    //隐式转换，利用18->被自动调用了B-constructor构建了
    //doSomething(18);
    //Widget w1;
    //Widget w3; //已经创建过了这个新对象
    //这是一个新的对象 -- 一定有个构造函数被调用
    //Widget w2 = w1;  //调用的是copy 构造而不是 operator =
    //w3 = w1; // operator =
    //char name[] = "Darla";

    /*
    string s11 = "whatisyourname";
    string s12 = "sssss";
    std::unordered_set<char> unorder = {};


    //不能插入相同的字符
    for(string::iterator it = s12.begin() ; it<s12.end() ; ++it){
        unorder.insert(*it);
    }

    //family();

    // const int transValue = 10;
    // int nonval = const_cast<int>(transValue);
    // binary_search

    //decltype获取一个函数的指针时候，记得在末尾增加*
    multiset<Sales_data , decltype(compareIsbn)*> bookstroe();
    multiset<Sales_data , bool (*)(const Sales_data &lhs , const Sales_data &rhs)>
            bookstore(compareIsbn);

    multimap<std::string , std::list<int>> mapp;
    std::map<std::vector<int>::iterator , int> mv;
    std::map<std::list<int>::iterator , int> ml;

    //手动插入一个
    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator ,int>(vi.begin(),0));

    //std::list<int> li;
    //ml.insert(std::pair<std::list<int>::iterator , int>(li.begin() , 0));

    //这个key值无法比较？？？？，list的iterator无法判定大小。
    std::list<int> li;
    //ml.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));

    int value1 =10 , value2 = 20;
    std::string strtre = "worcnim";
    std::pair<int, int> pl;
    std::pair<int, int> ppps(value1 ,value2);
    std::pair<int, int> ppps2(10 ,20);
    std::cout<< (ppps==ppps2) << std::endl;



    std::pair<int, int> pter = {value1, value2};
    auto binal = std::make_pair(strtre,value1);

    //creatPair();
    map_iter();

    //Miku mksama;
    //vector<Miku> vecsdasf(10); //调用默认初始化
    vector<C> vecttt(10); //调用默认初始化

    Sales_data ate(); //直接初始化
    string  mystr = "wochde";
    Sales_data datadd = mystr; // 本质上也是自动构造了一个obj，再把它通过copy constructor。拷贝初始化
    Sales_data datad("fasdfaf"); //

    Data vall = {0,"Anna"}; //初始值顺序要与声明顺序一致

    double rrd;
    Account::rate(10.5f);
    rrd = Account::rate();
    Account cac;


    std::array<int , 10> ial; //都不调用初始化的艹
    auto vvvre = ial.size();
    auto maxx_v = ial.max_size();
    std::array<int , 4> ia3;
    //ial = ia3;
    std::array<int , 10> ia2 = {0,1,2,3,4}; //可以用赋值运算符，但不能有copy constructor
    //swap(ia2 ,ia3);
    //std::arrayial(ia2);

    std::vector<int> vector11;
    std::vector<int> vector12(1);
    std::vector<int> vector13(1,10);
    std::vector<int> vectorlong{1,3,5,7,9,12};
    std::vector<int> vectorshor{1,3,5};  // 前缀子序列


    std::vector<int> vectorshor2{1,3,9}; // 不是前缀子序列
    std::vector<int> vectorshor3{1,3,7,9,12}; // 不是前缀子序列
    auto it_v1 = vectorshor2.begin()+2;
    auto it_v2  =vectorshor3.begin()+4;
    swap(vectorshor2,vectorshor3); //已经交换过了，但并不是元素真的交换了，但iterator所指向内容不变。



    //std::vector<int> vector153 = {1,2,3};
    //std::vector<int> vector15 = vector11; //
    std::vector<int> vector15(vector11);
    std::vector<int> vector16(vector11.begin(),vector11.end());
    std::vector<int> vector17(ia2.begin(),ia2.end());


    std::list<int> mylistt{1,2,3,4,5,6};
    vector<double> myvec(mylistt.begin() , mylistt.end());
    ial = ia2;
    int digs[10] ={0,1,2,3,4,5};
    //int cpy[10] = digs;

    list<string> names{"woc","nima"};
    vector<const char*> oldstyle{"lrd"};
    //string->const char* 不存在隐式转换
    //const char* -> string 可以，因为存在构造函数
    //oldstyle.assign(names.begin(),names.end());
    names.assign(oldstyle.begin(),oldstyle.end()); //和构造函数传递
    //ial.swap()


    vector<string> scev1(10);
    vector<string> scev2(23);
    swap(scev1,scev2); //swap不同size vector
    std::string swap1 = "woc";
    std::string swap2 = "luoruidi";
    auto ite2 = swap2.begin();
    swap(swap1,swap2);
    std::cout << *ite2 << std::endl;

    vector<string> v = {"aa" , "bb" , "cc", "dd"};
    list<string> mysrrt;
    auto new_it  = mysrrt.insert(mysrrt.begin(), v.begin() , v.end());
    std::cout << *new_it <<std::endl;
    auto new_it2 = mysrrt.insert(mysrrt.begin(), {"edw","cc"});
    std::cout << *new_it2 <<std::endl;

    vector<mytest> mycalss_contain;
    //mycalss_contain.push_back(123, "woc");
    mycalss_contain.emplace_back(1233,"woc");

    //临时变量可以赋值给 const ref
    // 可以延长该临时变量到
    Sandbox sandbox(string("four"));
    cout << "The answer is: " << sandbox.member << endl;

    //ofstream out1, out2;
    //out1 = out2;

    std::deque<string> mydeque;
    string ioinput;
    /*
    while(cin >> ioinput){
        mydeque.push_back(ioinput);
    }

    for(auto val : mydeque){
        std::cout << val << std::endl;
    }*/


    fuc_9_20();
    fuc_9_21();
    //fuc_9_22();
    fuc_9_26();

    vector<int> myvv = {1,2,3,4,5};

    auto it_erase = myvv.begin()+2;
    auto it_2 = myvv.begin()+3;
    auto it_emd = myvv.end();

    int& reff = myvv.front();
    auto& first = myvv.at(0);
    reff = 15;
    myvv.erase(it_emd , it_emd);
    std::cout << *it_2 << std::endl;

    //头插链表
    forward_list<int> fw;
    fw.push_front(1);
    fw.push_front(2);


    deque<int> deqq = {1,2,3,4};
    int& ref1 = deqq[2];
    auto deq_it = deqq.begin()+1;
    //deqq.insert(deqq.begin(),10);
    deqq.push_front(10);
    std::cout << "REF" <<ref1 << "ite"  <<*deq_it << std::endl;

    std::cout << typeid(deqq).name()  << std::endl; //编译器会改变obj的名字
    //fun_9_32();
    //fun_9_33();
    //fun_9_34();
    //fun_9_35();
    fun_9_41();
    string_erasetest();
    string_insert();
    string s{ "To drive tho thou is a foolish, tho courageous act." };
    //string_insertAndErase_index(s, "tho", "though");
    std::cout << s <<std::endl;
    string sstt = "Luo";
    auto resu = fun_9_45(sstt, "Mr." ,"Jr.");
    auto resu2 = fun_9_46(sstt, "forn" ,"end");
    find_str();
    fun_9_47();


    //ofstream out1, out2;
    //out1 = out2;

    forward_list<int> flst = {1,2,3,4,5,6,7};
    func_9_27(flst);

    forward_list<string> stringf = {"woc","MIKU","wod"};
    func_9_28(stringf,"ddd","sama");
    func_test();
    std::cout << "func_invalid_vec" << std::endl;
    //func_invalid_vec();
    //func_invalid_deque();
    //func_donot_saveend(); //没有更新 end
    fuc_9_31();

    //
    //base_derive* baseclass = new Bulk_quote2();  //Cannot cast 'Bulk_quote2' to its private base class 'base_derive'
    //Quote* quteclass = new Bulk_quote2();
    string inher_s = "woc";
    inhert_01 inher = inhert_01(inher_s, 15.0, 10 , 10);
    inher.f(inher);


    Quote q1 = Quote();
    //Bulk_quote* bulkP = &q1; //X q1中没有没有Bulk的成分，无法
    //Bulk_quote& bulkr = q1;  //同上

    Bulk_quote bq1 = Bulk_quote();
    //Quote *itemp = &bq1;    //bq1存在 Qutote部分，则可以转换
    //Bulk_quote *bulk = static_cast<Bulk_quote*>(itemp); // 本质上itemp指向bulk，但是在这一步看来，itemp是Quote类型，不存在bulk。所以不行
    //print_total(std::cout , q1 , 10);
    //print_total(std::cout , bq1 , 10);

    D2 d2;
    d2.f2();
    D3 d3;
    d3.f2();

    Pub_Drive d_1;
    Priv_Drive d_2;
    pro_Drive d_3;
    d_1.pub_mem();
    //d2.pub_mem();
    d_3.f(); // 无法



    D3* test_b = new D3();
    default_paraprint(test_b);
   // fun_10_1(10);
    fun_10_3();
    fun_10_4();
    fun_10_5();
    //fun_10_7();
    std::vector<std::string> vs{ "a", "v", "aabb", "b", "c", "a", "a" };
    elimDups(vs);

    auto v_e = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    auto it_aka = std::partition(v_e.begin(), v_e.end(), less_5);

    for(auto it = it_aka ; it != v_e.end() ; ++it){
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    fun_10_14();
    fun_10_15();
    auto v_e2 = std::vector<std::string>{ "a", "ddddddddd", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    //fun_10_18(v_e2);
    value_copy();
    ref_copu();
    fcn3();
    find_string("w");
    std::cout << cont_if(v_e2) <<std::endl;

    std::ofstream outputFile2;
    char sepra = ' ';
    //std::for_each(v_e2.begin(), v_e2.end(), [&outputFile2,sepra](const std::string& s) {};

    //shar_ptr();
    /*
    MyStruct_f data;
    data.field1 = 23;
    data.field2 = 33.4;
    std::ofstream outdes("data.txt", std::ofstream::app);
    if(outdes.is_open()){
        outdes <<  data.field1 << " " <<  data.field2 << "\n";
        outdes.close();
        std::cout << "Data written to file." << std::endl;
    }
    else{
        std::cerr << "Unable to open file for writing." << std::endl;
    }
    */

    //my_fun(std::cin);
    //在delete一个父类的时候，确保能动态绑定到子类的decon，这样从外而内的析构
    Base_cal* ptr = new Derived_cal();
    delete ptr;
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    //fun_fstream();
    //file_wrte();
    //sstr_test();
    //fun_8_10();
    //5fun_8_11();
    obj ol;
    //fun_8_3();

    //StrBlob stB = {"woc","nima"}; //如果是explicit的，那么就不会调用initializer_list的构造函数
    std::initializer_list<int>();
    strr::c_stirng_char();
    string_erasetest();
    string st_ss = "thro";
    fun_9_43( st_ss , "hro", "abcd");
    file_read_double();
    fun_directly_control();
    const my_cl* ptr_my = new my_cl; //创建
    const my_cl* ptr_my_2 = new const my_cl();
    //ptr_my->v = 100;
    BB* b_ptr = new BB();   // 这种 obj中存在 还没有被初始化的的值
    Point point = Point();  //
    obj* o_ptr = new obj();

    int* p2 = new int;
    int* ptrr3 = new (nothrow) int;

    //释放动态内存
    int i_ptr , *pi1 = &i_ptr , *pi2 = nullptr;
    double *pd = new double(33) , *pd2 = pd;
    //delete i_ptr; wrong
    //delete  pi1; // WRONG：未定义，释放局部变量
    delete  pd;  // GOOD:
    //delete  pd2; // WRONG：new过的对象只能delete一次
    delete  pi2; // GOOD: delete null指针总是可行的

    //释放const
    const int *pci = new const int(1024);
    delete(pci);

    vector<int>* v_pt = new vector<int>();
    //print_vec(decon_vec(make_dynamic()));
    //print_vec(v_pt);
    //delete v_pt;

    //本身就是一个指针了，不需要在增加一个*在<>内部
    shared_ptr<vector<int>> v_ptr = make_shared<vector<int>>();
    //fun_12_7_print(fun_12_7_read(fun_12_7_create()));

    //shared_ptr<int> shar_p = new int(15); //WRONG
    shared_ptr<int> shar_p( new int (15)); // 可以

    if(b_ptrr()){
        std::cout <<  "woc !" << std::endl;
    }

    float* my_ff =  new float(23515.3);
    shared_ptr<float> spptr(my_ff);

    //shared_ptr<float>(my_ff);
    shared_ptr<int>(qewtet);
    //auto vat = *qewtet;

    int *x(new int(1024)); // 只是一个普通指针
    int pre_xxx = *x;
    //process(x);
    process(shared_ptr<int>(x)); //产生一个临时智能指针,在process结束后消失，智能指针释放内存
    int jjtr = *x;  // 此时x所指向
    //smart_ptr();
    //func_12_10_main();
    //func_12_11_main();
    //fun_12_13();
    //continue_run();
    //continue_without_run();
    //delete_ete();
    //fun_changeString();
    //fun_9_50();
    //Mydate mdata((string &) "woc"); //如果是implicit构造的话，则会传递value

    string date01 = "January 1, 1900";
    string date02 = "Jan 1, 1900";
    string date03 = "Jan 1 1900";
    string date04 = "1/1/1900";
    //fun_9_51(date04);
    //adaptor_deque();
    string stbra = "{}f{}{dfawf}";
    bool rer = brakets(stbra);
    unique_base();
    //fun_12_17();
    eigen_rotate();

    quaraticEquation(2,-7,3);
    CrunNewFeature();
    templateAlise();
    int incre_id = 0;
    plustest(incre_id);
    my_printf("%d %s" , 15 , "woc");
    setdeclTest();
    STL_Lear01();

    //std::max()
    pure_vir();
    move_Assign_test();
    vec_test();
    BM44_stack_test();
    f_swap_opear();
    type_punning();
    priority_test();
    bind_test();
    struct_test();
    int va_andOP = 3;
    and_oprat(va_andOP);

    //
    //wek_ptr_learn();
    //share_ptr_incres();

    //functio_learn();

    init_test::no_def node;
    EMPTY e1;
    std::cout << "EMPTY SIZE: " << sizeof(e1) << std::endl;

    rvalueRef_lifetime();

    std::cout << "GLOABLLLL: " << ::global_va << "GLOBAL: " << std::endl;
    after_gl::print();
    recursive_smart();
    sp_test();
    func_tpr_test();
    struc_inher();
    cla_inher();
    un_map_learn();
    effec_09();
    memo_alloc();
    excp_test();

    const this_ptrTest const_obj1;
    const_obj1.printANS();

    int coun_re = 5;
    //int&& rva_ref_coutn = coun_re ;     /// 右值引用无法绑定左值
    int aa =10;

    int vv_1 = aa++;
    int vv_2 = ++aa;
    unordered_map_VS_unordered_Multimap::insert_ALL_MAP_test();
    unordered_map_VS_unordered_Multimap::insert_ALL_SET_test();

    //setTest();

//    if(typeid(typename std::iterator_traits<vector<>>))

    std::cout << sizeof(m1::A) << std::endl;
    std::cout << sizeof(m1::B) << std::endl;
    std::cout << sizeof(m1::C) << std::endl;
    std::cout << sizeof(m1::D) << std::endl;
    m1::smartPtr_get_test();
    bind_learn();
    mutable_test();

    std::cout <<  "woc !" << std::endl;
    return 0;
}

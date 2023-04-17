#include <iostream>
#include "chapter2.6.h"
#include "file_1.h"
#include <string>
#include <vector>
#include "string_chapter3.h"
#include "multi_array.h"
#include "function.h"

//""
std::string globe_str;
int global_int; //“0”
struct Foo
{

};

//const int value;


int main() {
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
    const int &rl = i3;
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
    //strr::c_str();
    //strr::c_stirng_char();
    //std::vector<int> ivec = {1,2,3,4};
    //strr::arry_copy(ivec);
    //multi_array::multi_dim_array();
    //multi_array::iterator_2D_array();
    //multi_array::array_2D_poitner();
    //multi_array::print_array();
    std::cout <<  funcs::first_0() << std::endl;
    std::cout <<  funcs::first_0() << std::endl;
    std::cout <<  funcs::first_0() << std::endl;
    //funcs::first_0();
//    int val_a = 10 , val_b = 9;
//    funcs::swt( &val_a, &val_b);
//    std::cout <<  val_a << val_b << std::endl;
//    int vaa = 1000;
//    funcs::reset(vaa);
//    std::cout <<  vaa << std::endl;
//    int vv2 = 10;
//    const int vv3 = vv2;
//    funcs::fcn(vv2);
    int i_ff = 0;
    const int ci = i_ff;
    //const int &r = i_ff;
    funcs::reset(&i_ff); //ptr
    //funcs::reset(&ci);  // const int* != int *
    funcs::reset(i);
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
     int va786  =  multi_array::null_return();
     std::cout << va786 << std::endl;

    return 0;
}

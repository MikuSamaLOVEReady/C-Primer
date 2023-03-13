#include <iostream>


static class fuc{

    public: static int func(){
        int i;
        std::cout<<"FUC" <<i << std::endl;
        return 0;
    }


};


int main() {
    //NOTE1:当无符号数被赋予一个 不在其范围内的值时
    //1. 对无符号类型所能表示的值的个数取余数
    //2. 将该余数赋值给unsigned 类型 ，此后该余数将被读取成该类型的值
    unsigned char c = -1; // -1 = 11111111 被理解成255


    //NOTE2： 无符号数 与 有符号数 一起运算时 有符号数会自动转换成无符号数。
    int i = -1;
    unsigned int j = 1;
    std::cout<< i *j <<std::endl;

    unsigned u = 10 , u2 =42;
    std::cout << u2 -u <<std::endl;
    std::cout << u - u2 << std::endl;

    int n = 10;
    std::cout << n - u <<std::endl;
    std::cout << u - n <<std::endl;

    //NOTE3: literal 整型字面值 --> 可以直接写
    // 8【0】
    // 10
    // 16【0x】 进制的数

    //NOTE: 表示10^x 次方
    //3.145e10 = 3.145 X 10^10 e后面表示10的多少次方
    std::cout<<'\f'<<std::endl;

    //NOTE: 初始化 VS 赋值
    //initialize list
    int unints_sold = 0;
    int unints_sold2 = {0};
    int unints_sold3(0);
    int unints_sold4{0};
    //initialize list 可以避免数据精度丢失
    long double ld = 3.1415926;
    //int a{ld}; {}无法通过，因为double -> int 存在数据丢失
    int e(ld), d = ld;

    //NOTE: default initializer （在定义变量后没有给初始值）int a; -->会被系统默认给一个值
    // 与变量类型，变量定义位置有关
    // 内置类型： 函数体之外 默认值为0 。 函数体之内的变量不能自动初始化。
    fuc::func(); //输出32760

    int input_value = 0;
    //std::cin >> input_value;


    //NOTE：先声明，再到第一次使用它的时候再赋值
    int dd = 10;
    for(int i = 0 ; i<5 ; i++)
    {
        int dd = i ;
        //std::cout << ::dd <<std::endl;
    }

    //NOTE: 左值引用
    int value = 20;
    int valu2 = 10;
    int& lvale = value;
    int& lvale2 = valu2; // ref 在初始化时就必须被绑定完成，并且后续不能再绑定给其他
    int& copyvle2 = lvale; //  value 被两个ref绑定 copyvle2 与 lvale 同时操纵

    lvale = lvale2; //并不是把lvalue 指向 lvale2所指向的地方，他俩还是个资绑定自己的value1 和 vale2
    std::cout <<lvale<<"woc"<<std::endl;
    value = 30;
    std::cout <<lvale<<"woc"<<std::endl;

    //TODO: ref 必须与对象绑定而不是一个字面值
    // ref 类型与具体值必须相同 --（存在两个例外）
    // 不能与 表达式结果绑定
    // 必须带& 和 *的部分才是ref或者pointer
    int v1 = 1024 , i2 =2048;
    int& r =v1, r2 = i2; // r是ref r2 是int
    int i3 =1024 , &ri = i3;
    int& r3 =i3 , &r4 =i2; //

    //int& ref = 3+8;

    //NOTE：pointer
    // pointer 类型需要和 所指向的OBJ类型相同 --存在两个意外。
    int* ptr;
    double *dp2;
    std::cout<< ptr<< "\n" << *ptr <<std::endl;
    double dvalue = 23.32;
    double *pd = &dvalue;
    double *pd2 = dp2; // 只能给地址给pointer







    int a  = -23;


    return 0;
}

#include <iostream>

//""
std::string globe_str;
int global_int; //“0”

int main() {
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

    //p = &m;



    return 0;
}

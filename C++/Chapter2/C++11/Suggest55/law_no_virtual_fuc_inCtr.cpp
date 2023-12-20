//
// Created by YX on 2023/12/5.
//

#include "law_no_virtual_fuc_inCtr.h"
#include  <memory>

Transaction::Transaction()
{
//    logTransaction(); //会找不到实现，因为是pure


}



// 自定义删除器
struct MyDeleter {
    void operator()(int* ptr) const {
        // 在这里添加释放资源的逻辑
        delete ptr;
    }
};

//自定义删除函数  参数必须与share的绑定一致
void deleter2(int* ptr) {
    // 在这里执行释放资源的操作
    // 如果你不需要执行任何操作，可以保留这个函数为空
}

MyTransction::MyTransction(const std::string &loginfo) {

 //   唯一的数据成员 一个函数指针，需要通过make_shared创建
  //  std::shared_ptr<int> data(0,MyDeleter());
    std::shared_ptr<int> data(0,deleter2);
    logTransaction(loginfo);
    //data.get()

}


//
// Created by YX on 2023/12/5.
//

#include "law_no_virtual_fuc_inCtr.h"
#include  <memory>

Transaction::Transaction()
{
//    logTransaction(); //���Ҳ���ʵ�֣���Ϊ��pure


}



// �Զ���ɾ����
struct MyDeleter {
    void operator()(int* ptr) const {
        // ����������ͷ���Դ���߼�
        delete ptr;
    }
};

//�Զ���ɾ������  ����������share�İ�һ��
void deleter2(int* ptr) {
    // ������ִ���ͷ���Դ�Ĳ���
    // ����㲻��Ҫִ���κβ��������Ա����������Ϊ��
}

MyTransction::MyTransction(const std::string &loginfo) {

 //   Ψһ�����ݳ�Ա һ������ָ�룬��Ҫͨ��make_shared����
  //  std::shared_ptr<int> data(0,MyDeleter());
    std::shared_ptr<int> data(0,deleter2);
    logTransaction(loginfo);
    //data.get()

}


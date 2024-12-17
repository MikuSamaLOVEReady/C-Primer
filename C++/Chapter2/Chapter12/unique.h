//
// Created by ����� on 2023/8/30.
//

#ifndef CHAPTER7_UNIQUE_H
#define CHAPTER7_UNIQUE_H


void unique_base(){

    unique_ptr<string> p1(new string("My unique"));
    unique_ptr<string> p2;

    unique_ptr<double> p4();
    unique_ptr<double> p3;

    //p1.release(); // ���ͷ�������Ķ���ֱ�ӷ��ر����ָ�룬p1����ָ��null
    //p1.reset();   // �ͷ�p1�����ܵ�ָ����ָ����ڴ棬����p1����Ҳָ��null

    unique_ptr<string> pnew1(p1.release());
    unique_ptr<string> pnew2(new string("mtr"));
    pnew1.reset(pnew2.release());


    string* mystr = new string("2341");
    std::cout << "woc!!!! " << *mystr << std::endl;
    p2.reset(mystr);  // ��p2ָ��mystr
    p2.reset();          // p2ָ��null ���������ܵ��ڴ�ָ�루mystr����ָ�Ŀռ�Ҳͬʱ�ͷ�
    if(mystr == nullptr) // ��ָ���ַ���ڴ汻��������mystrָ�뱾����Ȼ��ָ��
    {
        std::cout << "woc" << std::endl;
    }
    //std::cout << "woc!!!! " << *mystr << std::endl;
}

//����һ������ , �ײ������std::move , move�����ǽ���ֵת������ֵӦ�ð�
unique_ptr<int> copy_unique(int p){
    unique_ptr<int> ret(new int(p));
    return ret;
}

void copy_unique_test (){
    unique_ptr<int> p1(new int (5));
    unique_ptr<int> p2;
    //p2 = p1;
    //unique_ptr<int> p3(p1); ������constructor�Ǳ�ɾ����
}

void fun_12_17(){
    int ix = 1024 , *pi = &ix;
    //unique_ptr<int> p0(ix);
    unique_ptr<int> p2(&ix);
    unique_ptr<int> p3(&ix);
    std::cout << "woc" <<std::endl;

}



#endif //CHAPTER7_UNIQUE_H

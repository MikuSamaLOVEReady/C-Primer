#include <iostream>


static class fuc{

    public: static int func(){
        int i;
        std::cout<<"FUC" <<i << std::endl;
        return 0;
    }


};


int main() {
    //NOTE1:���޷�����������һ�� �����䷶Χ�ڵ�ֵʱ
    //1. ���޷����������ܱ�ʾ��ֵ�ĸ���ȡ����
    //2. ����������ֵ��unsigned ���� ���˺������������ȡ�ɸ����͵�ֵ
    unsigned char c = -1; // -1 = 11111111 ������255


    //NOTE2�� �޷����� �� �з����� һ������ʱ �з��������Զ�ת�����޷�������
    int i = -1;
    unsigned int j = 1;
    std::cout<< i *j <<std::endl;

    unsigned u = 10 , u2 =42;
    std::cout << u2 -u <<std::endl;
    std::cout << u - u2 << std::endl;

    int n = 10;
    std::cout << n - u <<std::endl;
    std::cout << u - n <<std::endl;

    //NOTE3: literal ��������ֵ --> ����ֱ��д
    // 8��0��
    // 10
    // 16��0x�� ���Ƶ���

    //NOTE: ��ʾ10^x �η�
    //3.145e10 = 3.145 X 10^10 e�����ʾ10�Ķ��ٴη�
    std::cout<<'\f'<<std::endl;

    //NOTE: ��ʼ�� VS ��ֵ
    //initialize list
    int unints_sold = 0;
    int unints_sold2 = {0};
    int unints_sold3(0);
    int unints_sold4{0};
    //initialize list ���Ա������ݾ��ȶ�ʧ
    long double ld = 3.1415926;
    //int a{ld}; {}�޷�ͨ������Ϊdouble -> int �������ݶ�ʧ
    int e(ld), d = ld;

    //NOTE: default initializer ���ڶ��������û�и���ʼֵ��int a; -->�ᱻϵͳĬ�ϸ�һ��ֵ
    // ��������ͣ���������λ���й�
    // �������ͣ� ������֮�� Ĭ��ֵΪ0 �� ������֮�ڵı��������Զ���ʼ����
    fuc::func(); //���32760

    int input_value = 0;
    //std::cin >> input_value;


    //NOTE�����������ٵ���һ��ʹ������ʱ���ٸ�ֵ
    int dd = 10;
    for(int i = 0 ; i<5 ; i++)
    {
        int dd = i ;
        //std::cout << ::dd <<std::endl;
    }

    //NOTE: ��ֵ����
    int value = 20;
    int valu2 = 10;
    int& lvale = value;
    int& lvale2 = valu2; // ref �ڳ�ʼ��ʱ�ͱ��뱻����ɣ����Һ��������ٰ󶨸�����
    int& copyvle2 = lvale; //  value ������ref�� copyvle2 �� lvale ͬʱ����

    lvale = lvale2; //�����ǰ�lvalue ָ�� lvale2��ָ��ĵط����������Ǹ��ʰ��Լ���value1 �� vale2
    std::cout <<lvale<<"woc"<<std::endl;
    value = 30;
    std::cout <<lvale<<"woc"<<std::endl;

    //TODO: ref ���������󶨶�����һ������ֵ
    // ref ���������ֵ������ͬ --�������������⣩
    // ������ ���ʽ�����
    // �����& �� *�Ĳ��ֲ���ref����pointer
    int v1 = 1024 , i2 =2048;
    int& r =v1, r2 = i2; // r��ref r2 ��int
    int i3 =1024 , &ri = i3;
    int& r3 =i3 , &r4 =i2; //

    //int& ref = 3+8;

    //NOTE��pointer
    // pointer ������Ҫ�� ��ָ���OBJ������ͬ --�����������⡣
    int* ptr;
    double *dp2;
    std::cout<< ptr<< "\n" << *ptr <<std::endl;
    double dvalue = 23.32;
    double *pd = &dvalue;
    double *pd2 = dp2; // ֻ�ܸ���ַ��pointer







    int a  = -23;


    return 0;
}

//
// Created by ����� on 2023/4/7.
//

#ifndef CHAPTER2_MULTI_ARRAY_H
#define CHAPTER2_MULTI_ARRAY_H

namespace multi_array{

    void multi_dim_array(){
        //int ai[3][4]; //ai��һ������Ϊ3�����飬ÿ��Ԫ������һ������Ϊ4�����顣
        int arr[10][20][30]; // ���ﵽ������ȷ�����ݵ�λ��

        //��ʼ��(initialize list)
        int ai[3][4] = {
                {0,1,2,3},
                {4,5,6,7},
                {8,9,10,11}
        };

        int ia[3][4] = {0,1,2,3,4,5,6,
                        7, 8, 9,10,11};

        int att[5]; //

        int ia2[3][4] = { {0} , {4} , {8} }; //��һ��{����}һ���Գ�ʼ��ĳһ�еĵ�һ��

        int ix[3][4] = {1,2,3,4}; //ֻ���ʼ����һ�еģ�ʣ�µ�ȫ��0
    }

    void iterator_2D_array(){
        int ai[3][4] = {
                {0},{0},{9}
        };

        int ia[3] = {1,2,3};
        //int ia2[3];      // ������ֱ�ӿ�������
        //ia2 = ia;        // Ҳ������ֱ�Ӹ�ֵ
        //decltype(ia) ia3 = ia;//decltype()���õ��Ĳ���������ia����һ��ָ��������
        // int ia3[3] = ia;

        size_t cnt = 0;
        int arr[4] = {1,2,3,4,};
        int (&ptr)[4] = arr;
        ptr[3] = 23;
        //std::cout << ptr[2] << std::endl;
        for( int (&row)[4] : ai){ //�����aiû�б��Զ�ת����ָ�룬���Ǽ��������������� �� 0 ��1 ��2 ��
            for( int &col : row){
                col = cnt;
                cnt++;
            }
        }

        //��ref���Է�ֹ�������͵�����->pointer
        //��Ȼai��3��ȷʵ�����3�����飬���������Ϊ������ָ��
        //Ӧ�������������͵ı�����
//        for(auto &row :ai){
//            for(auto &col : row){
//
//            }
//        }
        //�����ͻ��Զ����Ϊָ�������һ���������͵ı���
//        for(auto row :ai){
//            for(auto &col : row){
//
//            }
//        }

        std::cout << "wc" <<std::endl;

    }


    //��ָ����Ը�����
    void array_2D_poitner(){
        int ia[3][4];
        int arrr[3] = {1,2,3};
        int *ptrt = arrr; //arrr���Զ�����ָ���һ��Ԫ�ص�ָ��
        int (*ptr)[3] = &arrr; //arrrҲ�Ǳ�������ָ�룬ֻ���������ֶ����ָ��ȥ�˵�ַ��
        // ptrָ����һ�������ָ���һ��Ԫ�ص�ָ�롣 ��������һ��ָ���ָ�롿
        std::cout << (*ptr)  <<"head pointer" <<std::endl;
        std::cout << *(*ptr) <<"VALUE        "<<std::endl;

        int (*ppt)[4] = ia; //ppt��һ��ָ�룬 ָ��һ���������ͣ���������������������Ҫ��ref��ʹ��
        (*ppt)[2] = 12;
        //int *ptr = ia;
        //int (*p)[4] = ia;
        //p = &ia[2];

        //����ia��ʽת����ָ��ia��3����һ��Ԫ�ص�ָ�룬��������һ��ָ������ͷָ���ָ�롾ָ���ָ�롿
        for( int (*p)[4] = ia ; p != std::end(ia)  ; ++p ){
            //q�Ѿ�ָ���˵�һ��Ԫ��
                for( int *q = *p ; q != *p + 4 ; ++q){
                        std::cout << *q <<std::endl;
                }
        }


    }

    //
    void print_array(){
        int ai[3][4] = {
                {0,1,2,3},
                {4,5,6,7},
                {8,9,10,11}
        };

        //forѭ���Զ�����
        for(auto &row:ai){
            for(int value :row){ //�����Ref�Ļ������Ա���row���Pointer
                std::cout << value <<std::endl;
            }
        }

        //�±�
        for (int i = 0; i < 3 ; i++ ) {
              int* row = ai[i];
              for(int j = 0 ; j< 4 ;j++){
                  std::cout<< row[j] << std::endl;
              }
        }

        //ָ��
        for( int (*p)[4] = ai ; p != std::end(ai) ; ++p)
        {
            for( int* q = *p  ; q !=std::end(*p) ;  q++){
                std::cout << *q << std::endl;
            }
        }
    }

    //void



}

#endif //CHAPTER2_MULTI_ARRAY_H

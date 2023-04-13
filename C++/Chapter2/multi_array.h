//
// Created by 罗瑞笛 on 2023/4/7.
//

#ifndef CHAPTER2_MULTI_ARRAY_H
#define CHAPTER2_MULTI_ARRAY_H

namespace multi_array{

    void multi_dim_array(){
        //int ai[3][4]; //ai是一个容量为3的数组，每个元素又是一个长度为4的数组。
        int arr[10][20][30]; // 从里到外依次确定数据的位置

        //初始化(initialize list)
        int ai[3][4] = {
                {0,1,2,3},
                {4,5,6,7},
                {8,9,10,11}
        };

        int ia[3][4] = {0,1,2,3,4,5,6,
                        7, 8, 9,10,11};

        int att[5]; //

        int ia2[3][4] = { {0} , {4} , {8} }; //用一个{数字}一次性初始化某一行的第一个

        int ix[3][4] = {1,2,3,4}; //只会初始化第一行的，剩下的全是0
    }

    void iterator_2D_array(){
        int ai[3][4] = {
                {0},{0},{9}
        };

        int ia[3] = {1,2,3};
        //int ia2[3];      // 不允许直接拷贝数组
        //ia2 = ia;        // 也不允许直接赋值
        //decltype(ia) ia3 = ia;//decltype()所用到的参数并不把ia当做一个指针来处理
        // int ia3[3] = ia;

        size_t cnt = 0;
        int arr[4] = {1,2,3,4,};
        int (&ptr)[4] = arr;
        ptr[3] = 23;
        //std::cout << ptr[2] << std::endl;
        for( int (&row)[4] : ai){ //这里的ai没有被自动转化成指针，而是继续保持数组类型 （ 0 ，1 ，2 ）
            for( int &col : row){
                col = cnt;
                cnt++;
            }
        }

        //用ref可以防止数组类型的数据->pointer
        //虽然ai【3】确实存的是3个数组，但不能理解为是三个指针
        //应当当成数组类型的变量！
//        for(auto &row :ai){
//            for(auto &col : row){
//
//            }
//        }
        //这样就会自动理解为指针而不是一个数组类型的变量
//        for(auto row :ai){
//            for(auto &col : row){
//
//            }
//        }

        std::cout << "wc" <<std::endl;

    }


    //用指针可以更改吗？
    void array_2D_poitner(){
        int ia[3][4];
        int arrr[3] = {1,2,3};
        int *ptrt = arrr; //arrr被自动当成指向第一个元素的指针
        int (*ptr)[3] = &arrr; //arrr也是被当成了指针，只不过，我又对这个指针去了地址。
        // ptr指向了一个数组的指向第一个元素的指针。 【即他是一个指针的指针】
        std::cout << (*ptr)  <<"head pointer" <<std::endl;
        std::cout << *(*ptr) <<"VALUE        "<<std::endl;

        int (*ppt)[4] = ia; //ppt是一个指针， 指向一个数组类型，由于是数组类型所以需要解ref后使用
        (*ppt)[2] = 12;
        //int *ptr = ia;
        //int (*p)[4] = ia;
        //p = &ia[2];

        //这里ia隐式转化成指向ia【3】第一个元素的指针，本质上是一个指向数组头指针的指针【指针的指针】
        for( int (*p)[4] = ia ; p != std::end(ia)  ; ++p ){
            //q已经指向了第一个元素
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

        //for循环自动控制
        for(auto &row:ai){
            for(int value :row){ //如果用Ref的话，可以避免row变成Pointer
                std::cout << value <<std::endl;
            }
        }

        //下标
        for (int i = 0; i < 3 ; i++ ) {
              int* row = ai[i];
              for(int j = 0 ; j< 4 ;j++){
                  std::cout<< row[j] << std::endl;
              }
        }

        //指针
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

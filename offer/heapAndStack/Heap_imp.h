//
// Created by ����� on 2024/3/27.
//

#ifndef OFFER_HEAP_IMP_H
#define OFFER_HEAP_IMP_H

#include <vector>
#include <queue>


namespace LRD_STL{

    template< typename T >
    class My_heap{
    public:
        My_heap() : my_data(){}

        void push_heap( const T& va ){
            my_data.push_back(va);
            int end_index = my_data.size()-1;       ///  ��Ԫ�ص�index һ��ʼ����ĩβ
            int distance  = (end_index - 1) / 2;    /// end_index - 1 / 2 �ܻ�ȡbeing -> mid �ƶ��ľ���
            auto it_begin = my_data.begin();

            /// *(it_begin + distance) < va -----> �󶥶�
            while( end_index > 0 && *(it_begin + distance) < va ) {
                *(it_begin + end_index) = *(it_begin + distance);   /// ���ڵ�С������ȥ
                end_index = distance;
                distance = (end_index-1)/2;
            }
            /// end_index ������մﵽheap������պ� = 0
            *(it_begin + end_index) = va;
        }

        void pop_heap()
        {
            my_data[0] = my_data.back();    /// ��root ������Ϊ�������һ���ڵ㡢����ԭ��root��ɾ��
            my_data.pop_back();
            /// �����øոյ���������node�������½���
            int length = my_data.size();
            int root = 0;
            int left_child  = root * 2 + 1;
            int right_child = root * 2 + 2;

            while ( left_child < length )
            {
                int larger_index = root;                    ///ָ��ϴ����һ��
                if( my_data[left_child] > my_data[root]){
                    larger_index = left_child;
                }

                ///  ��Щʱ��һ����������������һ������������
                if( right_child < length && my_data[right_child] > my_data[root] ){
                    larger_index = right_child;
                }

                /// ����޷������³�
                if(larger_index == root)
                    break;

                std::swap( my_data[root] , my_data[larger_index] ) ;
                root = larger_index;
                left_child  = root * 2 + 1;
                right_child = root * 2 + 2;
            }
        }

        void top(){

        };

    private:
        vector<T> my_data{};
    };


}


#endif //OFFER_HEAP_IMP_H

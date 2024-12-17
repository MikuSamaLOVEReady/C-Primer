//
// Created by 罗瑞笛 on 2024/3/27.
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
            int end_index = my_data.size()-1;       ///  新元素的index 一开始放在末尾
            int distance  = (end_index - 1) / 2;    /// end_index - 1 / 2 能获取being -> mid 移动的距离
            auto it_begin = my_data.begin();

            /// *(it_begin + distance) < va -----> 大顶堆
            while( end_index > 0 && *(it_begin + distance) < va ) {
                *(it_begin + end_index) = *(it_begin + distance);   /// 父节点小、换下去
                end_index = distance;
                distance = (end_index-1)/2;
            }
            /// end_index 如果最终达到heap顶、则刚好 = 0
            *(it_begin + end_index) = va;
        }

        void pop_heap()
        {
            my_data[0] = my_data.back();    /// 树root 被更新为树中最后一个节点、并且原本root被删除
            my_data.pop_back();
            /// 重新让刚刚调换上来的node继续向下交换
            int length = my_data.size();
            int root = 0;
            int left_child  = root * 2 + 1;
            int right_child = root * 2 + 2;

            while ( left_child < length )
            {
                int larger_index = root;                    ///指向较大的那一个
                if( my_data[left_child] > my_data[root]){
                    larger_index = left_child;
                }

                ///  有些时候不一定存在右子树、但一定有左子树。
                if( right_child < length && my_data[right_child] > my_data[root] ){
                    larger_index = right_child;
                }

                /// 如果无法继续下沉
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

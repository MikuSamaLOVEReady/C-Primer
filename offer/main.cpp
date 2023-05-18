#include <iostream>
#include "offer2-41.h"
#include "offer-25.h"
//#include "offer-26.h"
//#include "offer-21.h"
#include "offer-27.h"
#include "offer28.h"



int main() {

    /*
    int t=0;
    while(true){
        if(t++>5)
            break;
        std::cout << t << std::endl;
    }
    MovingAverage* movingAverage = new MovingAverage(3);

    vector<int> nums = {};
    exchange(nums);
     */

    //[1,2,2,null,3,null,3]
    TreeNode* node = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(3);
    node->left = node2;
    node->right = node3;
    node2->left = nullptr;
    node2->right = node4;
    node3->right = nullptr;
    node3->right = node5;

    vector<int*> myvec;
    myvec.push_back(nullptr);
    bool result = isSymmetric(node);
    std::cout << "wic" << std::endl;
    //std::cout << movingAverage->next(10)<< std::endl;
    //std::cout << movingAverage->next(3) << std::endl;
    return 0;
}

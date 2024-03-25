//
// Created by 罗瑞笛 on 2023/5/1.
//

#ifndef OFFER_OFFER_07_H
#define OFFER_OFFER_07_H

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
std::unordered_map<int , int > inorder_index;

struct TreeNode_07 {
    int val;
    TreeNode_07 *left;
    TreeNode_07 *right;
    TreeNode_07(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int>& preorder ,  vector<int>& inorder , int preorder_left ,int preorder_right,
                int inorder_left , int inorder_right)
{
    //递归出口
    if(preorder_left > preorder_right){
        return nullptr;
    }

    //前序中第一个元素就是根
    int root_value = preorder[preorder_left];
    //获取在中序中的index
    int inorder_root_index = inorder_index[root_value];

    //创建root
    TreeNode* root = new TreeNode(root_value);
    //从中序中判断左右子树分别有多少个node
    int size_left_subtree = inorder_root_index - inorder_left;
    //递归构造左子树，需要在当前前序index后数 size_left_subtree 个元素放入左子树，
    root->left = build(preorder,inorder,preorder_left+1, preorder_left+size_left_subtree,
                       inorder_left,inorder_root_index-1);

    //递归构造右子树
    root->right = build(preorder,inorder,preorder_left+size_left_subtree , preorder_right,
                        inorder_root_index+1 ,inorder_right);
    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    for(int i = 0 ; i< n ;i++){
        //这个不需要提前配置空间，如果hastable中没有该元素，则自动创建
        inorder_index[inorder[i]] = i; // 1。记录中序元素数值所对应的序号，在前序列获得root后能快速定位它在中序中的index
    }
    return build(preorder,inorder,0,n-1,0,n-1);
}

//中序遍历
TreeNode* conIndexTree(TreeNode* root){
    while(root != nullptr){
        if(root->left == nullptr){
            std::cout<<"print 根";
            root = root->right;
        }
        else{
            //***设置线索***
            //先设置一个左侧探针
            TreeNode* pre = root->left;
            //遍历左侧最靠近root的右节点
            //&& pre->right != root 条件是当我们已经设置过root的线索过后
            while(pre->right != nullptr && pre->right != root){
                pre = pre->right;
            }
            //***设置线索END***
            //如果已经设置过了，则表示中序时左根右的顺序已经使用了
            if(pre->right == root){
                pre->right = nullptr ; //拆除索引
                std::cout<<"print root";
                root  = root->right; // 完成回溯
            }
            //如果还没设置过
            else{
                pre->right  = root; //设置索引
                root = root->left; //中序继续
            }
        }
    }
}


#endif //OFFER_OFFER_07_H

//
// Created by di on 2023/5/18.
//

#ifndef OFFER_OFFER_27_H
#define OFFER_OFFER_27_H
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> reverse_data;
queue<TreeNode* >  tree_node;
vector<TreeNode* >  all_treeNode;

TreeNode* mirrorTree(TreeNode* root) {
    //逆层序
    //边界条件
    if(root!= nullptr){
        tree_node.push(root);
    }
    //从右到左层序遍历，同时把节点存入
    while(!tree_node.empty()){
        //存值更新
        TreeNode* node = tree_node.front();
        tree_node.pop();
        reverse_data.push_back(node->val);
        //剩余节点更新
        if(node->right == nullptr){
            //如果是一个空节点，我需要push-1 用于占位
            //确保后续节点与其两个子节点2i+1 与 2i+2匹配
            //在后续建树的时候就会跳过
            reverse_data.push_back(-1);
        }else { tree_node.push(node->right);}
        if(node->left == nullptr){
            reverse_data.push_back(-1);
        } else{ tree_node.push(node->left);}
    }
    return root;
}

#endif //OFFER_OFFER_27_H

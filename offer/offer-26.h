//
// Created by di on 2023/5/17.
//

#ifndef OFFER_OFFER_26_H
#define OFFER_OFFER_26_H

#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;
//层序遍历
vector<TreeNode*> all_node;

void BFS( TreeNode* A ){
    if(A!= nullptr){
        all_node.push_back(A);
    }

    while(!all_node.empty()){
        //弹出一个最考前的元素
        TreeNode* cur =  all_node.front();
        all_node.pop_back();
        //push进新的node
        if(cur->left != nullptr){
            all_node.push_back(cur->left);
        }
        if(cur->right != nullptr){
            all_node.push_back(cur->right);
        }

        ////以cur节点为标准按照B树的结构两者做DFS
      //  while()
    }
}

//DFS = 后序遍历
int DFS_search_val(TreeNode* node){

    if(node == nullptr ) return -1;
    DFS_search_val(node->left);
    DFS_search_val(node->right);
    return node->val;
}

bool treeStruct_compare(TreeNode* A, TreeNode* B){
    if(B == nullptr) return true;
    else if(A == nullptr || A->val != B->val) return false;
    return treeStruct_compare(A->left , B->left) && treeStruct_compare(A->right,B->right);
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
    //直接先序遍历A树，对其中每个节点做判断是否是B结构
    return treeStruct_compare(A,B) || treeStruct_compare(A->left, B) || treeStruct_compare(A->right, B);
}



#endif //OFFER_OFFER_26_H

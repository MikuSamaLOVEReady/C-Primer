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
//�������
vector<TreeNode*> all_node;

void BFS( TreeNode* A ){
    if(A!= nullptr){
        all_node.push_back(A);
    }

    while(!all_node.empty()){
        //����һ���ǰ��Ԫ��
        TreeNode* cur =  all_node.front();
        all_node.pop_back();
        //push���µ�node
        if(cur->left != nullptr){
            all_node.push_back(cur->left);
        }
        if(cur->right != nullptr){
            all_node.push_back(cur->right);
        }

        ////��cur�ڵ�Ϊ��׼����B���Ľṹ������DFS
      //  while()
    }
}

//DFS = �������
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
    //ֱ���������A����������ÿ���ڵ����ж��Ƿ���B�ṹ
    return treeStruct_compare(A,B) || treeStruct_compare(A->left, B) || treeStruct_compare(A->right, B);
}



#endif //OFFER_OFFER_26_H

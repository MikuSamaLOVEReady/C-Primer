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
    //�����
    //�߽�����
    if(root!= nullptr){
        tree_node.push(root);
    }
    //���ҵ�����������ͬʱ�ѽڵ����
    while(!tree_node.empty()){
        //��ֵ����
        TreeNode* node = tree_node.front();
        tree_node.pop();
        reverse_data.push_back(node->val);
        //ʣ��ڵ����
        if(node->right == nullptr){
            //�����һ���սڵ㣬����Ҫpush-1 ����ռλ
            //ȷ�������ڵ����������ӽڵ�2i+1 �� 2i+2ƥ��
            //�ں���������ʱ��ͻ�����
            reverse_data.push_back(-1);
        }else { tree_node.push(node->right);}
        if(node->left == nullptr){
            reverse_data.push_back(-1);
        } else{ tree_node.push(node->left);}
    }
    return root;
}

#endif //OFFER_OFFER_27_H

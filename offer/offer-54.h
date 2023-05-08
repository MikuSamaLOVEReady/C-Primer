//
// Created by ����� on 2023/5/2.
//
#ifndef OFFER_OFFER_54_H
#define OFFER_OFFER_54_H

#include <unordered_map>
using namespace std;

static unsigned int inorder_index = 0;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//�������
void construct_inorder_Map( unordered_map<TreeNode* ,unsigned int>& inorder_map , TreeNode* root){
    if(root == nullptr){
        return;
    }
    //������
    construct_inorder_Map( inorder_map  , root->left );
    //root
    inorder_map[root] = inorder_index;
    inorder_index++;
    //������
    construct_inorder_Map( inorder_map  , root->right );
}

void update_tree_value(unordered_map<TreeNode* ,unsigned int>& inorder_map , TreeNode* root,
                       unordered_map<TreeNode* ,  int>& result_map){
    if(root == nullptr){
        return;
    }
    int index = inorder_map[root];
    int new_value = 0;
    for(auto it = inorder_map.begin() ; it != inorder_map.end() ; ++it){
        if(it->second >= index)
            new_value = new_value + it->first->val;
    }
    //������ǰ�޸ģ���ȫ������������˵
    //root->val = new_value;
    //�ݴ�������ֵ���������
    result_map[root] = new_value;
    //�ݹ���tree����value
    update_tree_value(inorder_map , root->left,result_map);
    update_tree_value(inorder_map , root->right,result_map);
}


//root = ������������Ľ��
//˼·���Ӳ���õ��������У��ڹ�����ʱ���¼node��������ʱ���index��
//��һ��map�洢value��index�����������
//�ٴα���ȫ����ÿ���ڵ㣬���Ϊnull�򲻸ı��ֵ�������null����ݵ�ǰnode��index����map��
//������index>=����ֵȫ��������ڸ���
TreeNode* convertBST(TreeNode* root) {
    unordered_map<TreeNode* , unsigned int> inorder_map;
    unordered_map<TreeNode* ,  int> result_map;
    construct_inorder_Map(inorder_map , root);
    update_tree_value(inorder_map,root,result_map);
    //��������tree value
    for(auto it = result_map.begin() ; it != result_map.end() ; ++it){
         it->first->val = it->second;
    }
    return root;
}

// �����������
int sum = 0;
TreeNode* convertBST_official(TreeNode* root) {
    if (root != nullptr) {
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
    }
    return root;
}


#endif //OFFER_OFFER_54_H

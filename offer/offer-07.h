//
// Created by ����� on 2023/5/1.
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
    //�ݹ����
    if(preorder_left > preorder_right){
        return nullptr;
    }

    //ǰ���е�һ��Ԫ�ؾ��Ǹ�
    int root_value = preorder[preorder_left];
    //��ȡ�������е�index
    int inorder_root_index = inorder_index[root_value];

    //����root
    TreeNode* root = new TreeNode(root_value);
    //���������ж����������ֱ��ж��ٸ�node
    int size_left_subtree = inorder_root_index - inorder_left;
    //�ݹ鹹������������Ҫ�ڵ�ǰǰ��index���� size_left_subtree ��Ԫ�ط�����������
    root->left = build(preorder,inorder,preorder_left+1, preorder_left+size_left_subtree,
                       inorder_left,inorder_root_index-1);

    //�ݹ鹹��������
    root->right = build(preorder,inorder,preorder_left+size_left_subtree , preorder_right,
                        inorder_root_index+1 ,inorder_right);
    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    for(int i = 0 ; i< n ;i++){
        //�������Ҫ��ǰ���ÿռ䣬���hastable��û�и�Ԫ�أ����Զ�����
        inorder_index[inorder[i]] = i; // 1����¼����Ԫ����ֵ����Ӧ����ţ���ǰ���л��root���ܿ��ٶ�λ���������е�index
    }
    return build(preorder,inorder,0,n-1,0,n-1);
}

//�������
TreeNode* conIndexTree(TreeNode* root){
    while(root != nullptr){
        if(root->left == nullptr){
            std::cout<<"print ��";
            root = root->right;
        }
        else{
            //***��������***
            //������һ�����̽��
            TreeNode* pre = root->left;
            //����������root���ҽڵ�
            //&& pre->right != root �����ǵ������Ѿ����ù�root����������
            while(pre->right != nullptr && pre->right != root){
                pre = pre->right;
            }
            //***��������END***
            //����Ѿ����ù��ˣ����ʾ����ʱ����ҵ�˳���Ѿ�ʹ����
            if(pre->right == root){
                pre->right = nullptr ; //�������
                std::cout<<"print root";
                root  = root->right; // ��ɻ���
            }
            //�����û���ù�
            else{
                pre->right  = root; //��������
                root = root->left; //�������
            }
        }
    }
}


#endif //OFFER_OFFER_07_H

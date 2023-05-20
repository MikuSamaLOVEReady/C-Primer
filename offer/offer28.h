//
// Created by di on 2023/5/18.
//

#ifndef OFFER_OFFER28_H
#define OFFER_OFFER28_H
#include <queue>

queue<TreeNode*> original_node;
queue<TreeNode*> mirror_node;

//�����ı�ԭ���ڵ�
// �ݹ鷵�ر�ʾ��root�ڵ�������������Ҿ���������
TreeNode* mirror_tree(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode* left = mirror_tree(root->left);
    TreeNode* right = mirror_tree(root->right);
    //�ݹ鵽��֮�󽻻��ڵ�󷵻�
    root->right = left;
    root->left = right;
    return root;
}

// ����һ���µ�Tree
// �������� ԭ�������ľ���
// �������� ԭ�������ľ���
// �������أ� ��ʾ������һ����������ȫ�������������˵�����
TreeNode* generate_mirror(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    TreeNode* MirrorNode = new TreeNode(root->val);
    MirrorNode->left = generate_mirror(root->right);
    MirrorNode->right = generate_mirror(root->left);
    return MirrorNode;
}


bool isSymmetric(TreeNode* root) {
    if(root== nullptr) return true;
    //��α���һ��ԭTree

    //��ȡmirror
    TreeNode* mirror = generate_mirror(root);

    int original_val = 0;
    int mirror_val = 0;
    //�����������
    original_node.push(root);
    mirror_node.push(mirror);
    while(!original_node.empty()){
        TreeNode* node_origin = original_node.front();
        TreeNode* node_mirror = mirror_node.front();

        if( (node_origin!= nullptr && node_mirror!= nullptr) || (node_mirror == nullptr && node_origin == nullptr) ){
            if (node_mirror == nullptr && node_origin == nullptr)
            {
                original_node.pop();
                mirror_node.pop();
                continue;
            }
            original_val = node_origin->val;
            mirror_val = node_mirror->val;
            if(original_val != mirror_val) return false;
            original_node.pop();
            original_node.push(node_origin->left);
            original_node.push(node_origin->right);
            mirror_node.pop();
            mirror_node.push(node_mirror->left);
            mirror_node.push(node_mirror->right);
        }
        if( (node_origin== nullptr&&node_mirror!= nullptr ) || (node_origin != nullptr && node_mirror== nullptr ) ){
            return false;
        }
    }
    return true;
}

#endif //OFFER_OFFER28_H

//
// Created by ����� on 2024/3/19.
//

#ifndef OFFER_HOT_114_H
#define OFFER_HOT_114_H

class Solution_114 {
public:

    TreeNode* pre_node = nullptr;   /// pre_node ���������С���һ����flatten_����root

    void flatten(TreeNode* root) {
        if(root == nullptr) return ;
        else
        {
            /// �������� ��������
            flatten(root->right);   /// ���Ҷ� flatten֮��
            flatten(root->left);
            root->right = pre_node;
            root->left = nullptr;       ///
            pre_node = root;            /// DFS����pre������һ���˳���λ��
        }
    }
};

#endif //OFFER_HOT_114_H

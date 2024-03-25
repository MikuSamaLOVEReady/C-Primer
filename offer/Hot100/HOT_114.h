//
// Created by ÂÞÈðµÑ on 2024/3/19.
//

#ifndef OFFER_HOT_114_H
#define OFFER_HOT_114_H

class Solution_114 {
public:

    TreeNode* pre_node = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr) return ;
        else
        {
            flatten(root->right);
            flatten(root->left);
            root->right = pre_node;
            root->left = nullptr;       /// for  testing
            pre_node = root;
        }
    }
};

#endif //OFFER_HOT_114_H

//
// Created by ÂÞÈðµÑ on 2024/3/18.
//

#ifndef OFFER_HOT_538_H
#define OFFER_HOT_538_H


class Solution_528 {
public:

    TreeNode* dfs_midorder(TreeNode* root , int& cur_sum){
        if(root == nullptr) return nullptr;
        TreeNode* node = new TreeNode(-1);

        node->right = dfs_midorder(root->right ,  cur_sum) ; /// ·´Ïò ÓÒ
        cur_sum  += root->val;
        node->val = cur_sum;                        /// ¸ù
        node->left = dfs_midorder(root->left , cur_sum);    /// ×ó
        return node;
    }

    TreeNode* convertBST(TreeNode* root) {
        int start_va = 0;
        return dfs_midorder(root , start_va);
    }
};

#endif //OFFER_HOT_538_H

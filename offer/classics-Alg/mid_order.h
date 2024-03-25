//
// Created by ÂÞÈðµÑ on 2024/3/18.
//

#ifndef OFFER_MID_ORDER_H
#define OFFER_MID_ORDER_H

class Solution_midorder {
public:
    vector<int> res{};

    void dfs_midorder( TreeNode* root ){
        if(root == nullptr) return ;

        dfs_midorder(root->left);
        res.push_back(root->val);
        dfs_midorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        dfs_midorder(root);
        return res;
    }
};

#endif //OFFER_MID_ORDER_H

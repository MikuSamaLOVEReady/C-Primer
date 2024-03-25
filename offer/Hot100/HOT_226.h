//
// Created by ÂÞÈðµÑ on 2024/3/17.
//

#ifndef OFFER_HOT_226_H
#define OFFER_HOT_226_H

class Solution_226 {
public:

    /// inverse pre_order
    TreeNode* inverse_pre_order(TreeNode* root ){
        if( root == nullptr) return nullptr;
        TreeNode* cur = new TreeNode(-1);
        cur->val = root->val;
        cur->left = inverse_pre_order(root->right );
        cur->right = inverse_pre_order(root->left );
        return cur;
    }

    TreeNode* invertTree(TreeNode* root) {
       return inverse_pre_order(root);
    }

};

#endif //OFFER_HOT_226_H

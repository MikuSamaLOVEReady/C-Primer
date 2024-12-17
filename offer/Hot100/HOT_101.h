//
// Created by ÂÞÈðµÑ on 2024/3/26.
//

#ifndef OFFER_HOT_101_H
#define OFFER_HOT_101_H

class Solution_101 {
public:

    bool DFS ( TreeNode* root_left , TreeNode* root_right) {

        if( root_left == nullptr && root_right == nullptr ){
            return true;
        }
        else if (root_left == nullptr && root_right != nullptr){
            return false;
        }
        else if (root_left != nullptr && root_right == nullptr){
            return false;
        }

        bool same = false;
        if(root_left->val == root_right->val) same = true;

        return same && DFS(root_left->left , root_right->right) && DFS(root_left->right , root_right->left);

    }

    bool isSymmetric(TreeNode* root) {
        return DFS(root , root);
    }
};

#endif //OFFER_HOT_101_H

//
// Created by 罗瑞笛 on 2024/3/17.
//

#ifndef OFFER_HOT_617_H
#define OFFER_HOT_617_H

class Solution_617 {
public:

    /// 双重dfs
    TreeNode* dfs( TreeNode* root1 , TreeNode* root2){
        /// 两者均不是空
        if( root1 == nullptr && root2 == nullptr) return nullptr;

        TreeNode* cur = new TreeNode(-1);
        if( root1 == nullptr ){
            return root2;
        }
        else if ( root2 == nullptr){
            return root1;
        }
        else{
            cur->val = root1->val + root2->val;
            cur->left = dfs(root1->left , root2->left);
            cur->right = dfs( root1->right , root2->right);
            return cur;
        }
    }


    /// 无论怎样都加给 tree1 上
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1 , root2);
    }
};

#endif //OFFER_HOT_617_H

//
// Created by ÂÞÈðµÑ on 2024/3/17.
//

#ifndef OFFER_HOT_104_H
#define OFFER_HOT_104_H

class Solution_104 {
public:

    int max_depth = -1;
    void dfs(TreeNode* root  , int& depth){
        if ( root == nullptr ) return;
        depth++;
        if ( max_depth < depth ) max_depth = depth;
        dfs( root->left , depth);
        dfs(root->right  , depth);
        depth--;
    }

    int maxDepth(TreeNode* root) {
            int depth = 0;
            if( root == nullptr) return depth;
            dfs(root , depth);
            return max_depth;
    }


};

#endif //OFFER_HOT_104_H

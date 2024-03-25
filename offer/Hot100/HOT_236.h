//
// Created by ÂÞÈðµÑ on 2024/3/20.
//

#ifndef OFFER_HOT_236_H
#define OFFER_HOT_236_H

class Solution_236 {
public:

    bool find = false;
    ///  Ç°Ðò±éÀú
    void dfs(TreeNode* root , vector<TreeNode*>& path , TreeNode* target) {
        if( find || root == nullptr) return ;

        path.push_back(root);
        if( root->val == target->val) {
            find = true;
            return;
        }
        else{
            dfs(root->left  , path , target);
            dfs(root->right , path , target);
            if(!find) path.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;

        find = false;
        dfs(root , p_path , p);
        find = false;
        dfs(root , q_path , q);

        TreeNode* pre_node = nullptr;
        for(int i = 0 ; i<p_path.size() && i<q_path.size() ; ++i) {
                if ( p_path[i]->val != q_path[i]->val ) break;
                pre_node = q_path[i];
        }
        return pre_node;
    }

};

#endif //OFFER_HOT_236_H

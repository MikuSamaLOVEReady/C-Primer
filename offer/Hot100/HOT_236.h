//
// Created by 罗瑞笛 on 2024/3/20.
//

#ifndef OFFER_HOT_236_H
#define OFFER_HOT_236_H

/// 二叉树的最近公共祖先 【普通二叉成树】 没有顺序
///
class Solution_236 {
public:

    bool find = false;
    ///  前序遍历
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


class Solution_236_2 {
public:

    /// 先用DFS 把路线存起来
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    }
};
#endif //OFFER_HOT_236_H

//
// Created by 罗瑞笛 on 2024/7/17.
//

#ifndef OFFER_HOT_337_H
#define OFFER_HOT_337_H

#include <vector>
#include <queue>
#include <unordered_map>

class Solution_337 {
public:
    int rob_wrong(TreeNode* root) {
           ///BFS 将树的父子关系存入 vector 前提得是 树是满的
           vector<int> tree_array;
           queue<TreeNode*>  qu;

           if(root == nullptr) return 0;
           qu.push(root);

//           while( !qu.empty() ){
//              TreeNode* cur = qu.front();
//              qu.pop();
//
//              tree_array.push_back(cur->val);
//              if(cur->left == nullptr)
//                qu.push(cur->left);
//              if(cur->right == nullptr)
//           }
    }


    /// Q1: 如何记录 root的两种状态下的值 ？
    /// A1: 用unordered_map记录？
    unordered_map<TreeNode* , int> select;
    unordered_map<TreeNode* , int> not_select;

    // --- 每个节点 都存在两个状态【两种值】选or不选 时的值  --- //
    /// 返回值 root 能偷的最大值 -> 只可能是 偷当前node 与 不偷当前node 之一
    /// 选当前节点 = 不选left + 不选right + 当前值
    /// 不选当前节点 = max (选left , 不选）+ max (选right , 不选）
    int rob(TreeNode* root) {
        if(root == nullptr)
            return 0;

        ///DFS
        rob(root->left);
        rob(root->right);

        select[root] =  not_select[root->left] + not_select[root->right] + root->val;
        not_select[root] = max( not_select[root->left] , select[root->left] ) + max( not_select[root->right] , select[root->right] );

        return max( select[root] , not_select[root] );
    }


};

#endif //OFFER_HOT_337_H

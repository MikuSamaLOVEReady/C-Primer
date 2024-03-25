//
// Created by ยÞศ๐ตั on 2024/3/22.
//

#ifndef OFFER_BFS_H
#define OFFER_BFS_H

#include <queue>


class Solution_BFS {
public:

    vector<vector<int>> res;
    queue<TreeNode* > cur_layer;

    void layer_search( ){
        /// ตÝน้
        while( !cur_layer.empty() ){
            vector<int> cur_res;
            int node_num = cur_layer.size();
            for(int i = 0  ; i< node_num ; ++i ) {
                TreeNode* root = cur_layer.front();
                cur_layer.pop();
                if(root->left  ) cur_layer.push( root->left );
                if(root->right ) cur_layer.push( root->right);
                cur_res.push_back(root->val);
            }
            res.push_back(cur_res);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return res;
        cur_layer.push(root);
        layer_search();
        return res;
    }

    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode * >  que;
            vector<vector<int>> out;
            if(!root)       return out;
            que.push(root);
            while(!que.empty())
            {
                int size = que.size();
                vector<int> cur;
                for(int i = 0;i<size;i++)
                {
                    auto node = que.front();
                    que.pop();
                    cur.push_back(node->val);
                    if(node->left)  que.push(node->left);
                    if(node->right)  que.push(node->right);
                }
                out.push_back(cur);

            }
            return out;
        }
    };

};

#endif //OFFER_BFS_H

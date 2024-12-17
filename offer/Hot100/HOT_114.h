//
// Created by 罗瑞笛 on 2024/3/19.
//

#ifndef OFFER_HOT_114_H
#define OFFER_HOT_114_H

class Solution_114 {
public:

    TreeNode* pre_node = nullptr;   /// pre_node 逆后序遍历中、上一个被flatten_子树root

    void flatten(TreeNode* root) {
        if(root == nullptr) return ;
        else
        {
            /// 本质上是 逆后序遍历
            flatten(root->right);   /// 左、右都 flatten之后、
            flatten(root->left);
            root->right = pre_node;
            root->left = nullptr;       ///
            pre_node = root;            /// DFS可用pre保留上一次退出的位置
        }
    }
};

#endif //OFFER_HOT_114_H

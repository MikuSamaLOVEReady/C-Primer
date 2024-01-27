//
// Created by YX on 2024/1/24.
//

#ifndef OFFER_TREENODE_H
#define OFFER_TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif //OFFER_TREENODE_H

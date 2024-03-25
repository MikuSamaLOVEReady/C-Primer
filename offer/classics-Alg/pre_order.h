//
// Created by 罗瑞笛 on 2024/3/19.
//

#ifndef OFFER_PRE_ORDER_H
#define OFFER_PRE_ORDER_H

class Solution_preOrder {
public:

    TreeNode* visit( TreeNode* cur){

        TreeNode* node = new TreeNode(cur->val);
        return node;
    }

    TreeNode* pre_order(TreeNode* root) {
        if(root == nullptr) return nullptr;

        TreeNode* cur = visit(root);            ///制造一个新node，表示本次前序遍历访问的目标
        cur->right = pre_order(root->left);

        TreeNode* cur_next = nullptr;
        if(cur->right == nullptr){                  /// 如果当前到底、则表示 pre-order下一个元素可以直接插在她的右侧
             cur_next = cur;
        }
        else{
            cur_next = cur->right;
        }
        cur_next = pre_order(root->right);
        return cur;
    }

};

#endif //OFFER_PRE_ORDER_H

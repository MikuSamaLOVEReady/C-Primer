//
// Created by ����� on 2024/3/19.
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

        TreeNode* cur = visit(root);            ///����һ����node����ʾ����ǰ��������ʵ�Ŀ��
        cur->right = pre_order(root->left);

        TreeNode* cur_next = nullptr;
        if(cur->right == nullptr){                  /// �����ǰ���ס����ʾ pre-order��һ��Ԫ�ؿ���ֱ�Ӳ��������Ҳ�
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

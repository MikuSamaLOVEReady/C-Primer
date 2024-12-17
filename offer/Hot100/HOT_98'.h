//
// Created by ����� on 2024/4/1.
//

#ifndef OFFER_HOT_98_H
#define OFFER_HOT_98_H

/// �������һ���ܻ��һ����С���������
class Solution_98 {
public:
    TreeNode* pre_node = nullptr;

    bool visit_cur( TreeNode* root ){

        /// �����д���ǰһ��node , ����ֵ����ȵ�ǰС�������ڻ��������BST
        if(pre_node != nullptr && root->val <= pre_node->val ){
            return false;
        }
        else{
            return true;
        }

    }

    bool isValidBST(TreeNode* root) {

        if(root == nullptr) return true;

        bool isBST_left = false , isBST_right = false;
        bool cur_isBST  = false;

        isBST_left = isValidBST(root->left);

        cur_isBST = visit_cur(root);
        pre_node = root;

        isBST_right = isValidBST(root->right);
        return  cur_isBST && isBST_left && isBST_right;
    }


    class Solution {
    public:
        bool ifBST(TreeNode *cur, long long lower, long long upper) {
            if (cur == nullptr) {
                return true;
            }
            if (cur->val >= upper || cur->val <= lower) {
                return false;
            }

            bool left_child_tree = ifBST(cur->left, lower, cur->val);       /// ������������ֻ������ֵ������
            bool right_child_tree = ifBST(cur->right, cur->val, upper);

            return left_child_tree && right_child_tree;
        }

        bool isValidBST(TreeNode* root) {
            return ifBST(root, LONG_MIN, LONG_MAX);
        }
    };


};

#endif //OFFER_HOT_98_H

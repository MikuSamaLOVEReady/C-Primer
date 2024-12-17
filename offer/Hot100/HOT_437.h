//
// Created by 罗瑞笛 on 2024/7/13.
//

#ifndef OFFER_HOT_437_H
#define OFFER_HOT_437_H

/// DFS

class Solution_437 {
public:

    /// 已经选入root作为起点 , 那么他在递归的时候就不考虑不选当前点的可能
    int path_select_Sum(TreeNode* root, int targetSum , int count){

        if(root == nullptr)
        {
            return count;
        }

        if( targetSum-root->val == 0){
            count++;
        }

        int va = path_select_Sum(root->left ,  targetSum-root->val, count);
        int vb = path_select_Sum(root->right , targetSum-root->val, count);

        return va + vb;

    }

    /// 返回root树中， 能找到的路径数量
    int pathSum(TreeNode* root, int targetSum) {

        if(root == nullptr) return 0;

        ///选root作为起点
        int va_select = path_select_Sum(root->left  , targetSum-root->val , 0);
        int vb_select = path_select_Sum(root->right , targetSum-root->val , 0);

        ///不选root作为起点
        int  va_not = pathSum(root->left , targetSum-root->val);
        int  vb_not = pathSum(root->right , targetSum-root->val);

        return va_select+vb_select+va_not+vb_not;
    }
};

class Solution_437_way2 {
public:

    /// 纳入当前root时， 可以组合出剩余值的情况
    int path_left_Sum( TreeNode* root, int left_Sum , int count ){

        if( root == nullptr ){
            return  count;
        }

        if( left_Sum == 0 ){
            count++;
        }

        int va = path_left_Sum(root->left , left_Sum-root->val , count);
        int vb = path_left_Sum(root->right , left_Sum-root->val , count);
        return va+vb;
    }

    ///  root 为路线起点，能够组合出8的情况，
    int pathSum(TreeNode* root, int targetSum) {

        if(root == nullptr)
            return 0;

        /// 算当前node为路线上节点的时 , 有多少个可能的路线
        int left_count  = path_left_Sum(root->left ,  targetSum-root->val , 0);
        int right_count = path_left_Sum(root->right , targetSum-root->val , 0);

       /// 不算当前node
       int count_left = pathSum(root->left , targetSum);
       int count_right = pathSum(root->right , targetSum);

       return left_count + right_count + count_left + count_right;
    }



};
#endif //OFFER_HOT_437_H

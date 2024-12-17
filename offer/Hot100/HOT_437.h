//
// Created by ����� on 2024/7/13.
//

#ifndef OFFER_HOT_437_H
#define OFFER_HOT_437_H

/// DFS

class Solution_437 {
public:

    /// �Ѿ�ѡ��root��Ϊ��� , ��ô���ڵݹ��ʱ��Ͳ����ǲ�ѡ��ǰ��Ŀ���
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

    /// ����root���У� ���ҵ���·������
    int pathSum(TreeNode* root, int targetSum) {

        if(root == nullptr) return 0;

        ///ѡroot��Ϊ���
        int va_select = path_select_Sum(root->left  , targetSum-root->val , 0);
        int vb_select = path_select_Sum(root->right , targetSum-root->val , 0);

        ///��ѡroot��Ϊ���
        int  va_not = pathSum(root->left , targetSum-root->val);
        int  vb_not = pathSum(root->right , targetSum-root->val);

        return va_select+vb_select+va_not+vb_not;
    }
};

class Solution_437_way2 {
public:

    /// ���뵱ǰrootʱ�� ������ϳ�ʣ��ֵ�����
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

    ///  root Ϊ·����㣬�ܹ���ϳ�8�������
    int pathSum(TreeNode* root, int targetSum) {

        if(root == nullptr)
            return 0;

        /// �㵱ǰnodeΪ·���Ͻڵ��ʱ , �ж��ٸ����ܵ�·��
        int left_count  = path_left_Sum(root->left ,  targetSum-root->val , 0);
        int right_count = path_left_Sum(root->right , targetSum-root->val , 0);

       /// ���㵱ǰnode
       int count_left = pathSum(root->left , targetSum);
       int count_right = pathSum(root->right , targetSum);

       return left_count + right_count + count_left + count_right;
    }



};
#endif //OFFER_HOT_437_H

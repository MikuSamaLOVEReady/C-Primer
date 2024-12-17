//
// Created by ����� on 2024/7/17.
//

#ifndef OFFER_HOT_337_H
#define OFFER_HOT_337_H

#include <vector>
#include <queue>
#include <unordered_map>

class Solution_337 {
public:
    int rob_wrong(TreeNode* root) {
           ///BFS �����ĸ��ӹ�ϵ���� vector ǰ����� ��������
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


    /// Q1: ��μ�¼ root������״̬�µ�ֵ ��
    /// A1: ��unordered_map��¼��
    unordered_map<TreeNode* , int> select;
    unordered_map<TreeNode* , int> not_select;

    // --- ÿ���ڵ� ����������״̬������ֵ��ѡor��ѡ ʱ��ֵ  --- //
    /// ����ֵ root ��͵�����ֵ -> ֻ������ ͵��ǰnode �� ��͵��ǰnode ֮һ
    /// ѡ��ǰ�ڵ� = ��ѡleft + ��ѡright + ��ǰֵ
    /// ��ѡ��ǰ�ڵ� = max (ѡleft , ��ѡ��+ max (ѡright , ��ѡ��
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

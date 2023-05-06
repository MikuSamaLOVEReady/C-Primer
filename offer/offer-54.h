//
// Created by 罗瑞笛 on 2023/5/2.
//
#ifndef OFFER_OFFER_54_H
#define OFFER_OFFER_54_H

#include <unordered_map>
using namespace std;

static unsigned int inorder_index = 0;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//中序遍历
void construct_inorder_Map( unordered_map<TreeNode* ,unsigned int>& inorder_map , TreeNode* root){
    if(root == nullptr){
        return;
    }
    //左子树
    construct_inorder_Map( inorder_map  , root->left );
    //root
    inorder_map[root] = inorder_index;
    inorder_index++;
    //右子树
    construct_inorder_Map( inorder_map  , root->right );
}

void update_tree_value(unordered_map<TreeNode* ,unsigned int>& inorder_map , TreeNode* root,
                       unordered_map<TreeNode* ,  int>& result_map){
    if(root == nullptr){
        return;
    }
    int index = inorder_map[root];
    int new_value = 0;
    for(auto it = inorder_map.begin() ; it != inorder_map.end() ; ++it){
        if(it->second >= index)
            new_value = new_value + it->first->val;
    }
    //不能提前修改，得全部结算完了再说
    //root->val = new_value;
    //暂存所有新值，以免叠加
    result_map[root] = new_value;
    //递归整tree更新value
    update_tree_value(inorder_map , root->left,result_map);
    update_tree_value(inorder_map , root->right,result_map);
}


//root = 是树层序遍历的结果
//思路：从层序得到中序排列，在构建的时候记录node进入中序时候的index，
//用一个map存储value与index，层序结束后
//再次遍历全树，每个节点，如果为null则不改变该值，如果！null则根据当前node的index遍历map，
//吧所有index>=它的值全部相加用于更新
TreeNode* convertBST(TreeNode* root) {
    unordered_map<TreeNode* , unsigned int> inorder_map;
    unordered_map<TreeNode* ,  int> result_map;
    construct_inorder_Map(inorder_map , root);
    update_tree_value(inorder_map,root,result_map);
    //更新所有tree value
    for(auto it = result_map.begin() ; it != result_map.end() ; ++it){
         it->first->val = it->second;
    }
    return root;
}

// 反序中序遍历
int sum = 0;
TreeNode* convertBST_official(TreeNode* root) {
    if (root != nullptr) {
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
    }
    return root;
}


#endif //OFFER_OFFER_54_H

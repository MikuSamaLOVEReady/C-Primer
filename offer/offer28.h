//
// Created by di on 2023/5/18.
//

#ifndef OFFER_OFFER28_H
#define OFFER_OFFER28_H
#include <queue>

queue<TreeNode*> original_node;
queue<TreeNode*> mirror_node;

//这里会改变原本节点
// 递归返回表示将root节点的树的子树左右镜像后输出了
TreeNode* mirror_tree(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode* left = mirror_tree(root->left);
    TreeNode* right = mirror_tree(root->right);
    //递归到底之后交换节点后返回
    root->right = left;
    root->left = right;
    return root;
}

// 产生一个新的Tree
// 左子树是 原右子树的镜像
// 右子树是 原左子树的镜像
// 函数返回： 表示产生了一个左右子树全部交换【镜像】了的新树
TreeNode* generate_mirror(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    TreeNode* MirrorNode = new TreeNode(root->val);
    MirrorNode->left = generate_mirror(root->right);
    MirrorNode->right = generate_mirror(root->left);
    return MirrorNode;
}


bool isSymmetric(TreeNode* root) {
    if(root== nullptr) return true;
    //如何备份一个原Tree

    //获取mirror
    TreeNode* mirror = generate_mirror(root);

    int original_val = 0;
    int mirror_val = 0;
    //启动层序遍历
    original_node.push(root);
    mirror_node.push(mirror);
    while(!original_node.empty()){
        TreeNode* node_origin = original_node.front();
        TreeNode* node_mirror = mirror_node.front();

        if( (node_origin!= nullptr && node_mirror!= nullptr) || (node_mirror == nullptr && node_origin == nullptr) ){
            if (node_mirror == nullptr && node_origin == nullptr)
            {
                original_node.pop();
                mirror_node.pop();
                continue;
            }
            original_val = node_origin->val;
            mirror_val = node_mirror->val;
            if(original_val != mirror_val) return false;
            original_node.pop();
            original_node.push(node_origin->left);
            original_node.push(node_origin->right);
            mirror_node.pop();
            mirror_node.push(node_mirror->left);
            mirror_node.push(node_mirror->right);
        }
        if( (node_origin== nullptr&&node_mirror!= nullptr ) || (node_origin != nullptr && node_mirror== nullptr ) ){
            return false;
        }
    }
    return true;
}

#endif //OFFER_OFFER28_H

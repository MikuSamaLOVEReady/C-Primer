//
// Created by 罗瑞笛 on 2024/3/19.
//

#ifndef OFFER_HOT_105_H
#define OFFER_HOT_105_H

class Solution_105 {
public:

    /// 返回构建完成的Tree
    /// \param cur_pre          前序
    /// \param cur_in           中序
    /// \param root_index       在pre中遍历用的index
    /// \return
    TreeNode* build_2(vector<int>& cur_pre , vector<int>& cur_in , int& root_index ){

        if( cur_in.empty() || root_index >= cur_pre.size()  ) return nullptr;
        root_index += 1;
        TreeNode* cur = new TreeNode( cur_pre[root_index]);
        if(cur_in.size() ==1 ) {
            return cur;          /// 只剩下一个元素、则构造&返回
        }

        auto it_root = std::find(cur_in.begin(), cur_in.end(), cur_pre[root_index] );
        vector<int> sub_left(cur_in.begin() , it_root);
        vector<int> sub_right(it_root+1 , cur_in.end());

        //cur->left  = build(cur_pre ,sub_left , root_index);
        //cur->right = build(cur_pre , sub_right , root_index);
        return cur;
    }


    TreeNode* build(vector<int>& cur_pre , vector<int>& cur_in , int& start_index ){

        if(start_index >= cur_pre.size() || cur_in.empty()) return nullptr;
        int cur_va = cur_pre[start_index];
        TreeNode* cur = new TreeNode( cur_va  );
        if( cur_in.size() == 1) {
            start_index++;
            return cur;
        }

        auto it_root = std::find(cur_in.begin(), cur_in.end(), cur_va);
        vector<int> sub_left(cur_in.begin() , it_root);
        vector<int> sub_right(it_root+1 , cur_in.end());

        start_index++;          ///只用加一次即可
        cur->left  = build(cur_pre ,sub_left , start_index);
        cur->right = build(cur_pre , sub_right, start_index);
        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

       /// return build(preorder , inorder , 0);
       if(preorder.empty() ) return nullptr;

       /// 划分成功
       /// auto it_root = std::find(inorder.begin(), inorder.end(), preorder[0] );
       /// vector<int> sub_inbegin(inorder.begin() , it_root);          /// 构成left tree
       /// vector<int> sub_inend(it_root+1 , inorder.end());
       int start = 0;
       return build(preorder , inorder , start);

    }


};


#endif //OFFER_HOT_105_H

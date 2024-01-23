//
// Created by YX on 2024/1/23.
//

#ifndef OFFER_LCR_156_H
#define OFFER_LCR_156_H

#include <string>
#include <list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    void pre_order(TreeNode* root , std::string& str)
    {
        if(root == nullptr )
            str += "None,";
        else
        {
            str += std::to_string(root->val) + ',';
            pre_order(root->left , str);
            pre_order(root->right, str);
        }
        return ;
    }

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string s1;
        pre_order(root , s1);
        return s1;
    }

    TreeNode* rdeserialize(std::list<std::string>& dataArray)
    {
        if(dataArray.front() == "None")
        {
            return nullptr;
        }
        /// pre_order
        TreeNode* node = new TreeNode( std::stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());

        node->left  = rdeserialize(dataArray);
        node->right = rdeserialize(dataArray);
        return node;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize( std::string data ) {
        std::list<std::string> clean_data;
        std::string str;

        for(auto& ch : data )
        {
            if(ch == ',') {
                clean_data.push_back(str);
                str.clear();
            }
            else {
                str.push_back(ch);
            }
        }

        if(!str.empty())
        {
            clean_data.push_back(str);
            str.clear();
        }

        return rdeserialize(clean_data);
    }


};



#endif //OFFER_LCR_156_H

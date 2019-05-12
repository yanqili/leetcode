/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        stack<TreeNode*> L_to_R;
        stack<TreeNode*> R_to_L;
        if(root!=NULL)
            L_to_R.push(root);
        TreeNode* tmp_node;
        while(L_to_R.size() != 0 || R_to_L.size() != 0){
            vector<int> tmp_v;
            while(L_to_R.size() != 0){
                tmp_node = L_to_R.top();
                L_to_R.pop();
                tmp_v.push_back(tmp_node->val);
                if(tmp_node->left)
                    R_to_L.push(tmp_node->left);
                if(tmp_node->right)
                    R_to_L.push(tmp_node->right);
                
            }
            if(tmp_v.size()!=0)
                result.push_back(tmp_v);
                tmp_v.clear();
            
            while(R_to_L.size() != 0){
                tmp_node = R_to_L.top();
                R_to_L.pop();
                tmp_v.push_back(tmp_node->val);

                if(tmp_node->right)
                    L_to_R.push(tmp_node->right);
                if(tmp_node->left)
                    L_to_R.push(tmp_node->left);
            }
            if(tmp_v.size()!=0)
                result.push_back(tmp_v);
                tmp_v.clear();
        }
        return result;

    }
};


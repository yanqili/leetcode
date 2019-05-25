/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {           
        vector<vector<int>> result;
        stack<vector<int>> st;
        vector<int> tmp_v;
        queue<TreeNode*> q;
        TreeNode* R; //下一层最右边的节点
        if(root == NULL)
            return result;
        q.push(root);
        R = root;
        while(q.size()!=0){
            TreeNode* tmp = q.front();
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);

            tmp_v.push_back(tmp->val);    
            if(tmp == R){
                if(q.size()!=0) // 最后一层不需要更新R
                {
                    R = q.back();
                 
                }
                st.push(tmp_v);
                tmp_v.clear();           
            }
             
            q.pop();
        }
        while(st.size()!=0){
            result.push_back(st.top());
            st.pop();
        }
        return result;
        
    }
};


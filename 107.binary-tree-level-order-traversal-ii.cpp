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
        queue<TreeNode*> q1,q2;
        stack<vector<int>> st;
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        q1.push(root);
        while(q1.size()!=0 || q2.size() != 0)
        {
            vector<int> tmp_v;
            TreeNode* tmp;
            if(q1.size()!=0){
                
                while(q1.size()!=0){
                    tmp = q1.front();
                    if(tmp->left)
                        q2.push(tmp->left);
                    if(tmp->right)
                        q2.push(tmp->right);

                    tmp_v.push_back(tmp->val);
                    q1.pop();
                }
            
                st.push(tmp_v);
                tmp_v.clear();
            }
            

            if(q2.size()!=0){
                
                while(q2.size()!=0){
                    tmp = q2.front();
                    if(tmp->left)
                        q1.push(tmp->left);
                    if(tmp->right)
                        q1.push(tmp->right);

                    tmp_v.push_back(tmp->val);
                    q2.pop();
                }
                st.push(tmp_v);
            }
            
            
        }
        while(st.size()!=0){
            result.push_back(st.top());
            st.pop();
        }
        return result;
        
    }
};


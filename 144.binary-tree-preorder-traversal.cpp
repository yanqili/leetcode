/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (50.71%)
 * Total Accepted:    318.5K
 * Total Submissions: 628.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
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
    vector<int> preorderTraversal(TreeNode* root) {
    
        stack<TreeNode*> st;
        TreeNode* tmp;
        vector<int> result;
        if(root!=NULL)
            st.push(root);
        while(st.size()!=0){
            tmp = st.top();
            st.pop();
            result.push_back(tmp->val);
            if(tmp->right)
                st.push(tmp->right);
            if(tmp->left)
                st.push(tmp->left);
        }
        return result;
    }
};


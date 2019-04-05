/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (47.46%)
 * Total Accepted:    246.4K
 * Total Submissions: 517.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
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
 * Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* tmp = root;
        TreeNode* last = NULL;
        
        while(tmp!=NULL)
        {
            st.push(tmp);
            tmp = tmp->left;
        }

        while(st.size()!=0){
            tmp = st.top();
            if(tmp->right && tmp->right != last){
                tmp = tmp->right;
                while(tmp!=NULL)
                {
                    st.push(tmp);
                    tmp = tmp->left;
                }
            }
            else{
                result.push_back(tmp->val);
                st.pop();
                last = tmp;
            }
        }
        return result;
    }
};


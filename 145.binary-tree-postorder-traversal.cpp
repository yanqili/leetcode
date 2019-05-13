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
        stack<TreeNode*> st_f; //保存已经探索过right分支的node
        vector<int> result;
        TreeNode* tmp;
        TreeNode* tmp_r = NULL;
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
        while(st.size()!=0){
            tmp = st.top();
            if(st_f.size()!=0 && tmp == st_f.top()){ // 已探索过该节点的right分支，可直接取出了
                result.push_back(tmp->val);
                st_f.pop();
                st.pop();
            }
            else{
                if(tmp->right){
                    st_f.push(tmp);
                    tmp = tmp->right;
                    while(tmp!=NULL){
                        st.push(tmp);
                        tmp = tmp->left;
                    }
                }
                else{
                    tmp = st.top();
                    st.pop();
                    result.push_back(tmp->val);
                }
                
                

          }        
        }
    return result;
    }
};


/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (44.46%)
 * Total Accepted:    309.7K
 * Total Submissions: 696.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        stack<ListNode*> nodes_1;
        stack<ListNode*> nodes_2;
        ListNode* result;
        int num_1 = 0;
        int num_2 = 0;
        if(head == NULL)
            return NULL;
        while(head!=NULL){
            nodes_1.push(head);
            num_1++;
            head = head->next;
            if(head==NULL)
                break;
            nodes_2.push(head);
            num_2++;
            head = head->next;
        }
        if(num_1 != num_2){
            if(num_1 > num_2){ // nodes_1里的节点多，需要先链接上，作为最后一个
                result = nodes_1.top();
                nodes_1.pop();
            }
            else{
                result = nodes_2.top();
                nodes_2.pop();
            }
            
        }
        while(nodes_1.size() != 0){
            nodes_1.top()->next = result;
            result = nodes_1.top();
            nodes_1.pop();

            nodes_2.top()->next = result;
            result = nodes_2.top();
            nodes_2.pop();
        }
        return result;
        
    }
};


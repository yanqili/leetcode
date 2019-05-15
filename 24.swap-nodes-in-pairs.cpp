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
        ListNode* node_1;
        ListNode* node_2;
        ListNode* result;
        ListNode* last = NULL;
        if(head == NULL){
            return NULL;
        }
        node_1 = head;
        node_2 = head->next;
        if(node_2 != NULL)
            result = node_2;
        else
            result = node_1;
        while(node_2 != NULL){
            node_1->next = node_2->next;
            node_2->next = node_1;
            if(last != NULL)
                last->next = node_2;
            last = node_1;
            node_1 = node_1->next;
            if(node_1==NULL)
                break;
            node_2 = node_1->next;
            
        }
        return result;
    
    }
};


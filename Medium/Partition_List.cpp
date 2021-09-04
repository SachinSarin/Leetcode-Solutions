/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* final = new ListNode(0);
        ListNode* ptr = final;
        unordered_set<int> s;
        ListNode* current = head;
        while(current!=NULL)
        {
            if(current->val < x)
            {
                ptr->next = new ListNode(current->val);
                s.insert(current->val);
                ptr = ptr->next;            
            }
            
            current = current->next;
            
        }
        
        //for remaining nodes
        ListNode* cur = head;
        while(cur!=NULL)
        {
            if(s.find(cur->val)==s.end())
            {
                ptr->next = new ListNode(cur->val);
                ptr = ptr->next;
            }
            cur = cur->next;
        }
        return final->next;
    }
};

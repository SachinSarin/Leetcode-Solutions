/*
Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
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
    ListNode* sortList(ListNode* head) {
        
        map<int,int> s;
        ListNode*current = head;
        while(current!=NULL)
        {
            
            s[current->val]++;
            current = current->next;
        }
        
        ListNode* final = new ListNode(0);
        ListNode* ptr = final;
        for(auto x: s)
        {
            while(x.second !=0)
            {
                 ptr->next = new ListNode(x.first);
                 ptr = ptr->next;
                 x.second--;

            }
           
        }
        return final->next;
    }       
};

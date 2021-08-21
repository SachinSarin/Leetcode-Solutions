/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
Accepted
650,422
Submissions
1,374,605
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        set<int> s;
        
        ListNode* current = head;
        while(current!=NULL)
        {
            s.insert(current->val);
            current = current -> next;
        }
        
        ListNode* first = new ListNode(0);
        ListNode* ptr = first;
        
        
        //run for each loop
        for(auto x : s)
        {
            ptr->next = new ListNode(x);
            ptr = ptr->next;
        }
        
        return first->next;
    }
    
};

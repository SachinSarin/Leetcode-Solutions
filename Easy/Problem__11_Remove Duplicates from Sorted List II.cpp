/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
        
        map<int,int> s;
        
        ListNode* current = head;
        
        while(current!=NULL)
        {
            s[current->val]++;
            current = current -> next;
        }
        
        //use of for each loop
        ListNode* final = new ListNode(0);
        ListNode* ptr = final;
        for(auto x :s)
        {
            if(x.second ==1)
            {
                 ptr->next = new ListNode(x.first);
                ptr = ptr->next;
            }
           
        }
        return final->next;
    }
};

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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        ListNode* a = head1;
        ListNode* b = head2;
        ListNode* tail = NULL;
        ListNode* curr = NULL;
        if(a == NULL)
        {
            return b;
        }
        if(b==NULL)
        {
            return a;
        }
        
        if(a->val <= b->val)
        
        {
            curr = tail = head1;
            a = a->next;
        
            
        }
        else
        {
            tail = head2;
            b = b->next;
            curr = tail;
        }
        
        //merging logic
        while(a!=NULL && b!=NULL)
        {
           if(a->val <= b->val)
           {
               tail->next = a;
               tail = a;
               a = a->next;
              
           }
            else
            {
                tail->next = b;
              
                tail = b;
                 b = b->next;
            }
        }
        
        //remaining nodes
        if(a==NULL)
        {
            tail->next = b;
        }
        else
        {
            tail->next = a;
        }
        return curr;
    }
        
};

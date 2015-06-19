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
ListNode* removeNthFromEnd(ListNode* head, int n) {
            assert(head);
            ListNode * p = head;
            ListNode * prev = head;
            // Find the starting point for prev(Head)->...(n-1)..->p;
            int m = 0;
            while(m < n && p != nullptr) // run once
            {
                p = p->next, m++;
            }
            assert(m == n);
            // Find the location
            while( p!= NULL && p->next != NULL)
            {
                 prev = prev->next;
                 p = p->next;
            }

            // Scenario To remove head
            if( p == nullptr)
            {
                head = head->next;
                delete prev;
                return head;
            }
            else{

                ListNode * tmp = prev->next;
                prev->next = tmp->next;
                delete tmp;
            }

            return head;
}
   };

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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow=head,*fast=head->next;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }       
        ListNode *prev = nullptr, *curr = slow->next;
        slow->next = nullptr;
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr=temp;
        } 
        ListNode* head2 = prev,*head1=head;
        while(head2)
        {
            ListNode *temp1=head1->next, *temp2=head2->next;
            head1->next=head2;
            head2->next=temp1;
            head1=temp1;
            head2=temp2;
        } 
    }
};

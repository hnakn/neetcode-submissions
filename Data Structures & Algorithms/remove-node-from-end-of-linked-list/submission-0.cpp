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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode *temp=head;
        while(temp)
        {
            size++;
            temp=temp->next;
        }
        int count = size-n+1;
        size=0;
        temp=head;
        ListNode *prev = nullptr;
        while(temp)
        {
            size++;
            if(size==count)
            {
                if(!prev) head=head->next;
                else
                {
                    prev->next = temp->next;
                } 
                break;
            } 
            prev=temp;
            temp=temp->next;
        }
        return head;        
    }
};

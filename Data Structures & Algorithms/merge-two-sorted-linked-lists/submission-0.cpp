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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* curr = head;
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<=list2->val)
            {
                if(head==nullptr) 
                {
                    head=list1;
                    curr=head;
                }
                else 
                {
                    curr->next = list1;
                    curr=curr->next;
                }
                list1=list1->next;
            }
            else 
            {
                if(head==nullptr) 
                {
                    head=list2;
                    curr=head;
                }
                else 
                {
                    curr->next = list2;
                    curr=curr->next;
                }
                list2=list2->next;
            }
        } 
        if(list1!=nullptr)
        {
            curr->next=list1;
        }
        if(list2!=nullptr)
        {
            curr->next=list2;
        }
        return head;       
    }
};

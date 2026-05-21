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
    struct cmp
    {
        bool operator() (ListNode *a, ListNode *b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        ListNode *temp = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq; 
        if(lists.empty()) return nullptr;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]) pq.push(lists[i]);
        }

        while(!pq.empty())
        {
            ListNode *x = pq.top();
            pq.pop();
            if(head) 
            {
                temp->next = x;
                temp=temp->next;
            }
            else
            {
                head = x;
                temp = head;
            }
            if(x->next) pq.push(x->next);
        }

        return head;
        
    }
};

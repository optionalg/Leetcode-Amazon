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
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(0), *cur = dummy, *top;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i = 0; i < lists.size(); ++i)
            if(lists[i])
                pq.push(lists[i]);
        while(!pq.empty()){
            top = pq.top(), pq.pop();
            cur->next = top;
            cur = cur->next;
            if(top->next)
                pq.push(top->next);
        }
        return dummy->next;
    }
};

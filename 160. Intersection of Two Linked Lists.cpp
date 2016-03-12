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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        int m = 0, n = 0, k;
        while(p) m++, p = p->next;
        while(q) n++, q = q->next;
        k = m < n ? n - m : m - n;
        p = m < n ? headA : headB;
        q = m < n ? headB : headA;
        while(k > 0) k--, q = q->next;
        while(p && q){
            if(p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};

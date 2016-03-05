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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        int val_1, val_2;
        while(l1 || l2){
            val_1 = l1 ? l1->val : INT_MAX;
            val_2 = l2 ? l2->val : INT_MAX;
            if(val_1 < val_2){
                cur->next = l1;
                l1 = l1 ? l1->next : NULL;
            }else{
                cur->next = l2;
                l2 = l2 ? l2->next : NULL;
            }
            cur = cur->next;
        }
        return dummy->next;
        
    }
};

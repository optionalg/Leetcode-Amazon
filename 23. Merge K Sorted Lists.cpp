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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int left = 0, right = lists.size() - 1;
        while(right > 0){
            left = 0;
            while(left < right) lists[left] = mergeTwoLists(lists[left++], lists[right--]);
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode* dummy = new ListNode(0), *cur = dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != NULL ? l1 :l2;
        return dummy->next;
    }
};

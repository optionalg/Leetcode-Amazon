struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head){
	ListNode *pre = NULL, *cur = head, *next = NULL;
	while(cur){
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
ListNode *reverse2ndHalfOfLinkedList(ListNode *head){
	ListNode *fast = head, *slow = head, *pre = NULL;
	while(fast && fast->next){
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(!fast) pre->next = reverse(slow);
	else slow->next = reverse(slow->next);
	return head;
}

ListNode* Solution::deleteDuplicates(ListNode* A) {
	ListNode *t1Head = new ListNode(0);
	ListNode *t1 = t1Head;
	t1->next = A;
	ListNode *head = A;
	while (head) {
		if (head->next && head->val == head->next->val) {
			while (head->next && head->val == head->next->val) {
				head = head->next;
			}
			t1->next = head->next;
		} else {
			t1 = t1->next;
		}

		head = head->next;
	}

	return t1Head->next;


}





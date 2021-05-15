ListNode* Solution::insertionSortList(ListNode* A) {

	ListNode *helper = new ListNode(0);
	ListNode *pre = helper, *curr = A, *next = NULL;

	while (curr) {
		next = curr->next;

		if (pre->next && pre->next->val > curr->val)
			pre = helper;

		while (pre->next && pre->next->val < curr->val)
			pre = pre->next;

		curr->next = pre->next;
		pre->next = curr;
		curr = next;
	}

	return helper->next;
}

//or

ListNode* Solution::insertionSortList(ListNode* A) {
	if (!A || !(A->next))
		return A;

	ListNode *curr = A, *tHead = A, *prev = NULL, *next = NULL;
	int sz = 1;
	while (curr->next) {
		sz++;
		prev = curr;
		curr = curr->next;
		next = curr->next;

		ListNode *temp = tHead;
		int pos = sz - 1, cnt = 0;
		while (pos--) {
			if (temp->val > curr->val)
				cnt++;

			temp = temp->next;
		}

		pos = sz - cnt - 2;
		temp = tHead;

		if (pos == -1) {
			prev->next = curr->next;
			curr->next = tHead;
			tHead = curr;
		}
		else {

			while (pos--) {
				temp = temp->next;
			}

			prev->next = curr->next;
			curr->next = temp->next;
			temp->next = curr;

		}

		pos = sz - 1;
		temp = tHead;
		while (pos--) {
			temp = temp->next;
		}

		curr = temp;

	}

	return tHead;
}

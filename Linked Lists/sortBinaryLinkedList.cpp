ListNode* Solution::solve(ListNode* A) {

	int cnt1 = 0;
	int sz = 0;

	ListNode *t1 = A;

	while (t1 != NULL) {
		if (t1->val)
			cnt1++;
		t1 = t1->next;
		sz++;
	}
	int cnt0 = sz - cnt1;
	t1 = A;

	while (t1 != NULL && cnt0--) {
		t1->val = 0;
		t1 = t1->next;
	}

	while (t1 != NULL && cnt1--) {
		t1->val = 1;
		t1 = t1->next;
	}

	return A;
}

// or


ListNode* Solution::solve(ListNode* A) {
	if (A == NULL)return A;
	ListNode *t1 = A, *t2 = A->next;
	while (t2) {
		if (t1->val == 1 && t2->val == 0) {
			t1->val = 0;
			t2->val = 1;
			t1 = t1->next;
			t2 = t2->next;
		} else if (t1->val == 1 && t2->val == 1) {
			t2 = t2->next;
		} else {
			t1 = t1->next;
			t2 = t2->next;
		}
	}
	return A;
}
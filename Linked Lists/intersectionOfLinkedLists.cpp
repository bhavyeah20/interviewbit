ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {

	ListNode *t1 = A, *t2 = B;
	int sz1 = 0, sz2 = 0;
	while (t1 != NULL) {
		t1 = t1->next;
		sz1++;
	}

	while (t2 != NULL) {
		t2 = t2->next;
		sz2++;
	}

	t1 = A, t2 = B;


	int diff = 0;
	if (sz1 > sz2) {
		diff = sz1 - sz2;
		while (diff--) {
			t1 = t1->next;
		}
	} else {
		diff = sz2 - sz1;
		while (diff--) {
			t2 = t2->next;
		}

	}


	while (t1 != NULL && t2 != NULL) {
		if (t1 == t2)
			return t1;

		t1 = t1->next;
		t2 = t2->next;
	}

	return NULL;

}

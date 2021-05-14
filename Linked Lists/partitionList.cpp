ListNode* Solution::partition(ListNode* A, int B) {
	ListNode *t1 = NULL, *t2 = NULL;
	ListNode *temp = A;
	ListNode *t1Head = t1, *t2Head = t2;
	ListNode *next;

	while (temp) {
		next = temp->next;
		if (temp->val < B) {
			if (t1 == NULL) {
				t1 = temp;
				t1Head = t1;
			} else {
				t1->next = temp;
				t1 = t1->next;
			}
		} else {
			if (t2 == NULL) {
				t2 = temp;
				t2Head = t2;
			} else {
				t2->next = temp;
				t2 = t2->next;
			}
		}

		temp = next;
	}


	if (t2Head == NULL) {
		t1->next = NULL;
		return t1Head;
	}

	if (t1Head == NULL) {
		t2->next = NULL;
		return t2Head;
	}

	t1->next = t2Head;
	t2->next = NULL;
	return t1Head;
}
ListNode *rev(ListNode *t) {
	ListNode *curr = t, *prev = NULL, *next = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

ListNode* Solution::solve(ListNode* A) {
	ListNode *odd = new ListNode(0), *even = new ListNode(0), *curr = A, *next = NULL;
	ListNode *oHead = odd, *eHead = even;
	int cnt = 1;
	while (curr) {
		next = curr->next;

		if (cnt) {
			odd->next = curr;
			odd = odd->next;
		}
		else {
			even->next = curr;
			even = even->next;
		}

		curr = next;
		cnt = (cnt + 1) % 2;
	}
	eHead = eHead->next;
	oHead = oHead->next;
	odd->next = NULL;
	even->next = NULL;

	eHead = rev(eHead);

	ListNode *ans = new ListNode(0);
	even = eHead, odd = oHead;
	cnt = 1;
	ListNode *oNext = NULL, *eNext = NULL;
	ListNode *ansHead = ans;
	while (even || odd) {
		if (cnt) {
			oNext = odd->next;
			ans->next = odd;
			odd = oNext;
		}
		else {
			eNext = even->next;
			ans->next = even;
			even = eNext;
		}

		ans = ans->next;
		cnt = (cnt + 1) % 2;
	}

	return ansHead->next;
}

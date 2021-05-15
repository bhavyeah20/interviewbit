/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

	int sz1 = 0, sz2 = 0;
	ListNode *t = A;
	while (t) {
		t = t->next;
		sz1++;
	}

	t = B;
	while (t) {
		t = t->next;
		sz2++;
	}

	if (sz1 > sz2)
		return Solution::addTwoNumbers(B, A);

	int carry = 0;
	ListNode *aHead = A, *bHead = B;
	while (aHead && bHead->next) {
		bHead->val = aHead->val + bHead->val + carry;
		carry = (bHead->val) / 10;
		bHead->val %= 10;

		aHead = aHead->next;
		bHead = bHead->next;

	}

	if (aHead) {
		bHead->val = aHead->val + bHead->val + carry - 1;
		carry = 1;
	}

	while (bHead && carry) {
		bHead->val += carry;
		carry = (bHead->val) / 10;
		bHead->val %= 10;
		if (carry && bHead->next == NULL) {
			ListNode *temp = new ListNode(0);
			bHead->next = temp;
		}
		bHead = bHead->next;
	}


	ListNode *rev = B, *curr = B, *prev = NULL, *next = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	while (prev && prev->val == 0) {
		prev = prev->next;
	}

	if (prev == NULL) {
		ListNode *ans = new ListNode(0);
		return ans;
	}

	B = prev;
	curr = B, prev = NULL, next = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}



	return prev;



}



//or


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;
	int sum = 0;
	int carry = 0;
	ListNode* l3 = new ListNode(-1);
	ListNode* head = l3;
	while (l1 || l2 || carry) {
		sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
		carry = sum / 10;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
		l3->next = new ListNode(sum % 10);
		l3 = l3->next;
	}
	return head->next;
}

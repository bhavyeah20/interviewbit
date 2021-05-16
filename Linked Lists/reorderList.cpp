/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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


ListNode* Solution::reorderList(ListNode* A) {
	ListNode *t1 = new ListNode(0), *t2 = new ListNode(0);
	ListNode *t1Head = t1, *t2Head = t2;


	int sz = 0;
	ListNode *temp = A;
	while (temp) {
		temp = temp->next;
		sz++;
	}

	temp = A;
	int inits = (sz + 1) / 2;

	while (inits-- && temp) {
		t1->next = temp;
		t1 = t1->next;
		temp = temp->next;
	}

	while (temp) {
		t2->next = temp;
		t2 = t2->next;
		temp = temp->next;
	}

	t1->next = NULL;
	t2->next = NULL;

	t1Head = t1Head->next;
	t2Head = t2Head->next;

	t2Head = rev(t2Head);

	ListNode *ans = new ListNode(0), *ansHead = ans;
	t1 = t1Head, t2 = t2Head;
	int cnt = 1;
	while (t1 || t2) {
		if (cnt) {
			ans->next = t1;
			t1 = t1->next;
		}
		else {
			ans->next = t2;
			t2 = t2->next;
		}

		ans = ans->next;
		cnt = (cnt + 1) % 2;
	}

	return ansHead->next;

}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
	int sz = 0;
	ListNode *t = A;
	while (t) {
		t = t->next;
		sz++;
	}

	int pos = sz / 2 + 1;
	if (B < 1 || B > sz / 2)
		return -1;

	pos = pos - B - 1;

	t = A;
	while (pos--) {
		t = t->next;
	}

	return t->val;
}

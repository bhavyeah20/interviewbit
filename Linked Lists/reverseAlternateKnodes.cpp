/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, int B) {
	ListNode *t = A;
	ListNode *prev = NULL, *curr = t, *next;
	int b = B;
	if (B == 1)
		return t;
	while (b-- && curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	A->next = next;
	t = next;
	b = B - 1;
	while (b-- && t) {
		t = t->next;
	}

	if (t && t->next) {
		t->next = Solution::solve(t->next, B);
	}

	return prev;
}
